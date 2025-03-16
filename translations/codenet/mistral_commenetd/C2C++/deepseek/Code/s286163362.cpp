#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> data(111111, 0); // Initialize a vector 'data' of size 111111 for storing the frequency of each number.
vector<int> seq(222222, 0); // Initialize a vector 'seq' of size 222222 for storing the sequence numbers.

int max(int a, int b); // Declare a function 'max' that returns the maximum of two integers.

int main()
{
  int n, k, t, i, p, ret = 0; // Declare variables 'n' and 'k' for the number of elements and the size of the sequence, 't' as a temporary variable, 'i' as a loop counter, 'p' as a pointer, and 'ret' as the result.

  while (true) { // Start an infinite loop.

    cin >> n >> k; // Read the number of elements 'n' and the size of the sequence 'k' from the standard input.
    if (n == 0 && k == 0) break; // If both 'n' and 'k' are zero, break the loop.

    fill(data.begin(), data.end(), 0); // Initialize all elements of the 'data' vector to zero using the 'fill' function.
    fill(seq.begin(), seq.end(), 0); // Initialize all elements of the 'seq' vector to zero using the 'fill' function.

    for (i = 0; i < k; i++) { // Loop through each number in the sequence.
      cin >> t; // Read a number 't' from the standard input.
      data[t]++; // Increment the frequency of the number 't' in the 'data' vector.
    }

    p = 0; // Initialize a pointer 'p' to the first element of the 'seq' vector.
    for (i = 1; i <= n; i++) { // Loop through each number from 1 to 'n'.
      if (data[i] > 0) { // If the frequency of the number 'i' is not zero, increment the corresponding element in the 'seq' vector.
	seq[p]++;
      } else { // If the frequency of the number 'i' is zero, move the pointer 'p' to the next even index.
	p += 2;
      }
    }
    p++; // Increment the pointer 'p' to the next index.

    if (data[0] > 0) { // If the frequency of the number 0 is not zero, calculate the maximum sum of consecutive sequences in the 'seq' vector.
      for (i = 0; i < p; i++) {
	ret = max(ret, seq[i] + seq[i + 2] + 1); // Calculate the sum of the current and next sequence and update the maximum sum if necessary.
      }
    } else { // If the frequency of the number 0 is zero, calculate the maximum sum of sequences in the 'seq' vector.
      for (i = 0; i < p; i++) {
	ret = max(ret, seq[i]); // Calculate the sum of the current sequence and update the maximum sum if necessary.
      }
    }

    cout << ret << endl; // Print the maximum sum of sequences to the standard output.
  }

  return 0; // Return 0 to indicate successful execution of the program.
}

int max(int a, int b) // The 'max' function remains the same.
{
  if (a > b) { // If 'a' is greater than 'b', return 'a' as the maximum.
    return a;
  }
  return b; // Otherwise, return 'b' as the maximum.
}

