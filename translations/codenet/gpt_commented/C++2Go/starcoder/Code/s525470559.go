package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Define a structure to represent a task with a name and time
type task struct {
    name string
    time int
}

func main() {
    var n, q int
    var elaps int
    var Q []task

    // Read the number of tasks and the time quantum from input
    fmt.Scanf("%d %d\n", &n, &q)

    // Read each task's name and time, and add it to the queue
    for i := 0; i < n; i++ {
        var tmp task
        fmt.Scanf("%s %d\n", &tmp.name, &tmp.time)
        Q = append(Q, tmp)
    }

    // Process tasks until the queue is empty
    for len(Q) > 0 {
        p := Q[0] // Get the task at the front of the queue
        Q = Q[1:] // Remove the task from the queue

        // Check if the task can be completed within the time quantum
        if p.time <= q {
            elaps += p.time // Update elapsed time
            fmt.Printf("%s %d\n", p.name, elaps) // Output task name and total elapsed time
        } else {
            // If the task cannot be completed, reduce its time and re-add it to the queue
            p.time -= q // Decrease the remaining time of the task
            elaps += q // Update elapsed time by the time quantum
            Q = append(Q, p) // Re-add the task to the queue for further processing
        }
    }
}

