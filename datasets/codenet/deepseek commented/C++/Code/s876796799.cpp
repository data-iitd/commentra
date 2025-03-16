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

long long a[200000]; // Array to store the elements
int ind_a[200000]; // Array to store the indices of elements in array a

int main(){
  int N;
  cin >> N; // Read the number of elements
  for(int i = 0; i < N; i++){
    cin >> a[i]; // Read the elements into array a
  }
  for(int i = 0; i < N; i++){
    ind_a[a[i] - 1] = i; // Initialize ind_a with the indices of elements in array a
  }

  set <int> used_inds; // Set to keep track of used indices
  long long ans = 0; // Variable to store the final answer
  for(int i = 0; i < N; i++){
    long long left_border; // Variable to store the left boundary
    long long right_border; // Variable to store the right boundary
    long long cur_ind = ind_a[i]; // Current index of the element being processed
    auto left_it = used_inds.lower_bound(cur_ind); // Iterator to the lower bound of cur_ind in used_inds
    auto right_it = used_inds.lower_bound(cur_ind + 1); // Iterator to the lower bound of cur_ind + 1 in used_inds

    if(left_it == used_inds.begin()){
      left_border = -1; // If left_it is the first element, set left_border to -1
    } else {
      if(left_it == used_inds.end() || *left_it > cur_ind){
        left_it --; // Adjust left_it if it points to an element greater than cur_ind
      }
      left_border = *left_it; // Set left_border to the value pointed by left_it
    }
    if(right_it == used_inds.end()){
      right_border = N; // If right_it is the end, set right_border to N
    } else {
      right_border = *right_it; // Set right_border to the value pointed by right_it
    }
    ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1); // Calculate the contribution of the current element to the answer

    // Debugging output (commented out)
    //cout << i << " " << left_border << " " << right_border << endl;
    //cout << ans << endl;

    used_inds.insert(cur_ind); // Insert the current index into the set used_inds
  }

  cout << ans << endl; // Output the final answer
  return 0;
}