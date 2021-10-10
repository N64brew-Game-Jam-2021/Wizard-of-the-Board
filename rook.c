
#include "pieces.h"

#include "constants.h"


void rookLegalMove(u32 ourIndex, const u8* piecesActive, const Pos2* piecePositions, u8* legalSpots) {
  const Pos2* ourPosition = &(piecePositions[ourIndex]);

  // Check east availability
  for (int stepX = (ourPosition->x + 1); stepX < BOARD_WIDTH; stepX++) {

    const Pos2 desiredSpot = { stepX, ourPosition->y };
    u32 broken = 0;
    for (int i = 0; i < MAX_NUMBER_OF_INGAME_PIECES; i++) {
      if (i == ourIndex) {
        continue;
      }

      if (!(piecesActive[i])) {
        continue;
      }

      // If our desired spot matches a piece, it's occupied and we can't move forward
      if ((piecePositions[i].x == desiredSpot.x) && (piecePositions[i].y == desiredSpot.y)) {
        broken = 1;
        break;
      }
    }

    if (broken) {
      break;
    }

    legalSpots[stepX + (BOARD_WIDTH * ourPosition->y)] = 1;
  }

  // Check west availability
  for (int stepX = (ourPosition->x - 1); stepX >= 0; stepX--) {

    const Pos2 desiredSpot = { stepX, ourPosition->y };
    u32 broken = 0;
    for (int i = 0; i < MAX_NUMBER_OF_INGAME_PIECES; i++) {
      if (i == ourIndex) {
        continue;
      }

      if (!(piecesActive[i])) {
        continue;
      }

      // If our desired spot matches a piece, it's occupied and we can't move forward
      if ((piecePositions[i].x == desiredSpot.x) && (piecePositions[i].y == desiredSpot.y)) {
        broken = 1;
        break;
      }
    }

    if (broken) {
      break;
    }

    legalSpots[stepX + (BOARD_WIDTH * ourPosition->y)] = 1;
  }

  // Check north availability
  for (int stepY = (ourPosition->y + 1); stepY < BOARD_HEIGHT; stepY++) {

    const Pos2 desiredSpot = { ourPosition->x, stepY };
    u32 broken = 0;
    for (int i = 0; i < MAX_NUMBER_OF_INGAME_PIECES; i++) {
      if (i == ourIndex) {
        continue;
      }

      if (!(piecesActive[i])) {
        continue;
      }

      // If our desired spot matches a piece, it's occupied and we can't move forward
      if ((piecePositions[i].x == desiredSpot.x) && (piecePositions[i].y == desiredSpot.y)) {
        broken = 1;
        break;
      }
    }

    if (broken) {
      break;
    }

    legalSpots[ourPosition->x + (BOARD_WIDTH * stepY)] = 1;
  }

  // Check south availability
  for (int stepY = (ourPosition->y - 1); stepY >= 0; stepY--) {

    const Pos2 desiredSpot = { ourPosition->x, stepY };
    u32 broken = 0;
    for (int i = 0; i < MAX_NUMBER_OF_INGAME_PIECES; i++) {
      if (i == ourIndex) {
        continue;
      }

      if (!(piecesActive[i])) {
        continue;
      }

      // If our desired spot matches a piece, it's occupied and we can't move forward
      if ((piecePositions[i].x == desiredSpot.x) && (piecePositions[i].y == desiredSpot.y)) {
        broken = 1;
        break;
      }
    }

    if (broken) {
      break;
    }

    legalSpots[ourPosition->x + (BOARD_WIDTH * stepY)] = 1;
  }
}

