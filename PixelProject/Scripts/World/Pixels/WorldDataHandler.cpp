#include "WorldDataHandler.h"

#include "Utility/Console.h"

WorldDataHandler& WorldDataHandler::GetInstance()
{
   static WorldDataHandler instance;
   return instance;
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
      for (auto& colour : pixel.type_colours)
      {
         if (_pixel_colour_map.contains(colour))
            DEBUG_WARNING_LOG("[WorldDataHandler] Duplicate pixel colour {} found for pixel type {}.", colour, pixel.pixel_type);
         _pixel_colour_map[colour] = pixel;
      }
      _pixel_type_map[pixel.pixel_type] = pixel;
   }
}

Uint32 WorldDataHandler::GetPixelColour(const Pixels::PixelType& pixel_type) const
{
   return _pixel_type_map.at(pixel_type).GetRandomColour();
}

const uint8_t& WorldDataHandler::GetRandomPixelUpdateOrder(Pixels::PixelType pixel_type) const
{
   return _pixel_type_map.at(pixel_type).GetPixelUpdateOrder();
}