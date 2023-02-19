#pragma once

#include "World/Pixels/Base/BasePixel.h"

class DirtPixel final : public BasePixel
{
public:
   constexpr DirtPixel()
   {
      pixel_type = Pixels::PixelType::Dirt;
      SetPixelName("Dirt");
      is_updateable = false;

      colour_count = 3;
      // Browns
      type_colours[0] = 0x964b00FF;
      type_colours[1] = 0x967100FF;
      type_colours[2] = 0x962600FF;

      _pixel_update_order_count = 0;

      rng = XoshiroCpp::Xoshiro128Plus(static_cast<int>(pixel_type));
   }
};


2 : 2