#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::gcd

// Define macros for maximum and minimum values
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b){
  if(b == 0){
    return a;
  }else{
    return gcd(b, a % b);
  }
}

// Function to calculate the least common multiple (LCM)
int lcm(int a, int b){
  return a * b / gcd(a, b);
}

// Main function
int main(void){
  int n; // Number of players
  long long k; // Initial points
  int q; // Number of queries
  std::vector<int> a(100001); // Vector to store query results
  std::vector<long long int> point(100001, 0); // Vector to store points for each player

  // Read input values
  std::cin >> n >> k >> q;

  // Process each query to update points
  for(int i = 0; i < q; i++){
    std::cin >> a[i];
    point[a[i] - 1]++; // Update points for the player who answered the query
  }

  // Determine if each player can reach the required points
  for(int i = 0; i < n; i++){
    if(k - (q - point[i]) > 0){
      std::cout << "Yes" << std::endl; // Player can reach the required points
    }else{
      std::cout << "No" << std::endl; // Player cannot reach the required points
    }
  }

  return 0;
}
