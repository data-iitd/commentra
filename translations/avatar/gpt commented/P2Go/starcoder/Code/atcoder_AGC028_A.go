// Read the values of N and M from input
N, M := strconv.Atoi(input())

// Read the strings S and T from input
S := input()
T := input()

// Convert strings S and T into lists for easier indexing
list_S := strings.Split(S, "")
list_T := strings.Split(T, "")

// Create a list of indices from 0 to N-1
Number_i := make([]int, N)
for i := 0; i < N; i++ {
    Number_i[i] = i
}

// Initialize an empty list to store calculated indices
Number_iMN := make([]int, 0)

// Calculate the scaled indices based on the ratio of M to N
for i := 0; i < N; i++ {
    Number_iMN = append(Number_iMN, i*M/N)
}

// Create a list of indices from 0 to M-1
Number_j := make([]int, M)
for j := 0; j < M; j++ {
    Number_j[j] = j
}

// Find the common indices between the scaled Number_iMN and Number_j
Kaburi_j := make([]int, 0)
for _, j := range Number_j {
    if j in Number_iMN {
        Kaburi_j = append(Kaburi_j, j)
    }
}

// Initialize an empty list to store the corresponding indices in the original range
Kaburi_i := make([]int, 0)

// Calculate the corresponding indices in the original range based on Kaburi_j
for _, j := range Kaburi_j {
    Kaburi_i = append(Kaburi_i, int(j*N/M))
}

// Initialize a counter for iteration and a flag for mismatch detection
counter := 0
Flag := 0

// Get the size of the Kaburi_i list
Kaburi_Size := len(Kaburi_i)

// Check if the characters at the calculated indices in S and T match
for counter = 0; counter < Kaburi_Size; counter++ {
    if list_S[Kaburi_i[counter]]!= list_T[Kaburi_j[counter]] {
        Flag = 1  // Set flag if a mismatch is found
        break  // Exit the loop on mismatch
    }
}

// Function to calculate the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
    for b > 0 {
        a, b = b, a%b
    }
    return a
}

// Output the result based on the flag indicating if a mismatch was found
if Flag == 1 {
    fmt.Println(-1)  // Print -1 if there was a mismatch
} else {
    // Print the least common multiple (LCM) of N and M
    fmt.Println(N*M/gcd(N, M))
}

