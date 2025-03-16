

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println(solve(reader))
}

func solve(reader *bufio.Reader) int {
    // Read the integer N from the input
    N, _ := strconv.Atoi(read(reader))

    // Initialize an array of size N to store the integers
    arr := make([]int, N)

    // Read N integers from the input and store them in the array
    for i := 0; i < N; i++ {
        arr[i], _ = strconv.Atoi(read(reader))
    }

    // Initialize a sum variable to 0
    sum := 0

    // Create a priority queue to store the integers in ascending order
    q := make(PriorityQueue, 0)

    // Iterate through the array and add each element to the priority queue
    for i := 0; i < len(arr); i++ {
        q = append(q, arr[i])
        // Check if the current element is less than or equal to the smallest element in the priority queue
        if arr[i] <= q[0] {
            sum++
        }
    }

    // Return the sum
    return sum
}

type PriorityQueue []int

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
    return pq[i] < pq[j]
}

func (pq PriorityQueue) Swap(i, j int) {
    pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
    item := x.(int)
    *pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
    old := *pq
    n := len(old)
    item := old[n-1]
    *pq = old[0 : n-1]
    return item
}

func read(reader *bufio.Reader) string {
    str, _ := reader.ReadString('\n')
    return strings.TrimSpace(str)
}

