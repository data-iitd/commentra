
#include <bits/stdc++.h> // Importing the standard library
using namespace std; // Using the standard namespace

int main() {
  int N; // Initializing the variable to store the number of elements in the array
  cin >> N; // Reading the number of elements in the array from the console
  int a[N]; // Creating an integer array of size N

  // Reading the elements of the array from the console and storing them in the array
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }

  int leftl[N]; // Creating an integer array of size N to store the length of the left segment for each element
  int rightl[N]; // Creating an integer array of size N to store the length of the right segment for each element
  deque<int> que; // Creating a deque object to implement a double ended queue
  int index = 0; // Initializing the index variable to traverse the array

  // Finding the length of the left and right segments for each element using two stacks
  while (index < N) {
    while (!que.empty() && a[que.back()] > a[index]) { // Popping the elements from the queue whose right segment length is to be calculated
      int ind = que.back(); // Storing the index of the popped element
      rightl[ind] = index - ind - 1; // Calculating the length of the right segment for the popped element
      que.pop_back(); // Popping the element from the queue
    }
    que.push_back(index++); // Pushing the current index into the queue
  }

  // Calculating the length of the right segment for the last element
  while (!que.empty()) {
    int ind = que.back();
    rightl[ind] = N - ind - 1;
    que.pop_back();
  }

  index = N - 1; // Initializing the index variable to traverse the array in reverse order

  // Finding the length of the left segments for each element using two stacks in reverse order
  while (index >= 0) {
    while (!que.empty() && a[que.back()] > a[index]) { // Popping the elements from the queue whose left segment length is to be calculated
      int ind = que.back();
      leftl[ind] = ind - index - 1; // Calculating the length of the left segment for the popped element
      que.pop_back();
    }
    que.push_back(index--); // Pushing the current index into the queue
  }

  // Calculating the length of the left segment for the first element
  while (!que.empty()) {
    int ind = que.back();
    leftl[ind] = ind - index - 1;
    que.pop_back();
  }

  long ans = 0; // Initializing the variable to store the final answer

  // Calculating the answer by multiplying the element, left segment length, and right segment length for each element
  for (int i = 0; i < N; ++i) {
    ans += (long) a[i] * (leftl[i] + 1) * (rightl[i] + 1);
  }

  // Printing the final answer
  cout << ans << endl;
}

