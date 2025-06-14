//
// Created by aliss on 13.06.2025.
//

#ifndef GAME_H
#define GAME_H

#include "board.h"

typedef struct {
    int position;
    int steps;
} GameState;

GameState init_game();

#endif // GAME_H

