// Read input values for N and K
N, K := strconv.Atoi(bufio.NewReader(os.Stdin).ReadString())
// Read the string S
S := bufio.NewReader(os.Stdin).ReadString()

// Initialize a flag to determine if we can use a shortcut for output
aaaa := false

// Check if K is large enough or if 2^K is greater than or equal to N
if K >= 15 {
    aaaa = true
} else if 2 ** K >= N {
    aaaa = true
}

// If the shortcut condition is met, print the minimum character repeated N times and exit
if aaaa {
    fmt.Printf("%s", string(S[0]) * N)
    return
}

// Function to get the lexicographically smallest rotation of the string
func get_last_dict(s_str string) string {
    // Create a doubled string to facilitate rotation comparison
    U := s_str + s_str[len(s_str)-1:]
    // Find the minimum character in the original string
    c := string(s_str[0])
    // Get the first occurrence of the minimum character
    p := strings.Index(U, c)
    minindex := p
    p += 1
    
    // Iterate through the doubled string to find the smallest rotation
    for p <= N {
        if U[p] == c {
            // Compare the current rotation with the previously found minimum
            if check_normal_dict(U, minindex, p) {
                minindex = p
        }
        p += 1
    
    // Return the smallest rotation of length N
    return U[minindex:minindex + N]
}

// Function to compare two rotations of the string
func check_normal_dict(u string, pointer1 int, pointer2 int) bool {
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
S := get_last_dict(S)

// If K is 1, simply print the smallest rotation
if K == 1 {
    fmt.Printf("%s", S)
} else {
    count := 0
    // Count how many times the first character appears consecutively
    for _, c := range S {
        if c == S[0] {
            count += 1
        } else {
            break
    }
    
    // Check if the repeated character can fill the string of length N
    if count * (2 ** (K - 1)) >= N {
        fmt.Printf("%s", string(S[0]) * N)
    } else {
        // Construct the output string based on the count and the original string
        S = string(S[0]) * (count * ((2 ** (K - 1)) - 1)) + S
        // Print the first N characters of the constructed string
        fmt.Printf("%s", S[0:N])
}

