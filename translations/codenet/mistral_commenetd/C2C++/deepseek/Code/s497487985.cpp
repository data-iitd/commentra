#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::gcd

#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))

// Function to find the greatest common divisor (GCD) of two integers
int gcd(int a, int b){
  if(b == 0){
    // If 'b' is 0, then 'a' is the GCD
    return a;
  }else{
    // Otherwise, recursively call the function with 'b' and the remainder of 'a' divided by 'b'
    return gcd(b, a % b);
  }
}

// Function to find the least common multiple (LCM) of two integers
int lcm(int a, int b){
  // The LCM is the product of the two numbers divided by their GCD
  return a * b / gcd(a, b);
}

int main(void){
  int n; // Number of people
  long long k; // Total points
  int q; // Number of queries
  std::vector<int> a(100001); // Array to store the query numbers
  std::vector<long long int> point(100001, 0); // Array to store the current points for each person

  // Read input values
  std::cin >> n >> k >> q;

  // Distribute the points to each query one by one
  for(int i = 0; i < q; i++){
    std::cin >> a[i]; // Read the query number
    point[a[i] - 1]++; // Increase the points for the person with the query number
  }

  // Check if it's possible to distribute the remaining points to the remaining people
  for(int i = 0; i < n; i++){
    if(k - (q - point[i]) > 0){ // If the remaining points are greater than the difference between the total points and the points already distributed
      std::cout << "Yes" << std::endl; // It's possible to distribute the remaining points to the remaining people
    }else{
      std::cout << "No" << std::endl; // It's impossible to distribute the remaining points to the remaining people
    }
  }

  return 0;
}
