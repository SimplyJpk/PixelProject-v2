#pragma once

#include <SDL.h>

class UIManager
{
public:
   static UIManager* GetInstance()
   {
      static UIManager instance;
      return &instance;
   }

   void Init(SDL_Window* window, SDL_GLContext glContext);

   void DrawGUI();

   void BeginFrame() const;
   void EndFrame();

protected:
   SDL_Window* _window;

private:
   UIManager() = default;
   ~UIManager();
};
