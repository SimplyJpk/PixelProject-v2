#include "FlyCamera.h"
#include "Utility/Console.h"

FlyCamera::FlyCamera()
{
   auto input = InputManager::GetInstance();

   auto handleKeyFunction = std::bind(&FlyCamera::HandleKeyMovement, this, std::placeholders::_1, std::placeholders::_2);
   for (auto keyMovement : KEY_MOVEMENT)
   {
      input->AddKeyListener(keyMovement.GetKeyAsKeyCode(), std::to_string(keyMovement.GetHash()), handleKeyFunction);
      _key_pressed[keyMovement.GetKeyAsKeyCode()] = false;
   }

   auto shiftKeyFunc = std::bind(&FlyCamera::HandleKeyShift, this, std::placeholders::_1, std::placeholders::_2);
   for (auto shiftKey: SHIFT_KEYS)
   {
      input->AddKeyListener(shiftKey, SHIFT_KEY_INPUT_KEY, shiftKeyFunc);
      _key_pressed[shiftKey] = false;
   }
}

FlyCamera::~FlyCamera()
{
   auto input = InputManager::GetInstance();

   for (auto keyMovement : KEY_MOVEMENT)
   {
      input->RemoveKeyListener(keyMovement.GetKeyAsKeyCode(), std::to_string(keyMovement.GetHash()));
   }
   for (auto shiftKey : SHIFT_KEYS)
   {
      input->RemoveKeyListener(shiftKey, SHIFT_KEY_INPUT_KEY);
   }
}

void FlyCamera::Update(float deltaTime)
{
   Camera::Update(deltaTime);

   glm::vec2 dir = glm::vec2();
   for (auto keyMovement : KEY_MOVEMENT)
   {
      if (_key_pressed[keyMovement.GetKeyAsKeyCode()])
      {
         dir += keyMovement.data;
      }
   }
   // Get length of direction vector
   if (const float length = glm::length(dir); length > 0)
   {
      dir = glm::normalize(dir);
      const glm::vec3 movement = glm::vec3(dir.x, 0, dir.y);
      
      const auto shiftMult = _shift_held ? _shift_multiplier : 1.0f;
      _position += movement * _default_speed * shiftMult * deltaTime;

      SetPosition(_position);
   }

   Console::PrintInfo("Camera position: " + std::to_string(_position.x) + ", " + std::to_string(_position.y) + ", " + std::to_string(_position.z));
}

void FlyCamera::HandleKeyMovement(SDL_Event& event, const bool is_pressed)
{
   _key_pressed[static_cast<KeyCode>(event.key.keysym.scancode)] = is_pressed;
   Console::PrintInfo("Key pressed: " + std::to_string(event.key.keysym.sym) + " Pressed:" + std::to_string(is_pressed));
}

void FlyCamera::HandleKeyShift(SDL_Event& event, const bool is_pressed)
{
   _shift_held = is_pressed;
   Console::PrintInfo("Shift pressed: " + std::to_string(is_pressed) + " Pressed: " + std::to_string(is_pressed));
}
