/*
name: Run Length Encode
author: Luan Mehmeti
date: 04.11.2020
description:
FOOO -> F1O3
BAAAAR -> B1A4R1
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rle.h"

#define MAX_RLEN 128

// rle function according to the given exercise

char* encode(char* str)
{
    char* res = malloc(2 * MAX_RLEN * sizeof(char));
    int char_count;
    int i = 0;
    int j = 0;

    while (i < strlen(str))
    {
        res[j] = str[i];
        char_count = 0;

        // couting up the same characters
        while (res[j] == str[i] && char_count < 9)
        {
            ++i;
            ++char_count;
        }

        // adding char_count as a character to the string
        res[++j] = char_count + '0';
        ++j;
    }

    // closing string
    res[++j] = '\0';
    return res;
}

