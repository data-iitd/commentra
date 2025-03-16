#include <iostream>
#include <string>
using namespace std;

int main(){
    int n; // Declare an integer variable to store the number of test cases
    cin >> n; // Read the value of n from the standard input

    int ac_count = 0; // Initialize an integer variable to count AC submissions
    int wa_count = 0; // Initialize an integer variable to count WA submissions
    int tle_count = 0; // Initialize an integer variable to count TLE submissions
    int re_count = 0; // Initialize an integer variable to count RE submissions

    # Loop through each test case
    for i in range(n):
        s = input() # Read the result from the standard input
        if s == "AC": # Check if the result is AC
            ac_count += 1 # Increment the AC count
        elif s == "WA": # Check if the result is WA
            wa_count += 1 # Increment the WA count
        elif s == "TLE": # Check if the result is TLE
            tle_count += 1 # Increment the TLE count
        elif s == "RE": # Check if the result is RE
            re_count += 1 # Increment the RE count

    # Print the counts of each result type
    print("AC x", ac_count)
    print("WA x", wa_count)
    print("TLE x", tle_count)
    print("RE x", re_count)
}

