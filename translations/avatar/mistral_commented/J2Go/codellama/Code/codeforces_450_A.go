
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var n, m int
    var q1, q2 []int

    // Reading the first integer n from the standard input
    n, _ = strconv.Atoi(os.Args[1])

    // Reading the second integer m from the standard input
    m, _ = strconv.Atoi(os.Args[2])

    // Creating an empty queue q1 of type Integer using LinkedList implementation
    q1 = make([]int, 0)

    // Creating an empty queue q2 of type Integer using LinkedList implementation
    q2 = make([]int, 0)

    // Iterating through the input values from 1 to n
    for i := 1; i <= n; i++ {
        // Adding the next integer value to the queue q1
        q1 = append(q1, i)

        // Adding the current index value to the queue q2
        q2 = append(q2, i)
    }

    var ans int

    // Starting the while loop to process the queues until both are empty
    for len(q1) > 0 {
        // Checking if the next value in q1 is less than or equal to m
        if q1[0] <= m {
            // Removing the next value from q1
            q1 = q1[1:]

            // Removing the corresponding index value from q2 and assigning it to the answer variable
            ans = q2[0]
            q2 = q2[1:]
        } else if q1[0] > m {
            // Checking if the next value in q1 is greater than m
            // Removing the next value from q1
            x := q1[0]
            q1 = q1[1:]

            // Calculating the new value by subtracting m from the next value
            val := x - m

            // Adding the new value back to the queue q1
            q1 = append(q1, val)

            // Removing the corresponding index value from q2
            val2 := q2[0]
            q2 = q2[1:]

            // Adding the index value back to the queue q2
            q2 = append(q2, val2)
        }
    }

    // Printing the final answer
    fmt.Println(ans)
}

