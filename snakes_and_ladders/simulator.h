//
// Created by aliss on 13.06.2025.
//

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "board.h"
#include "game.h"
#include <stdbool.h>

void run_simulations(const Board *board, int num_simulations, int die_sides, bool must_land_exactly, int max_rolls);

#endif // SIMULATOR_H

