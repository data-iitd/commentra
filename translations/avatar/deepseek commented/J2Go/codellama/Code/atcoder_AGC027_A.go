
package main

import (
    "fmt"
    "sort"
)

func main() {
    // Step 1: Read an integer N and a long integer x from the standard input
    var N int
    var x int64
    fmt.Scan(&N, &x)

    // Step 2: Read N long integers and store them in a list called sweet
    sweet := make([]int64, N)
    for i := 0; i < N; i++ {
        fmt.Scan(&sweet[i])
    }

    // Step 3: Sort the list sweet
    sort.Slice(sweet, func(i, j int) bool {
        return sweet[i] < sweet[j]
    })

    // Step 4: Initialize a counter num to 0 and iterate through the sorted list sweet
    num := 0
    for i := 0; i < N; i++ {
        // Step 5: Check if subtracting the element from x results in a non-negative value
        if x-sweet[num] >= 0 {
            // Step 6: Subtract the element from x and increment the counter num
            x = x - sweet[num]
            num++
        } else {
            // Step 7: Break out of the loop if the condition is not met
            break
        }
    }

    // Step 8: After the loop, if num equals N and x is greater than 0, decrement num by 1
    if num == N && x > 0 {
        num--
    }

    // Step 9: Print the value of num
    fmt.Println(num)
}

