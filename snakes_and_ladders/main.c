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

#define MAX_TRANSITIONS 100

void print_usage(const char *progname) {
    printf("Usage: %s [OPTIONS]\n", progname);
    printf("Options:\n");
    printf("  --size <n>       Board size (number of squares), default: 100\n");
    printf("  --games <n>      Number of games to simulate, default: 1000\n");
    printf("  --die <n>        Number of sides on the die, default: 6\n");
    printf("  --limit <n>      Maximum moves per game, default: 1000\n");
    printf("  --exact          Require exact landing on last square to win\n");
    printf("  --snake <from> <to>   Add a snake (multiple allowed)\n");
    printf("  --ladder <from> <to>  Add a ladder (multiple allowed)\n");
    printf("  --help           Show this help message\n");
}

int main(int argc, char *argv[]) {
    int board_size = 100;
    int num_games = 1000;
    int die_sides = 6;
    int max_rolls = 1000;
    int must_exact = 0;

    // Arrays for snake/ladder transitions
    int snake_from[MAX_TRANSITIONS], snake_to[MAX_TRANSITIONS], snake_count = 0;
    int ladder_from[MAX_TRANSITIONS], ladder_to[MAX_TRANSITIONS], ladder_count = 0;

    static struct option long_options[] = {
        {"size", required_argument, 0, 's'},
        {"games", required_argument, 0, 'g'},
        {"die", required_argument, 0, 'd'},
        {"limit", required_argument, 0, 'l'},
        {"exact", no_argument, 0, 'e'},
        {"snake", required_argument, 0, 1},
        {"ladder", required_argument, 0, 2},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    int opt, opt_index = 0;
    while ((opt = getopt_long(argc, argv, "s:g:d:l:eh", long_options, &opt_index)) != -1) {
        switch (opt) {
            case 's': board_size = atoi(optarg); break;
            case 'g': num_games = atoi(optarg); break;
            case 'd': die_sides = atoi(optarg); break;
            case 'l': max_rolls = atoi(optarg); break;
            case 'e': must_exact = 1; break;
            case 'h': print_usage(argv[0]); return 0;
            case 1: // --snake
                if (optind < argc) {
                    if (snake_count < MAX_TRANSITIONS) {
                        snake_from[snake_count] = atoi(optarg);
                        snake_to[snake_count] = atoi(argv[optind++]);
                        snake_count++;
                    }
                }
                break;
            case 2: // --ladder
                if (optind < argc) {
                    if (ladder_count < MAX_TRANSITIONS) {
                        ladder_from[ladder_count] = atoi(optarg);
                        ladder_to[ladder_count] = atoi(argv[optind++]);
                        ladder_count++;
                    }
                }
                break;
            default:
                print_usage(argv[0]);
                return 1;
        }
    }

    srand(time(NULL));

    Board *board = create_board(board_size);

    for (int i = 0; i < snake_count; ++i) {
        add_transition(board, snake_from[i] - 1, snake_to[i] - 1);
    }

    for (int i = 0; i < ladder_count; ++i) {
        add_transition(board, ladder_from[i] - 1, ladder_to[i] - 1);
    }

    run_simulations(board, num_games, die_sides, must_exact, max_rolls);

    free_board(board);
    return 0;
}

