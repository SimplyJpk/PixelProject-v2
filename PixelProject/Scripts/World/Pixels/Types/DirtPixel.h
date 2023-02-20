#pragma once

#include "World/Pixels/Base/BasePixel.h"

class DirtPixel final : public BasePixel
{
public:
   DirtPixel()
   {
      pixel_type = Pixels::PixelType::Dirt;
      SET_PIXEL_NAME("Dirt");
      is_updateable = false;

      colour_count = 3;
      // Browns
      type_colours[0] = 0x964b00FF;
      type_colours[1] = 0x967100FF;
      type_colours[2] = 0x962600FF;

      _pixel_update_order_count = 0;

      distribution = std::uniform_int_distribution<int>(0, colour_count);
   }
};
