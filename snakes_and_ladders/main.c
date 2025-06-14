//
// Created by aliss on 13.06.2025.
//
#include "board.h"
#include "simulator.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <time.h>

void print_usage(const char *progname) {
    printf("Usage: %s [OPTIONS]\n", progname);
    printf("Options:\n");
    printf("  --size <n>       Board size (number of squares), default: 100\n");
    printf("  --games <n>      Number of games to simulate, default: 1000\n");
    printf("  --die <n>        Number of sides on the die, default: 6\n");
    printf("  --limit <n>      Maximum moves per game, default: 1000\n");
    printf("  --exact          Require exact landing on last square to win\n");
    printf("  --help           Show this help message\n");
}

int main(int argc, char *argv[]) {
    int board_size = 100;
    int num_games = 1000;
    int die_sides = 6;
    int max_rolls = 1000;
    int must_exact = 0;

    static struct option long_options[] = {
        {"size", required_argument, 0, 's'},
        {"games", required_argument, 0, 'g'},
        {"die", required_argument, 0, 'd'},
        {"limit", required_argument, 0, 'l'},
        {"exact", no_argument, 0, 'e'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    int opt, opt_index = 0;
    while ((opt = getopt_long(argc, argv, "s:g:d:l:eh", long_options, &opt_index)) != -1) {
        switch (opt) {
            case 's':
                board_size = atoi(optarg);
                break;
            case 'g':
                num_games = atoi(optarg);
                break;
            case 'd':
                die_sides = atoi(optarg);
                break;
            case 'l':
                max_rolls = atoi(optarg);
                break;
            case 'e':
                must_exact = 1;
                break;
            case 'h':
                print_usage(argv[0]);
                return 0;
            default:
                print_usage(argv[0]);
                return 1;
        }
    }

    srand(time(NULL));

    Board *board = create_board(board_size);

    // Example hardcoded transitions – later replaced by --board support
    add_transition(board, 3, 22);
    add_transition(board, 5, 8);
    add_transition(board, 11, 26);
    add_transition(board, 20, 29);
    add_transition(board, 27, 1);
    add_transition(board, 21, 9);
    add_transition(board, 17, 4);
    add_transition(board, 99, 77);

    run_simulations(board, num_games, die_sides, must_exact, max_rolls);

    free_board(board);
    return 0;
}
