
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#define MAX_COLOR_COUNT 1000000

typedef struct {
    char color [ 10 ];
    int count;
} ColorCount;

typedef struct {
    ColorCount * color_counts;
    int count;
} ColorCounts;

void read_color_counts ( ColorCounts * color_counts ) {
    char line [ 1000000 ];
    int i = 0;
    scanf ( "%s" , line );
    while ( line [ i ] != '\0' ) {
        color_counts->color_counts [ i ].color [ 0 ] = line [ i ];
        color_counts->color_counts [ i ].color [ 1 ] = '\0';
        scanf ( "%d" , &color_counts->color_counts [ i ].count );
        i++;
    }
    color_counts->count = i;
}

void print_color_counts ( ColorCounts * color_counts ) {
    for ( int i = 0 ; i < color_counts->count ; i++ ) {
        printf ( "%s %d\n" , color_counts->color_counts [ i ].color , color_counts->color_counts [ i ].count );
    }
}

void free_color_counts ( ColorCounts * color_counts ) {
    free ( color_counts->color_counts );
    free ( color_counts );
}

int main ( ) {
    ColorCounts * color_counts = malloc ( sizeof ( ColorCounts ) );
    color_counts->color_counts = malloc ( MAX_COLOR_COUNT * sizeof ( ColorCount ) );
    read_color_counts ( color_counts );
    print_color_counts ( color_counts );
    free_color_counts ( color_counts );
    return 0;
}

