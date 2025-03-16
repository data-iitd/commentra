
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

  // Read the number of elements in the array P from the standard input
  int N;
  cin >> N;

  // Initialize an integer array P of size N
  vector<int> P(N);

  // Read each element of P from the standard input and store it in the corresponding index of the array
  for (int i = 0; i < N; ++i)
    cin >> P[i];

  // Create an empty HashMap to store the indices of the array P corresponding to each unique element
  map<int, int> map;

  // Iterate through each element of the array P and add its index to the HashMap
  for (int i = 0; i < N; ++i)
    map[P[i]] = i;

  // Create an empty vector to store the indices of the non-decreasing subsequences
  vector<int> nglist;

  // Iterate through each index i of the array P, where i < N - 1
  for (int i = 0; i < N - 1; ++i) {
    // If the index i corresponds to a smaller element than the next index, add its index to the vector
    if (map[P[i]] > map[P[i + 1]])
      nglist.push_back(i);
  }

  // If there are no non-decreasing subsequences, print 0 and exit the program
  if (nglist.empty()) {
    cout << 0 << endl;
    return 0;
  }

  // Calculate the answer by finding the minimum length of a non-decreasing subsequence
  int ans = min(N - nglist[0] - 1, nglist[nglist.size() - 1] + 1);

  // Iterate through each pair of consecutive indices in the vector nglist and update the answer if necessary
  for (int i = 0; i < nglist.size() - 1; ++i) {
    ans = min(nglist[i] + 1 + N - nglist[i + 1] - 1, ans);
  }

  // Print the answer
  cout << ans << endl;

  return 0;
}

