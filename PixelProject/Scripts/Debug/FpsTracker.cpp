#include "FpsTracker.h"

void FpsTracker::Update(const float delta_time)
{
    _current_fps = 1.0f / delta_time;
    
    _max_fps = std::numeric_limits<float>::min();
    _min_fps = std::numeric_limits<float>::max();
  
    if (_fps_history.size() >= MAX_FPS_HISTORY)
        _fps_history.erase(_fps_history.begin());
    
    _fps_history.push_back(_current_fps);
}

float FpsTracker::GetMaxFps()
{
    if (_max_fps == std::numeric_limits<float>::min())
    {
        for (const float fps : _fps_history)
        {
            if (fps > _max_fps)
                _max_fps = fps;
        }
    }
    return _max_fps;
}

float FpsTracker::GetMinFPS()
{
    if (_min_fps == std::numeric_limits<float>::max())
    {
        for (const float fps : _fps_history)
        {
            if (fps < _min_fps)
                _min_fps = fps;
        }
    }
    return _min_fps;
}
