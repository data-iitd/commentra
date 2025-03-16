#include <iostream>
using namespace std;

int main()
{
    // Take the first line as an input
    int firstline;
    cin >> firstline;

    // Initialize total and memory lists
    int total = 0;
    string memory = "";

    // Loop through the given number of lines
    for (int x = 0; x < firstline; x++)
    {
        // Take two integers as input, A and G
        int A, G;
        cin >> A >> G;

        // Check if adding A to the total memory usage is within the limit
        if (total + A <= 500)
        {
            // If yes, add A to the total and append 'A' to the memory list
            total += A;
            memory += "A";
        }
        else
        {
            // If no, subtract G from the total and append 'G' to the memory list
            total -= G;
            memory += "G";
        }
    }

    // Print the final memory state
    cout << memory << endl;

    return 0;
}

