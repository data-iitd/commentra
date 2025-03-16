
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
  // Create a new Scanner object to read input from the console
  char *s = malloc ( 100 * sizeof ( char ) ) ;
  char *t = malloc ( 100 * sizeof ( char ) ) ;

  // Read the first time string from the console and split it into hour and minute parts
  scanf ( "%s", s ) ;
  char *s_hour = strtok ( s, ":" ) ;
  char *s_minute = strtok ( NULL, ":" ) ;

  // Read the second time string from the console and split it into hour and minute parts
  scanf ( "%s", t ) ;
  char *t_hour = strtok ( t, ":" ) ;
  char *t_minute = strtok ( NULL, ":" ) ;

  // Create LocalTime objects `x` and `y` from the hour and minute parts of the first and second time strings, respectively
  int x_hour = atoi ( s_hour ) ;
  int x_minute = atoi ( s_minute ) ;
  int y_hour = atoi ( t_hour ) ;
  int y_minute = atoi ( t_minute ) ;

  // Print the result of subtracting the second time from the first time, which is the difference between the two times in hours and minutes
  printf ( "%d:%d\n", x_hour - y_hour, x_minute - y_minute ) ;

  // Free the memory allocated for the strings
  free ( s ) ;
  free ( t ) ;

  return 0 ;
}

