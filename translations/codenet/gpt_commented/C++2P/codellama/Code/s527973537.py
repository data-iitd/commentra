#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <iomanip>
#include <utility>
#include <bitset>
#include <set>
#include <map>
#include <ios>
#include <cstdlib>
using namespace std;

int main() {
    # Read input number as a string
    N = input()

    # Initialize a variable to hold the sum of the digits
    S = 0

    # Calculate the sum of the digits in the input string
    for i in range(len(N)):
        S += int(N[i])

    # Check if the original number is divisible by the sum of its digits
    if int(N) % S == 0:
        print("Yes")
    else:
        print("No")

    return 0
}

