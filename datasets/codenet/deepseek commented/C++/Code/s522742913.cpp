#include <iostream>
#include <string>
#include <cmath>
#include <bitset>

using namespace std;

int main()
{
    // Step 1: Input Handling
    // The program starts by taking a string input from the user.
    string source = "";
    cin >> source;

    // It checks if the length of the input string is within the valid range (1 to 10 characters).
    // If not, it returns -1.
    if(source.length() > 10 || source.length() < 1)
    {
        return -1;
    }

    // Step 2: Calculation Setup
    // The program calculates the maximum number of combinations that can be formed
    // by placing '+' signs between the digits of the input string.
    // This is done using the formula 2^(n-1), where n is the length of the input string.
    int max_i = static_cast<int>(pow(2, source.length() - 1));

    // Step 3: Iterating Over Combinations
    // The program iterates over all possible combinations of placing '+' signs between the digits.
    // For each combination, it calculates the sum of the numbers formed by the substrings separated by '+' signs.
    double sum = 0;

    for (int i = 0; i < max_i; ++i)
    {
        bitset<100> plus(i);

        double number = 0;

        string working = source;
        while(plus.any())
        {
            int i = 0;
            while(!plus[i]) ++i;
            sum += atof(working.substr(0, i + 1).c_str());
            plus >>= i + 1;
            working = working.substr(i + 1);
        }
        sum += atof(working.c_str());
    }

    // Step 4: Output
    // Finally, the program outputs the sum of all possible combinations.
    cout.precision(0);
    cout << fixed << sum << endl;

    return 0;
}
