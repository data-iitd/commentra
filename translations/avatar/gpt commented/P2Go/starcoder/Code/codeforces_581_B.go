// Read the number of elements in the array
n := int(input())

// Read the array elements from input, converting them to integers
arr := make([]int, n)
for i := 0; i < n; i++ {
    arr[i], _ = strconv.Atoi(input())
}

// Initialize an answer array with zeros, which will store the results
ans := make([]int, n)

// Set the maximum value to the last element of the array
mx := arr[n-1]

// Iterate through the array from the second last element to the first
for i := n - 2; i >= 0; i-- {
    // Calculate the required value for ans[i] based on the difference from the maximum
    ans[i] = max(0, mx - arr[i] + 1)
    
    // Update the maximum value if the current element is greater than the current maximum
    if arr[i] > mx {
        mx = arr[i]
}

// Print the result array as space-separated values
for i := 0; i < n; i++ {
    fmt.Printf("%d ", ans[i])
}

// 