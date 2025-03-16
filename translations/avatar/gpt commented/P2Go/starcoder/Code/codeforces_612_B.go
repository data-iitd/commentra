// Read the number of elements
n := int(input())

// Read the elements into a list and convert them to integers
a := make([]int, n)
for i := 0; i < n; i++ {
    a[i], _ = strconv.Atoi(input())
}

// Initialize a list 'b' with zeros to store the positions of elements
b := make([]int, n)

// Populate the list 'b' with the indices of elements from list 'a'
for i := 0; i < n; i++ {
    b[a[i]-1] = i
}

// Initialize the result variable to accumulate the total distance
res := 0

// Calculate the total distance between consecutive elements in 'b'
for i := 1; i < n; i++ {
    res += abs(b[i] - b[i-1])
}

// Print the final result
fmt.Println(res)

