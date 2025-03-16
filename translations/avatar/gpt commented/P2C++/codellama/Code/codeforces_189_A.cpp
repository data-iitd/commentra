#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // Read input and convert it into a list of integers
    int length, arr[3];
    cin >> length >> arr[0] >> arr[1] >> arr[2];
    
    // Sort the next three elements (the lengths of the pieces) in ascending order
    sort(arr, arr + 3);
    
    // If the total length is divisible by the smallest piece length, print the maximum number of pieces
    if (length % arr[0] == 0)
    {
        cout << length / arr[0] << endl;
        return 0;
    }
    
    // Initialize the answer variable to keep track of the maximum pieces
    int ans = 0;
    
    // Case when the two smallest piece lengths are equal
    if (arr[0] == arr[1])
    {
        int k = 0;
        // Iterate through the number of the largest pieces that can fit into the ribbon
        for (int i = 0; i <= length / arr[2]; i++)
        {
            // Calculate the remaining length after using i pieces of the largest size
            int check = length - i * arr[2];
            // Check if the remaining length can be completely divided by the smallest piece length
            if (check >= 0 && check % arr[0] == 0)
            {
                k = check / arr[0];
                // Update the maximum pieces found
                ans = max(ans, k + i);
            }
        }
    }
    else
    {
        // Case when the two smallest piece lengths are different
        int k = 0;
        // Iterate through the number of the largest pieces that can fit into the ribbon
        for (int i = 0; i <= length / arr[2]; i++)
        {
            // Iterate through the number of the second largest pieces that can fit into the ribbon
            for (int j = 0; j <= length / arr[1]; j++)
            {
                // Calculate the remaining length after using i pieces of the largest size and j pieces of the second largest size
                int check = length - i * arr[2] - j * arr[1];
                // Check if the remaining length can be completely divided by the smallest piece length
                if (check >= 0 && check % arr[0] == 0)
                {
                    k = check / arr[0];
                    // Update the maximum pieces found
                    ans = max(ans, k + i + j);
                }
            }
        }
    }
    
    // Print the maximum number of pieces that can be obtained
    cout << ans << endl;
    return 0;
}

