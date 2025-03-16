// Read two integers n and m from input
n, m := readInt(), readInt()

// Count the number of '-' characters in the input string
sa := strings.Count(readString(), "-")

// Calculate the minimum of the remaining characters (n - sa) and the count of '-' (sa)
sa = min(n-sa, sa)

// Initialize an empty list to store results
ss := make([]string, 0)

// Loop m times to read pairs of integers a and b
for i := 0; i < m; i++ {
    // Read two integers a and b from input
    a, b := readInt(), readInt()
    
    // Calculate the difference b - a
    b -= a
    
    // Check if b is odd and less than or equal to double the count of '-'
    // Append "1\n" to the results if true, otherwise append "0\n"
    if b%2 == 0 && b <= sa<<1 {
        ss = append(ss, "1\n")
    } else {
        ss = append(ss, "0\n")
    }
}

// Print the concatenated results from the list
fmt.Print(strings.Join(ss, ""))

