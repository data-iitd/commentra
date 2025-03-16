
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
  "bufio"
  "fmt"
  "os"
  "strconv"
  "strings"
)

<<<<<<< HEAD
// Function to calculate the cumulative sum of a given array
func cumSum(a []int) []int {
  // Initialize the cumulative sum array 'cum'
  cum := make([]int, len(a))

  // Initialize the cumulative sum to zero
  cum[0] = 0

  // Calculate the cumulative sum
  for i := 1; i < len(a); i++ {
    cum[i] = cum[i - 1] + a[i - 1]
  }

  // Return the cumulative sum
  return cum
}

// Function to calculate the answer
func answer(a []int) int {
  // Initialize the answer to zero
=======
// Function to calculate the cumulative sum of the elements in the array
func calcCumulativeSum(a []int) []int {
  // Initialize a slice 'acc' of size 'len(a)+1' with zero as initial value
  acc := make([]int, len(a)+1)

  // Calculate the cumulative sum of the elements in the array 'a'
  for i := 0; i < len(a); i++ {
    acc[i+1] = acc[i] + a[i]
  }

  // Return the slice 'acc'
  return acc
}

// Function to calculate the answer
func calcAnswer(a []int, acc []int) int {
  // Initialize the answer 'ans' to zero
>>>>>>> 98c87cb78a (data updated)
  ans := 0

  // Calculate the answer using the formula
  for i := 0; i < len(a); i++ {
    // Calculate the contribution of the current element 'a[i]' to the answer
<<<<<<< HEAD
    temp := a[i] * (mod + sum - cum[i])

    // Add the contribution to the answer
    ans += temp

    // Perform modulo operation to keep the value within the range of 'MOD'
    ans %= mod
=======
    temp := (a[i] * (acc[len(a)] - acc[i+1])) % 1000000007

    // Add the contribution to the answer
    ans += temp
>>>>>>> 98c87cb78a (data updated)
  }

  // Return the answer
  return ans
}

<<<<<<< HEAD
// Main function
func main() {
  // Read the number of elements in the array 'a'
  reader := bufio.NewReader(os.Stdin)
  fmt.Fscanln(reader, &n)

  // Initialize a vector 'a' of size 'n'
  a := make([]int, n)

  // Initialize a vector 'cum' of size 'n'
  cum := make([]int, n)

  // Read the elements of the array 'a'
  for i := 0; i < n; i++ {
    fmt.Fscanln(reader, &a[i])
  }

  // Calculate the cumulative sum of the array 'a'
  cum = cumSum(a)

  // Calculate the answer
  ans := answer(a)
=======
// Main function starts here
func main() {
  // Read the number of elements in the array 'a'
  reader := bufio.NewReader(os.Stdin)
  fmt.Fscan(reader, &n)

  // Initialize a slice 'a' of size 'n'
  a := make([]int, n)

  // Read the elements of the array 'a'
  for i := 0; i < n; i++ {
    fmt.Fscan(reader, &a[i])
  }

  // Calculate the cumulative sum of the elements in the array 'a'
  acc := calcCumulativeSum(a)

  // Calculate the answer
  ans := calcAnswer(a, acc)
>>>>>>> 98c87cb78a (data updated)

  // Print the answer
  fmt.Println(ans)
}

