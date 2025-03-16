#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Take the number of elements in the list as input
    int n;
    cin >> n;

    // Initialize an empty vector 'arr' to store the input elements
    vector<int> arr;

    // Iterate through the input elements and add them to the vector
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    // Check if the first element of the vector is greater than 15
    if (arr[0] > 15)
    {
        // If it is, print 15
        cout << 15 << endl;
    }
    else
    {
        // Else, iterate through the vector starting from the second element
        for (int i = 1; i < arr.size(); i++)
        {
            // Check if the difference between the current and previous elements is greater than 15
            if (arr[i] - arr[i-1] > 15)
            {
                // If it is, print the index of the previous element and add 15 to it
                cout << arr[i-1] + 15 << endl;
                // Break the loop as we have found the answer
                break;
            }
        }
        // Else, if we reach here, it means that no difference was greater than 15
        if (arr.back() == 90 || arr.back() + 15 >= 90)
        {
            // If it is, print 90
            cout << 90 << endl;
        }
        else
        {
            // Else, print the last element plus 15
            cout << arr.back() + 15 << endl;
        }
    }

    return 0;
}

