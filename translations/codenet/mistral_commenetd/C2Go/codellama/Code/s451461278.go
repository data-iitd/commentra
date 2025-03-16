#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

// Function declarations
func Partition(C []string, A []int, p, r int) int {

  var i, j int // Variables declaration
  var tmpC string // Variables declaration
  var tmpN int // Variables declaration

  // Set the pivot element as the last element of the array
  x := C[r]
  y := A[r]

  // Set the initial index of the left partition as p - 1
  i = p - 1

  // Iterate through the array from p to r - 1
  for j = p; j < r; j++ {
    // If the current element is smaller than the pivot, increment i and swap the elements
    if A[j] <= y {
      i = i + 1
      tmpN = A[j]
      tmpC = C[j]
      A[j] = A[i]
      C[j] = C[i]
      A[i] = tmpN
      C[i] = tmpC
    }
  }

  // Swap the pivot element with the element at index i + 1
  tmpN = A[i+1]
  tmpC = C[i + 1]
  A[i+1] = A[r]
  C[i+1] = C[r]
  A[r] = tmpN
  C[r] = tmpC

  // Return the index of the pivot element
  return i+1
}

// Quicksort function
func Quicksort(C []string, A []int, p, r int) {

  // Base case: if p is less than r, recursively call Partition and Quicksort functions
  if p < r {
    q := Partition(C, A, p, r)
    Quicksort(C, A, p, q-1)
    Quicksort(C, A, q+1, r)
  }
}

// Merge function for merge sort
func Merge(MC []string, MN []int, left, mid, right int) {

  n1 := mid - left + 1 // Calculate the size of the left partition
  n2 := right - mid // Calculate the size of the right partition
  LN := make([]int, n1 + 1) // Dynamically allocate memory for the left partition of integers
  RN := make([]int, n2 + 1) // Dynamically allocate memory for the right partition of integers
  LC := make([]string, n1 + 1) // Dynamically allocate memory for the left partition of characters
  RC := make([]string, n2 + 1) // Dynamically allocate memory for the right partition of characters

  // Copy the left partition to LN and LC arrays
  for i := 1; i <= n1; i++ {
    LN[i] = MN[left + i - 1]
    LC[i] = MC[left + i - 1]
  }

  // Copy the right partition to RN and RC arrays
  for i := 1; i <= n2; i++ {
    RN[i] = MN[mid + i]
    RC[i] = MC[mid + i]
  }

  // Set the sentinel values for LN and RN arrays
  LN[n1+1] = 1000000000
  RN[n2+1] = 1000000000

  // Merge the left and right partitions into the original arrays
  i := 1
  j := 1
  k := left
  for i <= n1 && j <= n2 {
    if LN[i] <= RN[j] {
      MN[k] = LN[i]
      MC[k] = LC[i]
      i++
    } else {
      MN[k] = RN[j]
      MC[k] = RC[j]
      j++
    }
    k++
  }

  // Free the dynamically allocated memory
  LN = nil
  RN = nil
  LC = nil
  RC = nil
}

// Merge sort function
func Merge_Sort(MC []string, MN []int, left, right int) {
    var mid int // Variable declaration

    // Base case: if left is less than right, recursively call Merge_Sort and Merge functions
    if left < right {
        mid = (left + right) / 2
        Merge_Sort(MC, MN, left, mid)
        Merge_Sort(MC, MN, mid+1, right)
        Merge(MC, MN, left, mid, right)
    }
}

// Main function
func main() {

  var A []int // Dynamically allocated array for integers A
  var C []string // Dynamically allocated array for characters C
  var MC []string // Dynamically allocated array for characters MC (Modified C)
  var MN []int // Dynamically allocated array for integers MN (Modified N)

  var i, p, n int // Variables declaration and initialization
  var count int = 0

  fmt.Scan(&n) // Read the number of elements n

  // Read characters and integers from the standard input
  for i := 1; i <= n; i++ {
    fmt.Scan(&C[i], &A[i])
  }

  // Copy characters and integers from A to MC and MN respectively
  for i := 1; i <= n; i++ {
    MC[i] = C[i]
    MN[i] = A[i]
  }

  // Merge sort on MC and MN arrays
  Merge_Sort(MC, MN, 1, n)

  // Quick sort on C and A arrays
  p = 1
  Quicksort(C, A, p, n)

  // Check if the arrays are equal after sorting
  for i := 1; i <= n; i++ {
    if MN[i] == A[i] && MC[i] == C[i] {
      count++
    }
  }

  // Print the result
  if count == n {
    fmt.Println("Stable")
  } else {
    fmt.Println("Not stable")
  }

  // Print the sorted arrays
  for i := 1; i <= n; i++ {
    fmt.Println(C[i], A[i])
  }
}

