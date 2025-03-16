
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // Read the first time string from the console and split it into hour and minute parts
    char *s = (char *) malloc ( 100 * sizeof ( char ) ) ;
    scanf ( "%s", s ) ;
    char *t = (char *) malloc ( 100 * sizeof ( char ) ) ;
    scanf ( "%s", t ) ;

    // Create time_t objects `x` and `y` from the hour and minute parts of the first and second time strings, respectively
    struct tm x, y ;
    sscanf ( s, "%d:%d", &x.tm_hour, &x.tm_min ) ;
    sscanf ( t, "%d:%d", &y.tm_hour, &y.tm_min ) ;

    // Print the result of subtracting the second time from the first time, which is the difference between the two times in hours and minutes
    printf ( "%d:%d\n", x.tm_hour - y.tm_hour, x.tm_min - y.tm_min ) ;

    // Free the memory allocated to the strings
    free ( s ) ;
    free ( t ) ;

    return 0 ;
}

