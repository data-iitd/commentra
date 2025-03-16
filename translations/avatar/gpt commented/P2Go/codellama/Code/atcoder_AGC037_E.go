// Read input values for N and K
N, K := readInts()
// Read the string S
S := readString()

// Initialize a flag to determine if we can use a shortcut for output
aaaa := false

// Check if K is large enough or if 2^K is greater than or equal to N
if K >= 15 {
    aaaa = true
} else if 1 << K >= N {
    aaaa = true
}

// If the shortcut condition is met, print the minimum character repeated N times and exit
if aaaa {
    fmt.Println(min(S) * N)
    os.Exit(0)
}

// Function to get the lexicographically smallest rotation of the string
func getLastDict(s_str string) string {
    // Create a doubled string to facilitate rotation comparison
    U := s_str + reverse(s_str)
    // Find the minimum character in the original string
    c := min(s_str)
    // Get the first occurrence of the minimum character
    p := strings.Index(U, c)
    minindex := p
    p += 1
    
    // Iterate through the doubled string to find the smallest rotation
    for p <= N {
        if U[p] == c {
            // Compare the current rotation with the previously found minimum
            if checkNormalDict(U, minindex, p) {
                minindex = p
            }
        }
        p += 1
    }
    
    // Return the smallest rotation of length N
    return U[minindex:minindex + N]
}

// Function to compare two rotations of the string
func checkNormalDict(u string, pointer1, pointer2 int) bool {
    // Compare characters of the two rotations
    for i := 0; i < N; i++ {
        if u[pointer1 + i] > u[pointer2 + i] {
            return true
        } else if u[pointer1 + i] < u[pointer2 + i] {
            return false
        }
    }
    return false
}

// Get the lexicographically smallest rotation of S
S = getLastDict(S)

// If K is 1, simply print the smallest rotation
if K == 1 {
    fmt.Println(S)
} else {
    count := 0
    // Count how many times the first character appears consecutively
    for _, c := range S {
        if c == S[0] {
            count += 1
        } else {
            break
        }
    }
    
    // Check if the repeated character can fill the string of length N
    if count * (1 << (K - 1)) >= N {
        fmt.Println(S[0] * N)
    } else {
        // Construct the output string based on the count and the original string
        S = S[0] * (count * ((1 << (K - 1)) - 1)) + S
        // Print the first N characters of the constructed string
        fmt.Println(S[0:N])
    }
}

