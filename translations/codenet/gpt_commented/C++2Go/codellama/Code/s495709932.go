// Optimize input/output operations
// #include <algorithm>
// #include <iostream>
// #include <vector>
// #define rep(i, n) for (int i = 0; i < (n); i++)
// using namespace std;

// int main(void) {
//   // Read the number of elements in the array
//   var N int
//   fmt.Scan(&N)

//   // Initialize a vector to store the elements
//   var A []int64
//   A = make([]int64, N)

//   // Read the elements into the vector
//   rep(i, N) fmt.Scan(&A[i])

//   // Initialize a variable to keep track of the maximum difference
//   var answer int64

//   // Iterate through all pairs of elements to find the maximum difference
//   for i := 0; i < N - 1; i++ {
//     for j := i + 1; j < N; j++ {
//       // Calculate the absolute difference between the two elements
//       diff := int64(math.Abs(float64(A[i] - A[j])))

//       // Update the maximum difference found so far
//       answer = max(answer, diff)
//     }
//   }

//   // Output the maximum difference
//   fmt.Println(answer)

//   return 0
// }

// 