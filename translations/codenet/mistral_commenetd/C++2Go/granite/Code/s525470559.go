
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

type task struct {
    name string
    time int
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    var n, q int
    var elaps int
    var Q []task

    // Read number of tasks and queries from standard input
    fmt.Fscanf(reader, "%d %d\n", &n, &q)

    // Read tasks details and add them to the queue
    for i := 0; i < n; i++ {
        var tmp task
        fmt.Fscanf(reader, "%s %d\n", &tmp.name, &tmp.time)
        Q = append(Q, tmp)
    }

    // Process tasks in the queue until it is empty
    for len(Q) > 0 {
        p := Q[0]
        Q = Q[1:] // Remove the task at the front of the queue

        // Check if the current task can be completed within the given query time
        if p.time <= q {
            elaps += p.time // Add the time taken by the task to the elapsed time
            fmt.Printf("%s %d\n", p.name, elaps) // Print the name and elapsed time of the task
        } else { // If the current task cannot be completed within the given query time
            // Subtract the query time from the time taken by the task
            p.time -= q
            // Add the task back to the queue with updated time
            Q = append(Q, p)
        }
    }
}

