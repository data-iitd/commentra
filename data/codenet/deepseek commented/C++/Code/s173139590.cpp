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

    // Loop through each test case
    for (int i = 0; i < n; ++i){
        string s; // Declare a string variable to store the result of a test case
        cin >> s; // Read the result from the standard input
        if (s == "AC"){ // Check if the result is AC
            ac_count += 1; // Increment the AC count
        } else if (s == "WA"){ // Check if the result is WA
            wa_count += 1; // Increment the WA count
        } else if (s == "TLE"){ // Check if the result is TLE
            tle_count += 1; // Increment the TLE count
        } else if (s == "RE"){ // Check if the result is RE
            re_count += 1; // Increment the RE count
        }
    }

    // Print the counts of each result type
    cout << "AC x " << ac_count << endl;
    cout << "WA x " << wa_count << endl;
    cout << "TLE x " << tle_count << endl;
    cout << "RE x " << re_count << endl;
}
