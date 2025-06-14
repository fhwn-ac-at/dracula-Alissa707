//
// Created by aliss on 13.06.2025.
//

#include "game.h"

GameState init_game() {
    GameState state;
    state.position = -1;  // Player starts before the board
    state.steps = 0;
    return state;
}


