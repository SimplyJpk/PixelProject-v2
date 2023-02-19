#pragma once

#include "World/Pixels/Base/BasePixel.h"

using namespace Chunk;

class SandPixel final : public BasePixel
{
public:
   constexpr SandPixel()
   {
      pixel_type = Pixels::PixelType::Sand;
      SetPixelName("Sand");
      is_updateable = true;

      colour_count = 3;
      // Yellows
      type_colours[0] = 0xE2D9AEFF;
      type_colours[1] = 0xE8BB9AFF;
      type_colours[2] = 0xEDC9AFFF;

      _pixel_update_order_count = 1;
      InsertPixelUpdateOrder(
         {
            {  WorldDir::South, WorldDir::SouthEast, WorldDir::South},
            {  WorldDir::South, WorldDir::SouthWest, WorldDir::South}
         });

      rng = XoshiroCpp::Xoshiro128Plus(static_cast<int>(pixel_type));
   }
   
};
