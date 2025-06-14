//
// Created by aliss on 13.06.2025.
//

#ifndef GAME_H
#define GAME_H

#include "board.h"
#include <stdbool.h>

// Represents the current state of a game
typedef struct {
    int position;    // Current position on the board (0-based index)
    int steps;       // Number of dice rolls taken so far
} GameState;

GameState init_game();

int roll_die(int sides);

#endif // GAME_H
