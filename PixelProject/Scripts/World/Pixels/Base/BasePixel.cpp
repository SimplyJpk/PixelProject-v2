#include "BasePixel.h"

const uint8_t& BasePixel::GetPixelUpdateOrder()
{
   if (_pixel_update_order_count != 1)
   {
      _chunk_order_counter++;
      if (_chunk_order_counter >= _pixel_update_order_count)
      {
         _chunk_order_counter = 0;
      }
   }
   return *_pixel_update_order[_chunk_order_counter];
}

void BasePixel::InsertPixelUpdateOrder(const uint8_t index, const std::vector<Chunk::WorldDir>& directions)
{
   if (index < Pixels::PIXEL_MAX_UPDATE_ORDER_COUNT)
   {
      for (uint8_t i = 0; i < Chunk::NUM_DIRECTIONS; i++)
      {
         if (i < directions.size())
            _pixel_update_order[index][i] = static_cast<uint8_t>(directions[i]);
         else
            _pixel_update_order[index][i] = Chunk::NUM_DIRECTIONS;
      }
   }
}

void BasePixel::InsertPixelUpdateOrder(const std::vector<std::vector<Chunk::WorldDir>>& directions)
{
   for (auto i = 0; i < directions.size(); i++)
   {
      InsertPixelUpdateOrder(static_cast<uint8_t>(i), directions[i]);
   }
}

void BasePixel::SetPixelName(const char* const name)
{
   if (strlen(name) > 0)
   {
      strcpy_s(pixel_name, Pixels::PIXEL_MAX_UPDATE_ORDER_COUNT, name);
   }
}

Uint32 BasePixel::GetRandomColour()
{
   return type_colours[rng() % colour_count];
}