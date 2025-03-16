#######
# Code
#######

// Define input variables N and M as integers
var N, M int
fmt.Scanf("%d %d", &N, &M)

// Comments: Get the dimensions N and M of the matrices S and T from user input

// Initialize variables S and T as strings
var S, T string
fmt.Scanf("%s", &S)
fmt.Scanf("%s", &T)

// Convert strings S and T into lists
list_S := strings.Split(S, "")
list_T := strings.Split(T, "")

// Initialize a list Number_i containing numbers from 0 to N-1
var Number_i []int
for i := 0; i < N; i++ {
    Number_i = append(Number_i, i)
}

// Initialize an empty list Number_iMN to store the results of the division i*M/N
var Number_iMN []int

// Iterate through each number i in the list Number_i
for _, i := range Number_i {
    // Append the result of the division i*M/N to the list Number_iMN
    Number_iMN = append(Number_iMN, i*M/N)
}

// Initialize a list Number_j containing numbers from 0 to M-1
var Number_j []int
for j := 0; j < M; j++ {
    Number_j = append(Number_j, j)
}

// Find the common elements between Number_iMN and Number_j using set intersection
Kaburi_j := list(set(Number_iMN) & set(Number_j))

// Initialize an empty list Kaburi_i to store the integer representations of the common elements
var Kaburi_i []int

// Iterate through each common element j in Kaburi_j
for _, j := range Kaburi_j {
    // Append the integer representation of j to the list Kaburi_i
    Kaburi_i = append(Kaburi_i, int(j*N/M))
}

// Initialize a counter variable to keep track of the current index in Kaburi_i
var counter int

// Initialize a flag variable to indicate whether there is a mismatch between S and T
var Flag int

// Determine the size of Kaburi_i
Kaburi_Size := len(Kaburi_i)

// Iterate through each index in Kaburi_i until the end of the list
for counter = 0; counter < Kaburi_Size; counter++ {
    // Check if the corresponding elements in S and T match
    if list_S[Kaburi_i[counter]]!= list_T[Kaburi_j[counter]] {
        // Set the flag variable to 1 if there is a mismatch
        Flag = 1
        // Break out of the loop
        break
    }
}

// Define a function gcd(a, b) to calculate the greatest common divisor of two integers
func gcd(a, b int) int {
    // While b is not equal to 0, keep updating a and b using the modulo operator
    for b!= 0 {
        a, b = b, a%b
    }
    // Return the final value of a as the greatest common divisor
    return a
}

// Check if there is a mismatch between S and T
if Flag == 1 {
    // Print -1 if there is a mismatch
    fmt.Println(-1)
} else {
    // Calculate and print the product of N and M divided by their greatest common divisor
    fmt.Println(int(N*M/gcd(N, M)))
}

