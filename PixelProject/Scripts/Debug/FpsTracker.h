#pragma once
#include <limits>
#include <vector>

class FpsTracker
{
public:
   void Update(const float delta_time);

   float GetCurrentFps() const { return _current_fps; }
   float GetMaxFps();
   float GetMinFPS();

   float GetApproxHistoryDuration() const { return MAX_FPS_HISTORY / _current_fps; }

   const std::vector<float>* GetFpsHistory() const { return &_fps_history; }
   const float* GetFpsHistoryData() const { return _fps_history.data(); }

   static constexpr int MAX_FPS_HISTORY = 500;
   
private:
   float _current_fps = 0;

   float _max_fps = std::numeric_limits<float>::min();
   float _min_fps = std::numeric_limits<float>::max();

   int _last_check_time = 0;

   std::vector<float> _fps_history = std::vector<float>(MAX_FPS_HISTORY, 0);
};
