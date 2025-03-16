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
    # Step 3: Input a string
    N = input()

    # Step 4: Calculate the sum of digits
    S = 0
    for i in range(len(N)):
        S += int(N[i])

    # Step 5: Check if the number is divisible by the sum of its digits
    if int(N) % S == 0:
        print("Yes")
    else:
        print("No")

    # Step 6: Return 0
    return 0
}

