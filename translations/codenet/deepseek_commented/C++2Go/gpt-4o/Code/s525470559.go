package main // Declare the main package.

import ( // Import necessary packages.
    "fmt" // Import the fmt package for formatted I/O.
    "container/list" // Import the container/list package for using a doubly linked list as a queue.
)

// Define a struct named 'task' to hold the name and time for each task.
type task struct {
    name string // The name of the task.
    time int    // The time required to complete the task.
}

func main() { // The main function is where the program execution begins.
    var n, q int // Declare variables for the number of tasks and the time quantum.
    elaps := 0   // Initialize the elapsed time to 0.
    Q := list.New() // Create a new doubly linked list to use as a queue.

    fmt.Scan(&n, &q) // Read the number of tasks and the time quantum from the standard input.

    for i := 0; i < n; i++ { // Loop to read each task's name and time.
        var tmp task // Create a temporary task object.
        fmt.Scan(&tmp.name, &tmp.time) // Read the task's name and time from the standard input.
        Q.PushBack(tmp) // Push the task into the queue.
    }

    for Q.Len() > 0 { // Process each task in the queue until it is empty.
        front := Q.Front() // Get the front task from the queue.
        p := front.Value.(task) // Type assert the value to task.
        Q.Remove(front) // Remove the front task from the queue.

        if p.time <= q { // Check if the remaining time for the task is less than or equal to the time quantum.
            elaps += p.time // Update the elapsed time by adding the task's remaining time.
            fmt.Println(p.name, elaps) // Print the task's name and the current elapsed time.
        } else { // If the task's remaining time is greater than the time quantum.
            p.time -= q // Reduce the task's remaining time by the time quantum.
            elaps += q // Update the elapsed time by adding the time quantum.
            Q.PushBack(p) // Push the task back into the queue with the remaining time.
        }
    }
}

// <END-OF-CODE>
