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
    printf("  --games <n>      Number of games to simulate (default: 1000)\n");
    printf("  --die <n>        Number of die sides (default: 6)\n");
    printf("  --exact          Player must land exactly on last square\n");
    printf("  --help           Show this help message\n");
}

int main(int argc, char *argv[]) {
    int num_games = 1000;
    int die_sides = 6;
    int must_exact = 0;

    static struct option long_options[] = {
        {"games", required_argument, 0, 'g'},
        {"die", required_argument, 0, 'd'},
        {"exact", no_argument, 0, 'e'},  // <- geändert
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    int opt;
    int opt_index = 0;
    while ((opt = getopt_long(argc, argv, "g:d:h", long_options, &opt_index)) != -1) {
        switch (opt) {
            case 'g':
                num_games = atoi(optarg);
            break;
            case 'd':
                die_sides = atoi(optarg);
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

