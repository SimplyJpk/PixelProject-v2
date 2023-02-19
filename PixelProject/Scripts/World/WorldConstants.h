#pragma once
#include <cstdint>

namespace Chunk {
   // Chunk Size
   constexpr short CHUNK_SIZE_X = 128;
   constexpr short CHUNK_HALF_X = CHUNK_SIZE_X / 2;

   constexpr short CHUNK_SIZE_Y = 128;
   constexpr short CHUNK_HALF_Y = CHUNK_SIZE_Y / 2;

   constexpr short CHUNK_TOTAL_SIZE = CHUNK_SIZE_X * CHUNK_SIZE_Y;

   // Corner index of a chunk
   constexpr short CHUNK_CORNER_NORTH_WEST = 0;
   constexpr short CHUNK_CORNER_NORTH_EAST = CHUNK_SIZE_X - 1;
   constexpr short CHUNK_CORNER_SOUTH_EAST = CHUNK_TOTAL_SIZE - 1;
   constexpr short CHUNK_CORNER_SOUTH_WEST = CHUNK_TOTAL_SIZE - CHUNK_SIZE_X;

   // Target Size (1080p pixels, 1920x1152), v1 was 8x5 (1024x640)
   constexpr short WORLD_SIZE_X = 15;
   constexpr short WORLD_SIZE_Y = 9;

   enum class WorldDir : uint8_t
   {
      North = 0,
      NorthEast = 1,
      East = 2,
      SouthEast = 3,
      South = 4,
      SouthWest = 5,
      West = 6,
      NorthWest = 7
   };

   static constexpr uint8_t NUM_DIRECTIONS = 8;
   static constexpr uint8_t GetDirectionIndex(const WorldDir direction)
   {
      return static_cast<uint8_t>(direction);
   }
   
}
   
namespace Pixels {
   constexpr int8_t PIXEL_MAX_NAME_LENGTH = 16;
   constexpr char PIXEL_NAME_UNDEFINED[PIXEL_MAX_NAME_LENGTH] = "N/A";
   
   // Max colours a pixel can reference
   constexpr int8_t PIXEL_MAX_COLOUR_COUNT = 4;
   // Max pixel direction orders a PixelType can have
   constexpr int8_t PIXEL_MAX_UPDATE_ORDER_COUNT = 4;

   enum class PixelType : int8_t
   {
      UNDEF = -1,
      Space = 0,
      Dirt = 1,
      Sand = 2
   };
   constexpr int8_t PIXEL_TYPE_COUNT = 3;

   constexpr int16_t PIXEL_INDEX_DIRECTION_CHANGE[] = {
      /* N  */    -Chunk::CHUNK_SIZE_X,
      /* NE */    -Chunk::CHUNK_SIZE_X + 1,
      /* E  */    1,
      /* SE */    Chunk::CHUNK_SIZE_X + 1,
      /* S  */    Chunk::CHUNK_SIZE_X,
      /* SW */    Chunk::CHUNK_SIZE_X - 1,
      /* W  */    -1,
      /* NW */    -Chunk::CHUNK_SIZE_X - 1
   };
   
}

namespace Direction {
   // constexpr int8_t NEW_CHUNK_BIT = 30;
   // constexpr int8_t NEGATIVE_BIT = 28;
         
}