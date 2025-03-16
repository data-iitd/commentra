#include <iostream> // Including the iostream library for input and output
#include <string>   // Including the string library for string manipulation
#include <algorithm> // Including the algorithm library for the max function

using namespace std; // Using the standard namespace

int main() {
    int N, K; // Declaring integers N and K
    cin >> N >> K; // Reading the integers N and K from standard input
    string S; // Declaring a string S
    cin >> S; // Reading the string S from standard input

    string c1 = S; // Copying the string S to c1
    string c3 = S; // Copying the string S to c3

    bool flag1 = false; // Initializing a boolean flag1 to false
    int count1 = 0; // Initializing an integer counter count1 to zero

    // The first for loop is used to process the string c1
    for (int i = 0; i < N; i++) {
        if (flag1 && c1[i] == 'R') { // If flag1 is true and the current character in c1 is 'R'
            flag1 = false; // Setting flag1 to false
            count1++; // Incrementing the counter count1
        }
        if (count1 == K) { // If the counter count1 has reached the value K
            break; // Exiting the for loop
        }
        if (c1[i] == 'L') { // If the current character in c1 is 'L'
            flag1 = true; // Setting flag1 to true
        }
    }

    bool flag3 = false; // Initializing a boolean flag3 to false
    int count3 = 0; // Initializing an integer counter count3 to zero

    // The second for loop is used to process the string c3
    for (int i = 0; i < N; i++) {
        if (flag3 && c3[i] == 'L') { // If flag3 is true and the current character in c3 is 'L'
            flag3 = false; // Setting flag3 to false
            count3++; // Incrementing the counter count3
        }
        if (count3 == K) { // If the counter count3 has reached the value K
            break; // Exiting the for loop
        }
        if (c3[i] == 'R') { // If the current character in c3 is 'R'
            flag3 = true; // Setting flag3 to true
        }
    }

    int count2 = 1; // Initializing an integer counter count2 to one
    int sum1 = 0; // Initializing an integer variable sum1 to zero
    char bef1 = c1[0]; // Assigning the first character in the string c1 to the character variable bef1

    // The third for loop is used to find the length of the longest consecutive identical characters in the string c1
    for (int i = 1; i < N; i++) {
        if (c1[i] == bef1) { // If the current character in c1 is the same as the previous character
            count2++; // Incrementing the counter count2
        } else { // If the current character in c1 is different from the previous character
            sum1 += count2 - 1; // Adding the length of the previous consecutive identical characters to the variable sum1, subtracting one
            count2 = 1; // Resetting the counter count2 to one
            bef1 = c1[i]; // Assigning the current character in c1 to the character variable bef1
        }
    }
    sum1 += count2 - 1; // Adding the length of the last consecutive identical characters to the variable sum1

    int count4 = 1; // Initializing an integer counter count4 to one
    int sum3 = 0; // Initializing an integer variable sum3 to zero
    char bef3 = c3[0]; // Assigning the first character in the string c3 to the character variable bef3

    // The fourth for loop is used to find the length of the longest consecutive identical characters in the string c3
    for (int i = 1; i < N; i++) {
        if (c3[i] == bef3) { // If the current character in c3 is the same as the previous character
            count4++; // Incrementing the counter count4
        } else { // If the current character in c3 is different from the previous character
            sum3 += count4 - 1; // Adding the length of the previous consecutive identical characters to the variable sum3, subtracting one
            count4 = 1; // Resetting the counter count4 to one
            bef3 = c3[i]; // Assigning the current character in c3 to the character variable bef3
        }
    }
    sum3 += count4 - 1; // Adding the length of the last consecutive identical characters to the variable sum3

    cout << max(sum1, sum3) << endl; // Printing the maximum of sum1 and sum3
    return 0; // Returning 0 to indicate successful completion
}

// <END-OF-CODE>
