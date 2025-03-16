// Define the input size and initialize an empty list for answers
q := int(input())
ans := [0, 0]

// Import heapq module for priority queue implementation
import "container/heap"

// Initialize empty priority queues for piles p1 and p2
p1 := make([]int, 0)
p2 := make([]int, 0)

// Initialize variables for sums of balls and priority queues
sum_b := 0
sum_p1 := 0
sum_p2 := 0

// Iterate through each query
for i := 0; i < q; i++ {
    ql := make([]int, 3)
    fmt.Scan(&ql[0], &ql[1], &ql[2])

    // Check if the current query is to find the answer
    if ql[0] == 2 {
        // Check if both piles have equal number of balls
        if len(p1) == len(p2) {
            // Calculate the answer and print it
            fmt.Println(-p2[0], sum_p1 - len(p1) * -p2[0] + len(p2) * -p2[0] - sum_p2 + sum_b)
        } else {
            // Calculate the answer and print it
            fmt.Println(p1[0], sum_p1 - len(p1) * p1[0] + len(p2) * p1[0] - sum_p2 + sum_b)
        }

    // Else, the current query is to add balls to a pile
    } else {
        // Add the number of balls to the total sum
        sum_b += ql[2]

        // If pile p1 is empty, add the ball to it
        if len(p1) == 0 {
            heap.Push(&p1, ql[1])
            sum_p1 += ql[1]

        // Else, check if the ball can be added to pile p1
        } else if p1[0] <= ql[1] {
            heap.Push(&p1, ql[1])
            sum_p1 += ql[1]

        // Else, add the ball to pile p2 and adjust the sums accordingly
        } else {
            heap.Push(&p2, -ql[1])
            sum_p2 += ql[1]
            sum_p1 -= ql[1]
            sum_p2 -= ql[1]
        }

        // Adjust the priority queues if necessary
        if len(p1) < len(p2) {
            k := heap.Pop(&p2).(int)
            heap.Push(&p1, -k)
            sum_p2 += k
            sum_p1 -= k
        }
        if len(p1) - 1 > len(p2) {
            k := heap.Pop(&p1).(int)
            heap.Push(&p2, -k)
            sum_p1 -= k
            sum_p2 += k
        }
    }
}

// Print the answer
fmt.Println(ans[0], ans[1])

