

#include <iostream> // Include the iostream library for handling input/output operations
#include <string> // Include the string library for handling strings
#include <sstream> // Include the stringstream library for converting strings to integers
#include <ctime> // Include the ctime library for handling time operations

using namespace std ; // Use the standard namespace for the code

int main ( ) {
  // Create a string variable `s` to store the first time string
  string s ;

  // Read the first time string from the console and store it in the `s` variable
  getline ( cin, s ) ;

  // Create a string variable `t` to store the second time string
  string t ;

  // Read the second time string from the console and store it in the `t` variable
  getline ( cin, t ) ;

  // Create a stringstream object `ss1` to convert the first time string to an integer
  stringstream ss1 ( s ) ;

  // Create a stringstream object `ss2` to convert the second time string to an integer
  stringstream ss2 ( t ) ;

  // Create an integer variable `h1` to store the hour part of the first time string
  int h1 ;

  // Read the hour part of the first time string from the `ss1` stringstream object and store it in the `h1` variable
  ss1 >> h1 ;

  // Create an integer variable `m1` to store the minute part of the first time string
  int m1 ;

  // Read the minute part of the first time string from the `ss1` stringstream object and store it in the `m1` variable
  ss1 >> m1 ;

  // Create an integer variable `h2` to store the hour part of the second time string
  int h2 ;

  // Read the hour part of the second time string from the `ss2` stringstream object and store it in the `h2` variable
  ss2 >> h2 ;

  // Create an integer variable `m2` to store the minute part of the second time string
  int m2 ;

  // Read the minute part of the second time string from the `ss2` stringstream object and store it in the `m2` variable
  ss2 >> m2 ;

  // Create a time_t variable `time1` to store the time value of the first time string
  time_t time1 = mktime ( localtime ( & time1 ) ) ;

  // Create a time_t variable `time2` to store the time value of the second time string
  time_t time2 = mktime ( localtime ( & time2 ) ) ;

  // Calculate the difference between the two time values in seconds
  time_t diff = difftime ( time1, time2 ) ;

  // Calculate the difference between the two time values in hours
  int hours = diff / 3600 ;

  // Calculate the difference between the two time values in minutes
  int minutes = ( diff % 3600 ) / 60 ;

  // Print the result of subtracting the second time from the first time, which is the difference between the two times in hours and minutes
  cout << hours << ":" << minutes << endl ;

  return 0 ;
}

