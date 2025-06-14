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

