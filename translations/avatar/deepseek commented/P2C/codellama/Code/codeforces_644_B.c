#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAX_TASKS 1000
#define MAX_BUFFER 1000
#define MAX_TIME 1000000

typedef struct {
    int time;
    int duration;
    int index;
} Task;

int main ( ) {
    int n, b;
    scanf ( "%d %d", &n, &b );
    Task tasks [ MAX_TASKS ];
    int result [ MAX_TASKS ];
    memset ( result, 0, sizeof ( result ) );
    int remaining = 0;
    bool running = false;
    int finish_time = 0;

    for ( int i = 0; i < n; i++ ) {
        scanf ( "%d %d", &tasks [ i ].time, &tasks [ i ].duration );
        tasks [ i ].index = i;
        result [ i ] = 0;
        if ( tasks [ i ].time > finish_time && remaining == 0 ) {
            running = true;
            finish_time = tasks [ i ].time + tasks [ i ].duration;
            result [ i ] = finish_time;
        } else {
            if ( tasks [ i ].time >= finish_time && remaining > 0 ) {
                finish_time = tasks [ i ].time + tasks [ i ].duration;
                result [ i ] = finish_time;
            }
            if ( remaining < b ) {
                remaining++;
            } else {
                result [ i ] = -1;
            }
        }
    }

    while ( remaining > 0 ) {
        for ( int i = 0; i < n; i++ ) {
            if ( tasks [ i ].time <= finish_time ) {
                finish_time = tasks [ i ].time + tasks [ i ].duration;
                result [ i ] = finish_time;
                remaining--;
            }
        }
    }

    for ( int i = 0; i < n; i++ ) {
        printf ( "%d\n", result [ i ] );
    }

    return 0;
}

