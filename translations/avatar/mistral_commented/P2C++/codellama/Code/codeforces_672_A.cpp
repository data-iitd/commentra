#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Initialize an empty vector 'li' to store the digits
    vector<int> li;

    // Initialize an index variable 'ind'
    int ind = 0;

    // Iterate through the range from 1 to 370
    for (int i = 1; i <= 370; i++)
    {
        // Initialize an empty vector 'temp' to store digits
        vector<int> temp;

        // Assign current number 'i' to variables p and q
        int p = i, q = i;

        // Initialize a counter 'count' to keep track of number of digits
        int count = 0;

        // While p is not zero, divide it by 10 and increment the counter
        while (p != 0)
        {
            p /= 10;
            count++;
        }

        // Based on the number of digits, append the number or its digits to 'li'
        if (count == 1)
        {
            // If the number has only one digit, directly append it to 'li'
            li.push_back(i);
        }

        else if (count == 2)
        {
            // If the number has two digits, extract its digits and reverse the list
            while (q != 0)
            {
                int x = q % 10;  // Get the last digit
                q /= 10;         // Move to the previous digit
                temp.push_back(x);
            }
            li = li + temp;  // Append the reversed list to 'li'
        }

        else if (count == 3)
        {
            // If the number has three digits, extract its digits and reverse the list
            while (q != 0)
            {
                int x = q % 10;  // Get the last digit
                q /= 10;         // Move to the previous digit
                temp.push_back(x);
            }
            li = li + temp;  // Append the reversed list to 'li'
        }
    }

    // Remove the first two elements from 'li' as they are not required
    li.erase(li.begin());
    li.erase(li.begin());

    // Take an input 'n' from the user
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Print the required digit or digits from 'li' based on the user input
    cout << li[n - 1] << endl;

    return 0;
}

