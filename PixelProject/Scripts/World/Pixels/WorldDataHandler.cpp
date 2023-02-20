#include "WorldDataHandler.h"

#include "Utility/Console.h"

WorldDataHandler* WorldDataHandler::GetInstance()
{
   static WorldDataHandler instance;
   return &instance;
}

WorldDataHandler::WorldDataHandler()
{
   _pixel_types = {
      SpacePixel(),
      DirtPixel(),
      SandPixel()
   };

   for (auto& pixel : _pixel_types)
   {
      for (auto i = 0; i < pixel.colour_count; ++i)
      {
         if (_pixel_colour_map.contains(pixel.type_colours[i]))
            DEBUG_WARNING_LOG("[WorldDataHandler] Duplicate pixel colour {} found for pixel type {}.", pixel.type_colours[i], pixel.pixel_type);
         _pixel_colour_map[pixel.type_colours[i]] = &pixel;
      }
      _pixel_type_map[pixel.pixel_type] = &pixel;
   }
}

Uint32 WorldDataHandler::GetPixelColour(const Pixels::PixelType& pixel_type) const
{
   return _pixel_type_map.at(pixel_type)->GetRandomColour();
}

const uint8_t& WorldDataHandler::GetRandomPixelUpdateOrder(Pixels::PixelType pixel_type) const
{
   return _pixel_type_map.at(pixel_type)->GetPixelUpdateOrder();
}