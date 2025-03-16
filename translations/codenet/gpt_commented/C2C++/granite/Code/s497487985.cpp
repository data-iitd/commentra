
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Macro definitions for maximum and minimum
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))

// Comparison function for sort to sort integers in descending order
bool compare_int(const int &a, const int &b){
  return a > b; // Sort in descending order
}

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

// Main function
int main(void){
  int n; // Number of participants
  long long int k; // Points required to win
  int q; // Number of questions
  vector<int> a(100001); // Vector to store the questions
  vector<long long int> point(100001, 0); // Vector to track points of each participant

  // Read input values for n, k, and q
  cin >> n >> k >> q;

  /*
  // Initialize points for each participant to k (commented out)
  for(int i = 0; i < n; i++){
    point[i] = k;
  }
  */
  
  /*
  // Check if any participant has less points than k (commented out)
  if(q < k){
    for(int i = 0; i < n; i++){
      cout << "Yes" << endl;
      return 0;
    }
  }
  */
  
  // Process each question and update points for the corresponding participant
  for(int i = 0; i < q; i++){
    cin >> a[i]; // Read the participant number for the question
    point[a[i] - 1]++; // Increment the point for the participant who answered
    /*
    // Update points for other participants (commented out)
    for(int j = 0; j < n; j++){
      if(a[i]!= (j + 1) && point[j] < k){
        point[j]++;
      }
      // cout << "i = " << i << "  point = " << point[j] << endl;
    }
    */
  }

  // Determine if each participant has enough points to win
  for(int i = 0; i < n; i++){
    if(k - (q - point[i]) > 0){ // Check if the participant has enough points
      cout << "Yes" << endl; // Participant can win
    }else{
      cout << "No" << endl; // Participant cannot win
    }
  }

  return 0; // End of the program
}


