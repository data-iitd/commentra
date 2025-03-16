#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
#include <set>
#include <climits>
#include <map>

using namespace std;

// Initialize an array 'a' of size N and an array 'ind_a' of size N
long long a[200000];
int ind_a[200000];

int main(){
  int N; // Read the number of elements N from the standard input
  cin >> N;

  // Read N elements from the standard input and store them in the array 'a'
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }

  // Initialize an empty set 'used_inds' to keep track of indices already used
  set <int> used_inds;

  long long ans = 0; // Initialize an answer variable 'ans' to 0

  // Iterate through each index i from 0 to N-1
  for(int i = 0; i < N; i++){
    long long left_border; // Initialize variables 'left_border' and 'right_border' to store the indices of the left and right neighbors of the current index i, respectively
    long long right_border;

    long long cur_ind = ind_a[i]; // Get the index of the current element a[i] in the array 'ind_a'

    // Find the index of the left neighbor of the current index i in the set 'used_inds'
    auto left_it = used_inds.lower_bound(cur_ind);

    // If the left neighbor does not exist, set 'left_border' to -1
    if(left_it == used_inds.begin()){
      left_border = -1;
    } else {
      // If the left neighbor exists and its index is greater than the current index i, move the iterator left to find the index of the actual left neighbor
      if(left_it == used_inds.end() || *left_it > cur_ind){
        left_it--;
      }
      left_border = *left_it;
    }

    // Find the index of the right neighbor of the current index i in the set 'used_inds'
    auto right_it = used_inds.lower_bound(cur_ind + 1);

    // If the right neighbor does not exist, set 'right_border' to N (the total number of elements)
    if(right_it == used_inds.end()){
      right_border = N;
    } else {
      right_border = *right_it;
    }

    // Calculate the contribution of the current index i to the answer 'ans'
    ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1);

    // Insert the index of the current element a[i] into the set 'used_inds'
    used_inds.insert(cur_ind);

    // Uncomment the following lines to print the values of i, left_border, right_border, and ans for debugging purposes
    // cout << i << " " << left_border << " " << right_border << endl;
    // cout << ans << endl;
  }

  // Print the final answer 'ans' to the standard output
  cout << ans << endl;

  // Return 0 to indicate successful execution of the program
  return 0;
}
