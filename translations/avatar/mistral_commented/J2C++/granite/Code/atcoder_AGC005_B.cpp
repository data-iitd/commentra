

#include <iostream> // Including the necessary header files for input/output operations
#include <queue> // Including the necessary header file for implementing a queue
#include <vector> // Including the necessary header file for using vectors

using namespace std; // Using the standard namespace for simplifying the code

int main() {
  int N; // Declaring the variable to store the number of elements in the array
  cin >> N; // Reading the number of elements in the array from the console

  vector<int> a(N); // Creating a vector to store the elements of the array
  for (int i = 0; i < N; ++i) {
    cin >> a[i]; // Reading the elements of the array from the console and storing them in the vector
  }

  vector<int> leftl(N); // Creating a vector to store the length of the left segment for each element
  vector<int> rightl(N); // Creating a vector to store the length of the right segment for each element
  queue<int> que; // Creating a queue to implement a queue

  int index = 0; // Initializing the index variable to traverse the array

  // Finding the length of the left and right segments for each element using two stacks
  while (index < N) {
    while (!que.empty() && a[que.front()] > a[index]) { // Popping the elements from the queue whose right segment length is to be calculated
      int ind = que.front(); // Storing the index of the popped element
      que.pop(); // Popping the element from the queue
      rightl[ind] = index - ind - 1; // Calculating the length of the right segment for the popped element
    }
    que.push(index++); // Pushing the current index into the queue
  }

  // Calculating the length of the right segment for the last element
  while (!que.empty()) {
    int ind = que.front();
    que.pop();
    rightl[ind] = N - ind - 1;
  }

  index = N - 1; // Initializing the index variable to traverse the array in reverse order

  // Finding the length of the left segments for each element using two stacks in reverse order
  while (index >= 0) {
    while (!que.empty() && a[que.front()] > a[index]) { // Popping the elements from the queue whose left segment length is to be calculated
      int ind = que.front();
      que.pop();
      leftl[ind] = ind - index - 1; // Calculating the length of the left segment for the popped element
    }
    que.push(index--); // Pushing the current index into the queue
  }

  // Calculating the length of the left segment for the first element
  while (!que.empty()) {
    int ind = que.front();
    que.pop();
    leftl[ind] = ind - index - 1;
  }

  long long ans = 0; // Initializing the variable to store the final answer

  // Calculating the answer by multiplying the element, left segment length, and right segment length for each element
  for (int i = 0; i < N; ++i) {
    ans += (long long) a[i] * (leftl[i] + 1) * (rightl[i] + 1);
  }

  // Printing the final answer
  cout << ans << endl; // Printing the final answer

  return 0; // Returning 0 to indicate successful execution of the program
}

