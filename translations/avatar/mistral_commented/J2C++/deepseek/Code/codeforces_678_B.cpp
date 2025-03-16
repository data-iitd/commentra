#include <iostream>
using namespace std;

// A function to check if a given year is a leap year or not
bool check_leap(int y) {
  // Returning true if the given year is divisible by 400, or if it is divisible by 4 and not divisible by 100, but not divisible by 100 if the century is not divisible by 4
  return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int main() {
  // Creating a new Scanner object to read input from the standard input stream
  int y;
  cin >> y;

  // Checking if the given year is a leap year or not
  bool leap = check_leap(y);

  // Initializing the sum variable to 0 and mod variable to 0
  int sum = 0;

  // Starting the loop from the year + 1
  for (int i = y + 1; ; i++) {

    // Checking if the current year is a leap year or not
    if (check_leap(i)) {

      // If the current year is a leap year and the previous year was also a leap year,
      // then print the current year and exit the loop
      sum += 366;
      if ((leap && check_leap(i)) || (!leap && !check_leap(i))) {
        cout << i << endl;
        return 0;
      }

    } else {

      // If the current year is not a leap year, then add 365 to the sum
      sum += 365;

    }

    // Checking if the sum is divisible by 7
    if (sum % 7 == 0) {

      // If the current year is a leap year and the previous year was also a leap year,
      // or if the current year is not a leap year and the previous year was not a leap year,
      // then continue to the next iteration of the loop
      if ((leap && check_leap(i)) || (!leap && !check_leap(i))) {
        continue;
      }

      // If the conditions are not met, then print the current year and exit the loop
      cout << i << endl;
      return 0;

    }

  }

  return 0;
}

