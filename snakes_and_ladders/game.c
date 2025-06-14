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


