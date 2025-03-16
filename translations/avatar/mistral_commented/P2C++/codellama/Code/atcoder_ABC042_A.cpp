#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
    // Define a tuple 'ABC' by applying int() function to each element of a list obtained by splitting a user input by space
    tuple<int, int, int> ABC;
    string input;
    getline(cin, input);
    istringstream iss(input);
    vector<int> list;
    int temp;
    while (iss >> temp)
    {
        list.push_back(temp);
    }
    ABC = make_tuple(list[0], list[1], list[2]);

    // Check if the tuple 'ABC' contains exactly 2 occurrences of the integer '5' using the count() method
    if (count(ABC, 5) == 2)
    {
        // If the condition is met, print 'YES' if the sum of all elements in the tuple 'ABC' equals '17'
        if (get<0>(ABC) + get<1>(ABC) + get<2>(ABC) == 17)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        // If the condition is not met, print 'NO'
        cout << "NO" << endl;
    }

    return 0;
}

