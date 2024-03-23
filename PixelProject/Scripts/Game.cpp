#include "Game.h"

#include <GL/glew.h>
#include <chrono>

#include "Config/ConfigFile.h"

#include "Rendering/Shaders/ShaderManager.h"

#include "World/Pixels/WorldDataHandler.h"
#include "UI/Paint/PaintSelector.h"

Game::Game(SDL_GLContext* gl_context, SDL_Window* gl_window, std::shared_ptr<GameSettings>& settings):
   _input_manager(nullptr), _camera(nullptr)
{
   _context = gl_context;
   _window = gl_window;
   _settings = settings;

   _ui_manager = UIManager::GetInstance();

   auto instance = WorldDataHandler::GetInstance();

   _fixed_step_step_time = _settings->target_sand_update_time;
   _fixed_step_max_steps = _settings->max_sand_updates_per_frame;
}

bool Game::Initialize()
{
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

   glViewport(0, 0, 1280, 720);

   // Un-sync FPS from monitor
   SDL_GL_SetSwapInterval(0);

   // Shaders
   const auto shaderManager = ShaderManager::GetInstance();
   Shader* defaultShader = shaderManager->CreateShaderProgramFromFiles(
      GetShaderMask(ShaderMask::MVertex, ShaderMask::MFragment), "orthoWorld", "shaders/orthoWorld");
   shaderManager->SetDefaultShader(defaultShader);

   glUniform1i(defaultShader->GetUniformLocation("ourTexture"), 0);
   glUniform1i(defaultShader->GetUniformLocation("noiseTextureIndex"), 1);
   
   // Input System
   _input_manager = InputManager::GetInstance();
   
   // User Interface
   _ui_manager->Init(_window, _context);

   _paint_selector = PaintSelector::GetInstance();
   _paint_selector->GenerateTextures(_settings.get());

   _camera = new FlyCamera();
   _camera->SetOrthographic(0.0f, 1280.0f, 720.0f, 0.0f, -1.0f, 1.0f);

   _world_simulator = new WorldSimulator(defaultShader, _settings);
   WorldDataHandler::GetInstance()->SetUniformData(defaultShader);

   return true;
}

void Game::Run()
{
   typedef std::chrono::steady_clock clock;
   typedef std::chrono::duration<float, std::milli> duration;

   auto deltaClock = clock::now();
   _is_running = true;

   _input_manager->AddKeyListener(KeyCode::U, "Temp_FixedUpdate", [this](SDL_Event& event, bool state)
   {
      if (state)
      {
         _world_simulator->FixedUpdate();
      }
   });
   
   // TODO : (James) While GameStateManager != IsShuttingDown??
   _minimum_delta_time = 1000.0f / _settings->target_frames_per_second;
   while (_is_running)
   {
      _delta_time += duration(clock::now() - deltaClock).count();
      deltaClock = clock::now();
      
      _fixed_time += _delta_time;
      FixedUpdate();
      
      InputUpdate();

      // Runs once a frame
      Update();
      _camera->Update(_delta_time);

      // Draw
      Render();
      _paint_selector->Draw();

      // UI
      RenderUI();

      SDL_GL_SwapWindow(_window);
      _delta_time = 0.0;
   }
}

void Game::FixedUpdate()
{
   uint8_t fixedUpdateCount = 0;
   while (_fixed_time >= _fixed_step_step_time)
   {
      _fixed_time -= _fixed_step_step_time;

      // Main Update Logic
      _world_simulator->FixedUpdate();

      // Protective logic to prevent falling into an infinite loop
      fixedUpdateCount++;
      if (fixedUpdateCount >= _fixed_step_max_steps)
      {
         LOG_WARNING("[Game] FixedUpdate() Falling behind, {} updates this frame ({}ms), remaining {}ms", fixedUpdateCount, std::round(_fixed_step_step_time * fixedUpdateCount * 100) / 100.0f, std::round(_fixed_time * 100) / 100.0f);
         break;
      }
   }
}

void Game::Update()
{
}

void Game::InputUpdate()
{
   _input_manager->Update();
   if (_input_manager->GetKeyState(KeyCode::Escape))
      _is_running = false;
}

void Game::Render()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   _world_simulator->Draw(_camera);
}

void Game::RenderUI()
{
   _ui_manager->BeginFrame();

   _ui_manager->DrawGUI();

   _ui_manager->EndFrame();
}
