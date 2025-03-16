// Read two integers from input: num (number of elements) and k (the divisor)
num, k := 0, 0
fmt.Scanf("%d %d", &num, &k)

// Read the array of integers from input
arr := make([]int, num)
for i := 0; i < num; i++ {
    fmt.Scanf("%d", &arr[i])
}

// Initialize a set to keep track of unique elements that meet the criteria
different := make(map[int]bool)

// Initialize a variable to keep track of the maximum size of the 'different' set
temp := 0

// Sort the array to process elements in ascending order
sort.Ints(arr)

// Iterate through each element in the sorted array
for _, x := range arr {
    // Check if the element is not divisible by k or if its quotient is not already in the 'different' set
    if (x % k!= 0 ||!different[x//k]) {
        // Add the element to the 'different' set since it meets the criteria
        different[x] = true
    }
    
    // Update the maximum size of the 'different' set if the current size is larger
    temp = max(len(different), temp)
}

// Print the maximum size of the 'different' set found
fmt.Println(temp)

