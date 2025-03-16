
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Define macros for maximum and minimum values
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))

// Function to compare integers in descending order
bool compare_int(const void *a, const void *b){
  return *(long int*)b - *(long int*)a; // 大きい順
}

// Function to calculate the greatest common divisor (GCD)
long long int gcd(long long int a, long long int b){
  if(b == 0){
    return a;
  }else{
    return gcd(b, a % b);
  }
}

// Function to calculate the least common multiple (LCM)
long long int lcm(long long int a, long long int b){
  return a * b / gcd(a, b);
}

// Main function
int main(void){
  long long int n; // Number of players
  long long int k; // Initial points
  long long int q; // Number of queries
  vector<long long int> a(100001); // Vector to store query results
  vector<long long int> point(100001, 0); // Vector to store points for each player

  // Read input values
  cin >> n >> k >> q;

  // Process each query to update points
  for(long long int i = 0; i < q; i++){
    cin >> a[i];
    point[a[i] - 1]++; // Update points for the player who answered the query
  }

  // Determine if each player can reach the required points
  for(long long int i = 0; i < n; i++){
    if(k - (q - point[i]) > 0){
      cout << "Yes" << endl; // Player can reach the required points
    }else{
      cout << "No" << endl; // Player cannot reach the required points
    }
  }

  return 0;
}


