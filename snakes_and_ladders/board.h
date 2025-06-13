//
// Created by aliss on 13.06.2025.
//

#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

// Structure representing the game board
typedef struct {
    int size;           // Total number of fields (e.g., 100 for a 10x10 board)
    int *transitions;   // transitions[i] = destination if snake/ladder at i, otherwise -1
} Board;

Board *create_board(int size);

bool add_transition(Board *board, int from, int to);

void print_board(const Board *board);

void free_board(Board *board);

#endif // BOARD_H

