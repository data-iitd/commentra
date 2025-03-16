package main

import "fmt"

var A [1000000]int
var n int

/* 
 * binarySearch function performs a binary search on the array A to find a given key.
 * It returns 1 if the key is found, otherwise it returns 0.
 */
func binarySearch(key int) int {
  left := 0
  right := n
  var mid int
  for left < right {
    mid = (left + right) / 2
    if key == A[mid] {
      return 1
    }
    if key > A[mid] {
      left = mid + 1
    } else if key < A[mid] {
      right = mid
    }
  }
  return 0
}

/* 
 * main function is the entry point of the program.
 * It reads the size of the array and the elements of the array from the user.
 * It then reads the number of queries and performs binary search for each query.
 * Finally, it prints the number of elements found.
 */
func main() {
  var i, q, k, sum int
  fmt.Scan(&n)
  for i = 0; i < n; i++ {
    fmt.Scan(&A[i])
  }
  fmt.Scan(&q)
  for i = 0; i < q; i++ {
    fmt.Scan(&k)
    if binarySearch(k) == 1 {
      sum++
    }
  }
  fmt.Println(sum)
}

