
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std ;

int main ( ) {
  // Create a new Scanner object to read input from the console
  Scanner sc = new Scanner ( System.in ) ;

  // Read the first time string from the console and split it into hour and minute parts
  string [ ] s = sc.next ( ).split ( ":" ) ;

  // Read the second time string from the console and split it into hour and minute parts
  string [ ] t = sc.next ( ).split ( ":" ) ;

  // Create LocalTime objects `x` and `y` from the hour and minute parts of the first and second time strings, respectively
  LocalTime x = LocalTime.of ( stoi ( s [ 0 ] ) , stoi ( s [ 1 ] ) ) ;
  LocalTime y = LocalTime.of ( stoi ( t [ 0 ] ) , stoi ( t [ 1 ] ) ) ;

  // Print the result of subtracting the second time from the first time, which is the difference between the two times in hours and minutes
  cout << x.minusHours ( y.getHour ( ) ).minusMinutes ( y.getMinute ( ) ) << endl ;

  return 0 ;
}

