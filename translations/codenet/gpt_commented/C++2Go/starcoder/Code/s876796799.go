package main

import (
  "fmt"
  "sort"
  "strings"
)

// Declare an array to hold the input values and an array to store their indices
var a [200000]int64
var ind_a [200000]int

func main() {
  // Read the number of elements
  var N int
  fmt.Scanf("%d\n", &N)

  // Input the elements into array 'a'
  for i := 0; i < N; i++ {
    fmt.Scanf("%d\n", &a[i])
  }

  // Populate 'ind_a' with the indices of the elements in 'a'
  for i := 0; i < N; i++ {
    ind_a[a[i]-1] = i
  }

  // Set to keep track of used indices
  used_inds := make(map[int]bool)
  var ans int64 = 0 // Variable to accumulate the final answer

  // Iterate through each element's index
  for i := 0; i < N; i++ {
    var left_border int64
    var right_border int64
    var cur_ind int = ind_a[i] // Current index of the element being processed

    // Find the first used index that is not less than cur_ind
    left_it := sort.Search(len(used_inds), func(x int) bool {
      return x >= cur_ind
    })
    // Find the first used index that is greater than cur_ind
    right_it := sort.Search(len(used_inds), func(x int) bool {
      return x > cur_ind
    })

    // Determine the left border
    if left_it == 0 {
      left_border = -1
    } else {
      left_border = int64(sort.Search(len(used_inds), func(x int) bool {
        return x >= cur_ind
      }) - 1)
    }

    // Determine the right border
    if right_it == len(used_inds) {
      right_border = int64(N)
    } else {
      right_border = int64(sort.Search(len(used_inds), func(x int) bool {
        return x > cur_ind
      }))
    }

    // Calculate the contribution of the current index to the answer
    ans += (cur_ind - left_border) * (right_border - cur_ind) * (int64(i) + 1)

    // Uncomment the lines below for debugging purposes
    // fmt.Printf("%d %d %d\n", i, left_border, right_border)
    // fmt.Printf("%d\n", ans)

    // Insert the current index into the set of used indices
    used_inds[cur_ind] = true
  }

  // Output the final answer
  fmt.Printf("%d\n", ans)
}

