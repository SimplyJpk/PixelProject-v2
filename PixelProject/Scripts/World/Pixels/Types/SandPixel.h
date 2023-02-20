#pragma once

#include "World/Pixels/Base/BasePixel.h"

using namespace Chunk;

class SandPixel final : public BasePixel
{
public:
   SandPixel()
   {
      pixel_type = Pixels::PixelType::Sand;
      SET_PIXEL_NAME("Sand");
      is_updateable = true;

      colour_count = 3;
      // Yellows
      type_colours[0] = 0xE2D9AEFF;
      type_colours[1] = 0xE8BB9AFF;
      type_colours[2] = 0xEDC9AFFF;

      _pixel_update_order_count = 2;
      SET_PIXEL_UPDATE_ORDER(0, WorldDir::South, WorldDir::SouthEast, WorldDir::SouthWest);
      SET_PIXEL_UPDATE_ORDER(1, WorldDir::South, WorldDir::SouthWest, WorldDir::SouthEast);
      
      // InsertPixelUpdateOrder(
      //    {
      //       {  WorldDir::South, WorldDir::SouthEast, WorldDir::South},
      //       {  WorldDir::South, WorldDir::SouthWest, WorldDir::South}
      //    });

      distribution = std::uniform_int_distribution<int>(0, colour_count);
   }
   
};
