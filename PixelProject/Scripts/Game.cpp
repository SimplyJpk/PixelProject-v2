#include "Game.h"

#include <GL/glew.h>
#include <chrono>

#include "Config/ConfigFile.h"

Game::Game(SDL_GLContext* gl_context, SDL_Window* gl_window)
{
    _context = gl_context;
    _window = gl_window;

    _ui_manager = UIManager::GetInstance();
}

bool Game::Initialize()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glViewport(0, 0, 1280, 720);
    
    _ui_manager->Init( _window, _context );
    
    return true;
}

void Game::Run()
{
    typedef std::chrono::steady_clock clock;
    typedef std::chrono::duration<float, std::milli> duration;

    auto deltaClock = clock::now();

    // TODO : (James) While GameStateManager != IsShuttingDown??
    while (true)
    {
        deltaTime = duration(clock::now() - deltaClock).count();
        deltaClock = clock::now();

        fixedTime += deltaTime;
        // TODO : (James) while fixedTime > X then do fixed update
        FixedUpdate();

        InputUpdate();
        
        // Runs once a frame
        Update();

        // Draw
        Render();

        // UI
        RenderUI();
        
        SDL_GL_SwapWindow(_window);
    }
}

void Game::FixedUpdate()
{

    // TODO : (James) while fixedTime > X then do fixed update
}

void Game::Update()
{
    
}

void Game::InputUpdate()
{
    // TODO : (James) Input Manager
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            return;
        }
    }
}

void Game::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Game::RenderUI()
{
    _ui_manager->BeginFrame();

    _ui_manager->DrawGUI();

    _ui_manager->EndFrame();
}


