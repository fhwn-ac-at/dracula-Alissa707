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


