#pragma once

#include <SDL.h>

#include "UI/UIManager.h"
#include "Input/InputManager.h"

using namespace PixelProject::Input;

class Game
{
public:
   ~Game() = default;

   Game(SDL_GLContext* gl_context, SDL_Window* gl_window);
   bool Initialize();

   /// @brief Runs the game loop, this won't return until the application is closed
   void Run();

protected:
   void InputUpdate();

   void FixedUpdate();
   void Update();

   void Render();
   void RenderUI();

protected:
   SDL_GLContext* _context;
   SDL_Window* _window;

   UIManager* _ui_manager;
   InputManager* _input_manager;

   double deltaTime = 0.0;
   double fixedTime = 0.0;

private:
   Game() = default;
   bool _is_running = true;
};
