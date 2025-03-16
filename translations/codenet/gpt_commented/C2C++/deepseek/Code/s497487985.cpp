#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::gcd in C++17 and later

// Macro definitions for maximum and minimum
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))

// Function to calculate the greatest common divisor (GCD) using recursion
int gcd(int a, int b){
  if(b == 0){
    return a; // Base case: if b is 0, return a
  }else{
    return gcd(b, a % b); // Recursive case
  }
}

// Function to calculate the least common multiple (LCM) using GCD
int lcm(int a, int b){
  return a * b / gcd(a, b); // LCM formula
}

int main() {
  int n; // Number of participants
  long long k; // Points required to win
  int q; // Number of questions
  std::vector<int> a(100001); // Array to store the questions
  std::vector<long long> point(100001, 0); // Array to track points of each participant

  // Read input values for n, k, and q
  std::cin >> n >> k >> q;

  // Process each question and update points for the corresponding participant
  for(int i = 0; i < q; i++){
    std::cin >> a[i]; // Read the participant number for the question
    point[a[i] - 1]++; // Increment the point for the participant who answered
  }

  // Determine if each participant has enough points to win
  for(int i = 0; i < n; i++){
    if(k - (q - point[i]) > 0){ // Check if the participant has enough points
      std::cout << "Yes" << std::endl; // Participant can win
    }else{
      std::cout << "No" << std::endl; // Participant cannot win
    }
  }

  return 0; // End of the program
}
