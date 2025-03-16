
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

// Global variables
var (
    n, q int
    Q    [100005]P
)

// Structures
type P struct {
    name string
    t    int
}

// Function to add a process to the queue
func enqueue(x P) {
    Q[tail] = x
    tail = (tail + 1) % 100005
}

// Function to remove a process from the queue
func dequeue() P {
    x := Q[head]
    head = (head + 1) % 100005
    return x
}

// Function to find the minimum of two integers
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func main() {
    var (
        elaps int
        c     int
        u     P
    )

    fmt.Scanf("%d %d\n", &n, &q)

    for i := 1; i <= n; i++ {
        fmt.Scanf("%s\n", &Q[i].name)
        fmt.Scanf("%d\n", &Q[i].t)
        enqueue(Q[i])
    }
    head = 1
    tail = n + 1

    for head!= tail {
        u = dequeue()
        c = min(q, u.t)
        u.t -= c
        elaps += c
        if u.t > 0 {
            enqueue(u)
        } else {
            fmt.Printf("%s %d\n", u.name, elaps)
        }
    }
}

