// Read the number of queries
q := int(input())
// Initialize answers and sums
ans := [2]int{0, 0}
// Initialize two heaps for managing two groups of numbers
p1 := make([]int, 0)
p2 := make([]int, 0)

// Process each query
for _ := 0; _ < q; _++ {
    // Read the query line and convert it to a list of integers
    ql := strings.Split(input(), " ")
    ql = strings.Split(ql[2], "\n")
    ql = strings.Split(ql[0], " ")
    ql = make([]int, len(ql))
    for i := range ql {
        ql[i], _ = strconv.Atoi(ql[i])
    }

    // If the query type is 2, perform a specific operation
    if ql[0] == 2 {
        // If both heaps are of equal length, calculate and print the result based on p2
        if len(p1) == len(p2) {
            fmt.Printf("%d %d\n", -p2[0], ans[0]-len(p1)*-p2[0]+len(p2)*-p2[0]-ans[1]+ans[2])
        } else {
            // If p1 is longer, calculate and print the result based on p1
            fmt.Printf("%d %d\n", p1[0], ans[0]-len(p1)*p1[0]+len(p2)*p1[0]-ans[1]+ans[2])
    } else {
        // If the query type is 1, update the heaps and sums
        ans[2] += ql[2]  // Add the third element of the query to the sum_b

        // If p1 is empty, push the new value into p1
        if len(p1) == 0 {
            heap.Push(p1, ql[1])
            ans[0] += ql[1]
        // If the new value is greater than or equal to the smallest in p1, push it to p1
        } else if p1[0] <= ql[1] {
            heap.Push(p1, ql[1])
            ans[0] += ql[1]
        // Otherwise, push the negative of the new value into p2 (to maintain max-heap behavior)
        } else {
            heap.Push(p2, -ql[1])
            ans[1] += ql[1]

        // Balance the heaps if p1 has fewer elements than p2
        if len(p1) < len(p2) {
            k := heap.Pop(p2).(int)  // Pop the largest from p2
            heap.Push(p1, -k)  // Push it to p1 (as positive)
            ans[1] += k  // Update sum_p2
            ans[0] -= k  // Update sum_p1

        // Balance the heaps if p1 has more than one extra element compared to p2
        if len(p1) - 1 > len(p2) {
            k := heap.Pop(p1).(int)  // Pop the smallest from p1
            heap.Push(p2, -k)  // Push it to p2 (as negative)
            ans[0] -= k  // Update sum_p1
            ans[1] += k  // Update sum_p2
}

