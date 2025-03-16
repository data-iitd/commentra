// Read the main string from user input
s := bufio.NewReader(os.Stdin).ReadString('\n')

// Read the number of subsequent strings to process
n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadString('\n'))

// Initialize the answer variable to accumulate results
ans := 0

// Loop through each of the n strings provided by the user
for i := 0; i < n; i++ {
    // Read the current string
    x, _ := bufio.NewReader(os.Stdin).ReadString('\n')
    
    // Initialize counters for characters matching the first and second characters of x
    a, b := 0, 0
    
    // Loop through each character in the main string s
    for _, j := range s {
        // If the character matches the first character of x, increment counter a
        if j == x[0] {
            a++
        }
        // If the character matches the second character of x, increment counter b
        if j == x[1] {
            b++
        }
    }
    
    // After finishing the loop, add the minimum of a and b to ans for the last segment
    ans += min(a, b)
}

// Print the final accumulated answer
fmt.Println(ans)

