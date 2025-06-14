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

void apply_move(GameState *state, const Board *board, int die_result, bool must_land_exactly);

bool has_won(const GameState *state, const Board *board);

#endif // GAME_H
