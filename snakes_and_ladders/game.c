//
// Created by aliss on 13.06.2025.
//

#include "game.h"
#include <stdlib.h>

GameState init_game() {
    GameState state;
    state.position = -1;  // Player starts before the board
    state.steps = 0;
    return state;
}

int roll_die(int sides) {
    return (rand() % sides) + 1;  // Returns value from 1 to sides
}

void apply_move(GameState *state, const Board *board, int die_result, bool must_land_exactly) {
    if (!state || !board) return;

    int target = state->position + die_result;
    int last_square = board->size - 1;

    if (target > last_square && must_land_exactly) {
        // Overshooting not allowed → no move
        state->steps++;
        return;
    }

    // Move to target or final square
    if (target > last_square) target = last_square;

    // Check for snake or ladder
    if (board->transitions[target] != -1) {
        target = board->transitions[target];
    }

    state->position = target;
    state->steps++;
}

bool has_won(const GameState *state, const Board *board) {
    return state && board && (state->position == board->size - 1);
}

