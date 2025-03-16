#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to check if a weight can be carried by a knapsack of capacity 'wei'
bool check(int n, int wei, vector<int> book)
{
  int tmp = wei; // Initialize temporary variable 'tmp' to 'wei'
  n--; // Decrement 'n' (number of items left to be put in the knapsack)

  // Loop through all the items in the vector 'book'
  for (int i = 0; i < book.size(); i++)
  {
    // If the weight of the current item is greater than the remaining capacity,
    // check if there is still room for more items by decrementing 'n' and resetting 'tmp' to 'wei'
    if (tmp < book[i])
    {
      if (n > 0) // If there are still items left to be put in the knapsack
      {
        n--; // Decrement 'n'
        tmp = wei; // Reset 'tmp' to 'wei'
        // Check if the current weight is less than the weight of the current item
        if (tmp < book[i])
          return false;
      }
      else // If there are no more items left to be put in the knapsack
        return false;
    }

    // Subtract the weight of the current item from the remaining capacity
    tmp -= book[i];
  }

  // If all items have been considered and the remaining capacity is still greater than zero,
  // then the given weight can be carried by the knapsack
  return true;
}

int main()
{
  int m, n; // 'm' is the maximum weight the knapsack can carry and 'n' is the number of items

  // Loop through the input until the end of the file is reached
  for (; cin >> m >> n, m;)
  {
    vector<int> book; // Initialize an empty vector 'book' to store the weights of the items

    // Loop through all the items and add their weights to the vector 'book'
    for (int i = 0; i < n; i++)
    {
      int tmp;
      cin >> tmp;
      book.push_back(tmp);
    }

    // Use binary search to find the maximum weight that can be carried by the knapsack
    int l = 0;
    int r = 1500000;
    int ans;
    while (l < r)
    {
      // Calculate the middle value of the range [l, r]
      int mid = (l + r) / 2;

      // If the middle value can be carried by the knapsack, update 'ans' and shrink the range to [l, mid]
      if (check(m, mid, book))
      {
        ans = mid;
        r = mid;
      }
      // If the middle value cannot be carried by the knapsack, shrink the range to [mid+1, r]
      else
      {
        l = mid + 1;
      }
    }

    // Output the maximum weight that can be carried by the knapsack
    cout << ans << endl;
  }

  return 0;
}