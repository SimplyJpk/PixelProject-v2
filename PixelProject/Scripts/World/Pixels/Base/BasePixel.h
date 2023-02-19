#pragma once

#include <SDL_stdinc.h>
#include <vector>

#include "XoshiroCpp.hpp"

#include "World/WorldConstants.h"

class BasePixel
{
public:
   Pixels::PixelType pixel_type;
   char pixel_name[Pixels::PIXEL_MAX_NAME_LENGTH];
   
   bool is_updateable;
   // TODO : (James) Need to apply pixel value to all PixelTypes
   Uint32 new_pixel_value;

   // TODO : (James) Check if worse by making static
   XoshiroCpp::Xoshiro128Plus rng;

   // Pixel Settings
   uint8_t pixel_index;
   uint8_t colour_count;

   Uint32 type_colours[Pixels::PIXEL_MAX_COLOUR_COUNT];

   const uint8_t& GetPixelUpdateOrder();
   Uint32 GetRandomColour();

protected:
   uint8_t _chunk_order_counter;
   uint8_t _pixel_update_order_count;
   uint8_t _pixel_update_order[Pixels::PIXEL_MAX_UPDATE_ORDER_COUNT][Chunk::NUM_DIRECTIONS];

   void InsertPixelUpdateOrder(const uint8_t index, const std::vector<Chunk::WorldDir>& directions);
   void InsertPixelUpdateOrder(const std::vector<std::vector<Chunk::WorldDir>>& directions);
   void SetPixelName(const char* const name);
   
};