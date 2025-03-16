package main

import (
    "fmt"
)

func main() {
    var T, S, q int
    // Read the values of T, S, and q from user input
    fmt.Scan(&T, &S, &q)

    // Initialize the variable `previous` with the value of S
    previous := int64(S)

    // Initialize the variable `answer` with the value 0
    answer := 0

    // Enter a loop that continues until `previous` is less than T
    for previous < int64(T) {
        // Inside the loop, multiply `previous` by q and increment the `answer` by 1
        previous *= int64(q)
        answer++
    }

    // After the loop, print the value of `answer`
    fmt.Println(answer)
}

// <END-OF-CODE>
