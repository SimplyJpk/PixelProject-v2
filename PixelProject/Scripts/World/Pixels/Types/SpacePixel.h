#pragma once

#include "World/Pixels/Base/BasePixel.h"

class SpacePixel final : public BasePixel
{
public:
   constexpr SpacePixel()
   {
      pixel_type = Pixels::PixelType::Space;
      SetPixelName("Space");
      is_updateable = false;

      colour_count = 1;
      // Space
      type_colours[0] = 0x00000000;

      _pixel_update_order_count = 0;

      rng = XoshiroCpp::Xoshiro128Plus(static_cast<int>(pixel_type));
   }
   
};
