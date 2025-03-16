

#include <stdio.h> // Include the standard input/output library
#include <stdlib.h> // Include the standard library for dynamic memory allocation
#include <time.h> // Include the time library for handling time

int main ( void ) {
  // Create a new time_t variable to store the current time
  time_t now ;

  // Get the current time and store it in the `now` variable
  time ( &now ) ;

  // Create a new tm structure to store the local time
  struct tm *ltm = localtime ( &now ) ;

  // Read the first time string from the console and split it into hour and minute parts
  int h1, m1 ;
  scanf ( "%d:%d", &h1, &m1 ) ;

  // Read the second time string from the console and split it into hour and minute parts
  int h2, m2 ;
  scanf ( "%d:%d", &h2, &m2 ) ;

  // Calculate the difference between the two times in seconds
  int diff = ( h1 - h2 ) * 3600 + ( m1 - m2 ) * 60 ;

  // Print the result of subtracting the second time from the first time, which is the difference between the two times in hours and minutes
  printf ( "%d:%d\n", diff / 3600, diff % 3600 / 60 ) ;

  // Return 0 to indicate successful execution of the program
  return 0 ;
}

