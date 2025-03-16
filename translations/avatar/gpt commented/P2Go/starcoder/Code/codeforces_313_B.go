// Read the input string from the user
soz := bufio.NewReader(os.Stdin).ReadString('\n')

// Initialize a list 'a' to store the cumulative count of consecutive characters
// The length of 'a' is one more than the length of'soz' to handle the base case
a := make([]int, len(soz) + 1)

// Iterate through the string to fill the cumulative count array 'a'
for i := 1; i < len(soz); i++ {
    // Carry forward the previous count
    a[i] = a[i - 1]
    
    // If the current character is the same as the previous one, increment the count
    if soz[i - 1] == soz[i] {
        a[i] += 1
}

// Read the number of queries from the user
n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadString('\n'))

// Initialize an empty list to store the results of each query
arr := make([]int, n)

// Process each query
for i := 0; i < n; i++ {
    // Read the start and end indices for the query
    m, l := bufio.NewReader(os.Stdin).ReadString('\n')
    
    // Calculate the number of consecutive characters between indices m and l
    // and append the result to the 'arr' list
    arr[i] = a[int(l) - 1] - a[int(m) - 1]
}

// Print the results for each query
for i := 0; i < n; i++ {
    fmt.Println(arr[i])
}

