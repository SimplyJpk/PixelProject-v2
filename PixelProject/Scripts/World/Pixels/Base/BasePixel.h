#pragma once

#include <SDL_stdinc.h>

#include <vector>
#include <array>
#include <random>

#include "World/WorldConstants.h"

class BasePixel
{
public:
   Pixels::PixelType pixel_type = Pixels::PixelType::UNDEF;
   std::array<char, Pixels::PIXEL_MAX_NAME_LENGTH> pixel_name = { "None" };
   
   bool is_updateable = false;
   // TODO : (James) Need to apply pixel value to all PixelTypes
   Uint32 new_pixel_value = 0;

   // Random seeded with pixel_type
   std::minstd_rand rand_engine;
   std::uniform_int_distribution<int> distribution;

   // Pixel Settings
   uint8_t pixel_index = 0;
   uint8_t colour_count = 0;

   Uint32 type_colours[Pixels::PIXEL_MAX_COLOUR_COUNT] = { 0 };

   const uint8_t& GetPixelUpdateOrder();
   Uint32 GetRandomColour();

protected:
   uint8_t _chunk_order_counter = 0;
   uint8_t _pixel_update_order_count = 0;
   uint8_t _pixel_update_order[Pixels::PIXEL_MAX_UPDATE_ORDER_COUNT][Chunk::NUM_DIRECTIONS] =
      {{ static_cast<uint8_t>(Chunk::WorldDir::UNDEFINED) }};

   constexpr void InsertPixelUpdateOrder(const uint8_t index, const std::vector<Chunk::WorldDir>& directions);
   void SetPixelName(const char* const name);

   // Constexpr helper function, sets the index of the pixel update order, primarily for the constructor
   #define SET_PIXEL_UPDATE_ORDER(index, ...) \
   do { \
   constexpr WorldDir values[] = { __VA_ARGS__, WorldDir::UNDEFINED, WorldDir::UNDEFINED, \
   WorldDir::UNDEFINED, WorldDir::UNDEFINED, WorldDir::UNDEFINED, \
   WorldDir::UNDEFINED, WorldDir::UNDEFINED }; \
   for (uint8_t i = 0; i < Chunk::NUM_DIRECTIONS; i++) { \
   _pixel_update_order[index][i] = static_cast<uint8_t>(values[i]); \
   } \
   } while (false)
   
private:
   #define SET_PIXEL_NAME(name) std::copy_n(name, sizeof(name), pixel_name.begin())
   
};