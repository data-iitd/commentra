#######
// Code
#######

// Define input variables
var N, K int
var S string

// Read input from stdin
fmt.Scanf("%d %d\n%s", &N, &K, &S)

// Initialize a flag variable
var aaaa bool

// Check if K is greater than or equal to 15
if K >= 15 {
    // If so, set the flag variable to True
    aaaa = true
}

// Else, check if 2^K is greater than or equal to N
else if 2**K >= N {
    // If so, set the flag variable to True
    aaaa = true
}

// If the flag variable is True, print the result and exit the function
if aaaa {
    fmt.Printf("%s\n", S[:N])
    return
}

// Define a function to get the last dictionary of the string S
func get_last_dict(s_str string) string {
    // Create a new string U by concatenating S with its reverse
    U := s_str + s_str[::-1]
    // Find the minimum character in S
    c := string(min(S))
    // Find the index of the first occurrence of the minimum character in U
    p := strings.Index(U, c)
    // Initialize a variable minindex to store the index of the first occurrence of the minimum character in S
    minindex := p
    // Move the pointer p to the next character in U
    p += 1
    // Check if the substring starting from the current pointer and of length N is a normal dictionary
    for p <= N {
        // If the character at the current pointer in U is the same as the minimum character,
        // and if the substring starting from the current pointer and of length N is a normal dictionary,
        // update the index minindex
        if U[p] == c && check_normal_dict(U, minindex, p) {
            minindex = p
        }
        // Move the pointer p to the next character in U
        p += 1
    }
    // Return the substring starting from minindex and of length N
    return U[minindex:minindex+N]
}

// Define a function to check if a substring is a normal dictionary
func check_normal_dict(u string, pointer1 int, pointer2 int) bool {
    // Iterate through each character in the substring of length N
    for i := 0; i < N; i++ {
        // If the character at pointer1+i in U is greater than the character at pointer2+i,
        // return True (indicating that the substring is a normal dictionary)
        if u[pointer1+i] > u[pointer2+i] {
            return true
        }
        // Else, if the character at pointer1+i is less than the character at pointer2+i,
        // return False (indicating that the substring is not a normal dictionary)
        else if u[pointer1+i] < u[pointer2+i] {
            return false
        }
    }
    // If none of the above conditions are met, return False
    return false
}

// Get the last dictionary of the string S
S = get_last_dict(S)

// If K is equal to 1, print the string S
if K == 1 {
    fmt.Printf("%s\n", S)
}
// Else, check if the number of occurrences of the first character in S is greater than or equal to N/2^(K-1)
else {
    count := 0
    for _, c := range S {
        // If the current character is the same as the first character, increment the count
        if c == S[0] {
            count++
        }
        // Else, break the loop
        else {
            break
        }
    }
    // If the count is greater than or equal to N/2^(K-1), print the string consisting of the first character repeated N times
    if count * (2 ** (K - 1)) >= N {
        fmt.Printf("%s\n", S[0:N])
    }
    // Else, construct the string S by concatenating N-1 instances of the first character with the original string S
    else {
        S = S[0:count*(2**(K-1))-1] + S
        // Print the first N characters of the constructed string S
        fmt.Printf("%s\n", S[:N])
    }
}

