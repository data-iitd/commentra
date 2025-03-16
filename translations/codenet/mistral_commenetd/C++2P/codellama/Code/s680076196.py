#include <iostream>   # Include input/output library
#include <algorithm>  # Include standard algorithms library
#include <cmath>      # Include mathematical functions library
using namespace std;   # Use standard namespace

typedef long long ll; # Define a new type alias for long long int

int main():
  # Declare variables a, b, c, and d of type int
  a, b, c, d = int, int, int, int

  # Read values of variables a, b, c, and d from standard input
  cin >> a >> b >> c >> d

  # Calculate the difference between a and c, and the difference between b and d
  difference_ab = static_cast<ll>(a) - static_cast<ll>(c)
  difference_cd = static_cast<ll>(b) - static_cast<ll>(d)

  # Multiply the differences and print the result to standard output
  cout << difference_ab * difference_cd << endl

