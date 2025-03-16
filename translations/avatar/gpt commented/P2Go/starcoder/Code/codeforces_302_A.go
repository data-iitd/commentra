// Read two integers n and m from input
n, m := strconv.Atoi(input())

// Count the number of '-' characters in the input string
sa := strings.Count(input(), "-")

// Calculate the minimum of the remaining characters (n - sa) and the count of '-' (sa)
sa = min(n - sa, sa)

// Initialize an empty list to store results
ss := []string{}

// Loop m times to read pairs of integers a and b
for i := 0; i < m; i++ {
    // Read two integers a and b from input
    a, b := strconv.Atoi(input())
    
    // Calculate the difference b - a
    b -= a
    
    // Check if b is odd and less than or equal to double the count of '-'
    // Append "1\n" to the results if true, otherwise append "0\n"
    ss = append(ss, (b%2 == 1 && b <= sa<<1) && "1\n" || "0\n")
}

// Print the concatenated results from the list
fmt.Print(strings.Join(ss, ""))

