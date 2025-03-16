#include<iostream>
using namespace std;

int main() {
    # Declare an integer variable to store the length of the string
    n = int(input())

    # Read the length of the string from user input
    s = input()

    # Initialize a counter to count the number of distinct segments
    cnt = 0

    # Iterate through each character in the string
    for i in range(n):
        # Increment the counter for each new segment found
        cnt += 1

        # Initialize a variable j to find the end of the current segment
        j = i + 1

        # Continue moving j forward as long as the characters are the same
        for j in range(i + 1, n):
            # If the current character is different from the next character, break the loop
            if s[i] != s[j]:
                break

        # Move i to the end of the current segment
        i = j - 1

    # Output the total count of distinct segments
    print(cnt)

    return 0 # Indicate that the program ended successfully
}
