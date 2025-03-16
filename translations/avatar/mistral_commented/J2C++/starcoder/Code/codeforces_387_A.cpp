
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

int main() {
  // Read the first time string from the console and split it into hour and minute parts
  string s;
  cin >> s;
  int hour = stoi(s.substr(0, 2));
  int minute = stoi(s.substr(3, 2));

  // Read the second time string from the console and split it into hour and minute parts
  string t;
  cin >> t;
  int hour2 = stoi(t.substr(0, 2));
  int minute2 = stoi(t.substr(3, 2));

  // Create a `std::chrono::time_point` object `x` from the hour and minute parts of the first time string
  auto x = chrono::hours(hour) + chrono::minutes(minute);

  // Create a `std::chrono::time_point` object `y` from the hour and minute parts of the second time string
  auto y = chrono::hours(hour2) + chrono::minutes(minute2);

  // Print the result of subtracting the second time from the first time, which is the difference between the two times in hours and minutes
  cout << x - y << endl;
}

