//
// Created by aliss on 13.06.2025.
//

#include "board.h"
#include <stdio.h>
#include <stdlib.h>

Board *create_board(int size) {
    if (size <= 1) return NULL;

    Board *board = malloc(sizeof(Board));
    if (!board) return NULL;

    board->size = size;
    board->transitions = malloc(sizeof(int) * size);
    if (!board->transitions) {
        free(board);
        return NULL;
    }

    // Initialize all transitions to -1 (no snake or ladder)
    for (int i = 0; i < size; ++i) {
        board->transitions[i] = -1;
    }

    return board;
}

bool add_transition(Board *board, int from, int to) {
    // Validate indices and prevent illegal transitions
    if (!board || from < 0 || from >= board->size || to < 0 || to >= board->size) {
        return false;
    }
    if (from == to || from == board->size - 1) return false;

    board->transitions[from] = to;
    return true;
}

void print_board(const Board *board) {
    if (!board) return;
    printf("Board with %d squares:\n", board->size);
    for (int i = 0; i < board->size; ++i) {
        if (board->transitions[i] != -1) {
            if (board->transitions[i] > i)
                printf("Ladder:  %2d -> %2d\n", i + 1, board->transitions[i] + 1);
            else
                printf("Snake:   %2d -> %2d\n", i + 1, board->transitions[i] + 1);
        }
    }
}

void free_board(Board *board) {
    if (!board) return;
    free(board->transitions);
    free(board);
}

