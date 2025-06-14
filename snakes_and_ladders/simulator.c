//
// Created by aliss on 13.06.2025.
//

#include "simulator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROLLS 1000
#define MAX_TRANSITIONS 1000

typedef struct {
    int square;
    int count;
} TransitionUsage;

static void track_usage(TransitionUsage *usage, int *count, int square) {
    for (int i = 0; i < *count; ++i) {
        if (usage[i].square == square) {
            usage[i].count++;
            return;
        }
    }
    usage[*count].square = square;
    usage[*count].count = 1;
    (*count)++;
}

void run_simulations(const Board *board, int num_simulations, int die_sides, bool must_land_exactly) {
    int total_rolls = 0;
    int shortest_win = MAX_ROLLS;
    int shortest_sequence[MAX_ROLLS];
    int snake_usage_count = 0, ladder_usage_count = 0;
    TransitionUsage snake_usage[MAX_TRANSITIONS] = {0};
    TransitionUsage ladder_usage[MAX_TRANSITIONS] = {0};

    for (int sim = 0; sim < num_simulations; ++sim) {
        GameState state = init_game();
        int rolls[MAX_ROLLS];
        int roll_count = 0;

        while (!has_won(&state, board) && roll_count < MAX_ROLLS) {
            int roll = roll_die(die_sides);
            int prev = state.position;
            apply_move(&state, board, roll, must_land_exactly);
            rolls[roll_count++] = roll;

            if (board->transitions[prev + roll] != -1) {
                int from = prev + roll;
                int to = board->transitions[from];

                if (to > from) {
                    track_usage(ladder_usage, &ladder_usage_count, from);
                } else {
                    track_usage(snake_usage, &snake_usage_count, from);
                }
            }
        }

        if (has_won(&state, board)) {
            total_rolls += roll_count;
            if (roll_count < shortest_win) {
                shortest_win = roll_count;
                memcpy(shortest_sequence, rolls, sizeof(int) * roll_count);
            }
        }
    }
