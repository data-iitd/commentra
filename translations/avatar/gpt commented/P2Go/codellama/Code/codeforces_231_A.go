// Read an integer input which represents the number of lists to process
n, _ := strconv.Atoi(input())

// Initialize a counter to keep track of lists with a sum greater than 1
c := 0

// Loop through the range of n to process each list
for i := 0; i < n; i++ {
    // Read a line of input, split it into individual string elements, convert them to integers, and store them in a list
    l1 := strings.Split(input(), " ")
    l2 := make([]int, len(l1))
    for j := 0; j < len(l1); j++ {
        l2[j], _ = strconv.Atoi(l1[j])
    }
    
    // Check if the sum of the current list is greater than 1
    if sum(l2) > 1 {
        // Increment the counter if the condition is met
        c++
    }
}

// Print the final count of lists that had a sum greater than 1
fmt.Println(c)

