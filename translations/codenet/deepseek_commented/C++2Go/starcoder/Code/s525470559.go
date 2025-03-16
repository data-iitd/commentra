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

// Define a struct named 'task' to hold the name and time for each task.
type task struct {
    name string
    time int
}

func main() {
    // Declare variables for the number of tasks, the time quantum, and the elapsed time.
    var n, q, elaps int
    // Initialize the elapsed time to 0.
    elaps = 0
    // Declare a queue of tasks.
    var Q []task

    // Read the number of tasks and the time quantum from the standard input.
    fmt.Scanf("%d %d\n", &n, &q)

    // Loop to read each task's name and time.
    for i := 0; i < n; i++ {
        // Create a temporary task object.
        var tmp task
        // Read the task's name and time from the standard input.
        fmt.Scanf("%s %d\n", &tmp.name, &tmp.time)
        // Push the task into the queue.
        Q = append(Q, tmp)
    }

    // Process each task in the queue until it is empty.
    for len(Q) > 0 {
        // Get the front task from the queue and remove it from the queue.
        p := Q[0]
        Q = Q[1:]
        if p.time <= q { // Check if the remaining time for the task is less than or equal to the time quantum.
            elaps += p.time // Update the elapsed time by adding the task's remaining time.
            fmt.Printf("%s %d\n", p.name, elaps) // Print the task's name and the current elapsed time.
        } else { // If the task's remaining time is greater than the time quantum.
            p.time -= q // Reduce the task's remaining time by the time quantum.
            elaps += q  // Update the elapsed time by adding the time quantum.
            Q = append(Q, p) // Push the task back into the queue with the remaining time.
        }
    }
}

