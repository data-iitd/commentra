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

// Define the heap array and its size
var heap []int
var sz int

// Function to insert a new element into the heap
func push(x int) {
    i := sz
    sz++
    // Bubble up the new element to its correct position
    for i > 0 {
        p := (i - 1) / 2
        if heap[p] >= x {
            break
        }
        heap[i] = heap[p]
        i = p
    }
    heap[i] = x
}

// Function to remove and return the maximum element from the heap
func pop() int {
    ret := heap[0]
    x := heap[sz-1]
    sz--
    i := 0
    // Bubble down the new root to its correct position
    for i*2+1 < sz {
        a := i*2 + 1
        b := i*2 + 2
        if b < sz && heap[b] > heap[a] {
            a = b
        }
        if heap[a] <= x {
            break
        }
        heap[i] = heap[a]
        i = a
    }
    heap[i] = x
    return ret
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, m, i, j := 0, 0, 0, 0
    var a []int
    fmt.Fscan(reader, &n, &m)
    for i = 0; i < n; i++ {
        var x int
        fmt.Fscan(reader, &x)
        a = append(a, x)
    }
    for i = 0; i < n; i++ {
        push(a[i])
    }
    for i = 0; i < m; i++ {
        tm := pop()
        tm /= 2
        push(tm)
    }
    ans := 0
    for i = 0; i < n; i++ {
        ans += heap[i]
    }
<<<<<<< HEAD
    fmt.Println(ans)
=======
    fmt.Fprintln(os.Stdout, ans)
>>>>>>> 98c87cb78a (data updated)
}