Vtx rook_verts[] = {
  { 67, -70, 0, 0, 0, 0, 43, 43, 43, 255 },
  { 67, -70, 44, 0, 0, 0, 158, 158, 158, 255 },
  { 65, -54, 264, 0, 0, 0, 80, 80, 80, 255 },
  { 50, -45, 289, 0, 0, 0, 158, 158, 158, 255 },
  { 81, -30, 347, 0, 0, 0, 189, 189, 189, 255 },
  { 44, -70, 347, 0, 0, 0, 189, 189, 189, 255 },
  { 84, -32, 311, 0, 0, 0, 189, 189, 189, 255 },
  { 47, -72, 311, 0, 0, 0, 189, 189, 189, 255 },
  { -67, -70, 0, 0, 0, 0, 43, 43, 43, 255 },
  { -67, -70, 44, 0, 0, 0, 158, 158, 158, 255 },
  { 0, -51, 249, 0, 0, 0, 45, 45, 45, 255 },
  { -65, -54, 264, 0, 0, 0, 80, 80, 80, 255 },
  { 0, -66, 67, 0, 0, 0, 157, 157, 157, 255 },
  { 0, -96, 1, 0, 0, 0, 40, 40, 40, 255 },
  { 0, -96, 44, 0, 0, 0, 166, 166, 166, 255 },
  { 0, -94, 264, 0, 0, 0, 66, 66, 66, 255 },
  { 0, -94, 347, 0, 0, 0, 207, 207, 207, 255 },
  { -50, -45, 289, 0, 0, 0, 158, 158, 158, 255 },
  { 0, -69, 289, 0, 0, 0, 158, 158, 158, 255 },
  { -81, -30, 347, 0, 0, 0, 189, 189, 189, 255 },
  { -44, -70, 347, 0, 0, 0, 189, 189, 189, 255 },
  { -84, -32, 311, 0, 0, 0, 189, 189, 189, 255 },
  { -47, -72, 311, 0, 0, 0, 189, 189, 189, 255 },
  { 96, 0, 1, 0, 0, 0, 43, 43, 43, 255 },
  { 67, 70, 0, 0, 0, 0, 43, 43, 43, 255 },
  { 96, 0, 44, 0, 0, 0, 160, 160, 160, 255 },
  { 67, 70, 44, 0, 0, 0, 158, 158, 158, 255 },
  { 54, 0, 249, 0, 0, 0, 39, 39, 39, 255 },
  { 87, 0, 264, 0, 0, 0, 82, 82, 82, 255 },
  { 65, 54, 264, 0, 0, 0, 80, 80, 80, 255 },
  { 69, 0, 67, 0, 0, 0, 199, 199, 199, 255 },
  { 87, 0, 347, 0, 0, 0, 189, 189, 189, 255 },
  { 50, 45, 289, 0, 0, 0, 158, 158, 158, 255 },
  { 66, 0, 289, 0, 0, 0, 107, 107, 107, 255 },
  { 81, 30, 347, 0, 0, 0, 189, 189, 189, 255 },
  { 44, 70, 347, 0, 0, 0, 189, 189, 189, 255 },
  { 84, 32, 311, 0, 0, 0, 189, 189, 189, 255 },
  { 47, 72, 311, 0, 0, 0, 189, 189, 189, 255 },
  { -96, 0, 1, 0, 0, 0, 43, 43, 43, 255 },
  { -67, 70, 0, 0, 0, 0, 43, 43, 43, 255 },
  { -96, 0, 44, 0, 0, 0, 160, 160, 160, 255 },
  { -67, 70, 44, 0, 0, 0, 158, 158, 158, 255 },
  { -54, 0, 249, 0, 0, 0, 39, 39, 39, 255 },
  { 0, 51, 249, 0, 0, 0, 45, 45, 45, 255 },
  { -87, 0, 264, 0, 0, 0, 82, 82, 82, 255 },
  { -65, 54, 264, 0, 0, 0, 80, 80, 80, 255 },
  { 0, 66, 67, 0, 0, 0, 157, 157, 157, 255 },
  { -69, 0, 67, 0, 0, 0, 199, 199, 199, 255 },
  { 0, 0, 96, 0, 0, 0, 50, 50, 50, 255 },
  { 0, 96, 1, 0, 0, 0, 40, 40, 40, 255 },
  { 0, 96, 44, 0, 0, 0, 166, 166, 166, 255 },
  { 0, 94, 264, 0, 0, 0, 66, 66, 66, 255 },
  { -87, 0, 347, 0, 0, 0, 189, 189, 189, 255 },
  { 0, 94, 347, 0, 0, 0, 207, 207, 207, 255 },
  { -50, 45, 289, 0, 0, 0, 158, 158, 158, 255 },
  { 0, 0, 289, 0, 0, 0, 158, 158, 158, 255 },
  { 0, 69, 289, 0, 0, 0, 158, 158, 158, 255 },
  { -66, 0, 289, 0, 0, 0, 107, 107, 107, 255 },
  { -81, 30, 347, 0, 0, 0, 189, 189, 189, 255 },
  { -44, 70, 347, 0, 0, 0, 189, 189, 189, 255 },
  { -84, 32, 311, 0, 0, 0, 189, 189, 189, 255 },
  { -47, 72, 311, 0, 0, 0, 189, 189, 189, 255 },
};
Gfx rook_commands[]  = {
  gsSPVertex(&rook_verts, 62, 0),
  gsSP2Triangles(0, 48, 23, 0, 48, 0, 13, 0),
  gsSP2Triangles(0, 23, 1, 0, 13, 0, 1, 0),
  gsSP2Triangles(12, 30, 27, 0, 10, 27, 28, 0),
  gsSP2Triangles(1, 25, 30, 0, 14, 1, 12, 0),
  gsSP2Triangles(25, 1, 23, 0, 13, 1, 14, 0),
  gsSP2Triangles(12, 27, 10, 0, 10, 2, 15, 0),
  gsSP2Triangles(10, 28, 2, 0, 1, 30, 12, 0),
  gsSP2Triangles(2, 7, 16, 0, 16, 3, 18, 0),
  gsSP2Triangles(28, 4, 6, 0, 33, 55, 3, 0),
  gsSP2Triangles(3, 55, 18, 0, 3, 31, 33, 0),
  gsSP2Triangles(3, 4, 31, 0, 6, 7, 2, 0),
  gsSP2Triangles(3, 7, 6, 0, 3, 5, 7, 0),
  gsSP2Triangles(16, 15, 2, 0, 7, 5, 16, 0),
  gsSP2Triangles(6, 2, 28, 0, 28, 31, 4, 0),
  gsSP2Triangles(3, 6, 4, 0, 3, 16, 5, 0),
  gsSP2Triangles(8, 38, 48, 0, 48, 13, 8, 0),
  gsSP2Triangles(8, 9, 38, 0, 13, 9, 8, 0),
  gsSP2Triangles(12, 42, 47, 0, 10, 44, 42, 0),
  gsSP2Triangles(9, 47, 40, 0, 14, 12, 9, 0),
  gsSP2Triangles(40, 38, 9, 0, 13, 14, 9, 0),
  gsSP2Triangles(12, 10, 42, 0, 10, 15, 11, 0),
  gsSP2Triangles(10, 11, 44, 0, 9, 12, 47, 0),
  gsSP2Triangles(11, 16, 22, 0, 16, 18, 17, 0),
  gsSP2Triangles(44, 21, 19, 0, 57, 17, 55, 0),
  gsSP2Triangles(17, 18, 55, 0, 17, 57, 52, 0),
  gsSP2Triangles(17, 52, 19, 0, 21, 11, 22, 0),
  gsSP2Triangles(17, 21, 22, 0, 17, 22, 20, 0),
  gsSP2Triangles(16, 11, 15, 0, 22, 16, 20, 0),
  gsSP2Triangles(21, 44, 11, 0, 44, 19, 52, 0),
  gsSP2Triangles(17, 19, 21, 0, 17, 20, 16, 0),
  gsSP2Triangles(24, 23, 48, 0, 48, 49, 24, 0),
  gsSP2Triangles(24, 26, 23, 0, 49, 26, 24, 0),
  gsSP2Triangles(46, 27, 30, 0, 43, 28, 27, 0),
  gsSP2Triangles(26, 30, 25, 0, 50, 46, 26, 0),
  gsSP2Triangles(25, 23, 26, 0, 49, 50, 26, 0),
  gsSP2Triangles(46, 43, 27, 0, 43, 51, 29, 0),
  gsSP2Triangles(43, 29, 28, 0, 26, 46, 30, 0),
  gsSP2Triangles(29, 53, 37, 0, 53, 56, 32, 0),
  gsSP2Triangles(28, 36, 34, 0, 33, 32, 55, 0),
  gsSP2Triangles(32, 56, 55, 0, 32, 33, 31, 0),
  gsSP2Triangles(32, 31, 34, 0, 36, 29, 37, 0),
  gsSP2Triangles(32, 36, 37, 0, 32, 37, 35, 0),
  gsSP2Triangles(53, 29, 51, 0, 37, 53, 35, 0),
  gsSP2Triangles(36, 28, 29, 0, 28, 34, 31, 0),
  gsSP2Triangles(32, 34, 36, 0, 32, 35, 53, 0),
  gsSP2Triangles(39, 48, 38, 0, 48, 39, 49, 0),
  gsSP2Triangles(39, 38, 41, 0, 49, 39, 41, 0),
  gsSP2Triangles(46, 47, 42, 0, 43, 42, 44, 0),
  gsSP2Triangles(41, 40, 47, 0, 50, 41, 46, 0),
  gsSP2Triangles(40, 41, 38, 0, 49, 41, 50, 0),
  gsSP2Triangles(46, 42, 43, 0, 43, 45, 51, 0),
  gsSP2Triangles(43, 44, 45, 0, 41, 47, 46, 0),
  gsSP2Triangles(45, 61, 53, 0, 53, 54, 56, 0),
  gsSP2Triangles(44, 58, 60, 0, 57, 55, 54, 0),
  gsSP2Triangles(54, 55, 56, 0, 54, 52, 57, 0),
  gsSP2Triangles(54, 58, 52, 0, 60, 61, 45, 0),
  gsSP2Triangles(54, 61, 60, 0, 54, 59, 61, 0),
  gsSP2Triangles(53, 51, 45, 0, 61, 59, 53, 0),
  gsSP2Triangles(60, 45, 44, 0, 44, 52, 58, 0),
  gsSP2Triangles(54, 60, 58, 0, 54, 53, 59, 0),
  gsSPEndDisplayList()
};