#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    # Declare variables to hold the number of characters and the answer
    n = 0
    ans = 0
    a = ""
    b = ""
    c = ""

    # Read the number of characters and the three strings from input
    n = int(input())
    a = input()
    b = input()
    c = input()

    # Iterate through each character index from 0 to n-1
    for i in range(n):
        # Check if all three characters at index i are the same
        if a[i] == b[i] and b[i] == c[i]:
            # Do nothing, as no points are awarded for identical characters
            pass
        # Check if any two characters are the same
        elif a[i] == b[i] or b[i] == c[i] or a[i] == c[i]:
            # Increment the answer by 1 for matching pairs
            ans += 1
        # If all characters are different
        else:
            # Increment the answer by 2 for all different characters
            ans += 2

    # Output the final answer
    print(ans)

