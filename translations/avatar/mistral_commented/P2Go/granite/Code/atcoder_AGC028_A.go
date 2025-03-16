
###
# Code
###

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Define input variables N and M as integers
    var N, M int

    // Read input from the user
    reader := bufio.NewReader(os.Stdin)
    fmt.Fscanf(reader, "%d %d\n", &N, &M)

    // Comments: Get the dimensions N and M of the matrices S and T from user input

    // Initialize variables S and T as strings
    var S, T string

    // Read input for S and T from the user
    fmt.Fscanf(reader, "%s\n", &S)
    fmt.Fscanf(reader, "%s\n", &T)

    // Convert strings S and T into slices of runes
    list_S := []rune(S)
    list_T := []rune(T)

    // Initialize a slice Number_i containing numbers from 0 to N-1
    Number_i := make([]int, N)
    for i := 0; i < N; i++ {
        Number_i[i] = i
    }

    // Initialize a slice Number_iMN to store the results of the division i*M/N
    Number_iMN := make([]int, N)
    for i := 0; i < N; i++ {
        Number_iMN[i] = int(i * M / N)
    }

    // Initialize a slice Number_j containing numbers from 0 to M-1
    Number_j := make([]int, M)
    for j := 0; j < M; j++ {
        Number_j[j] = j
    }

    // Find the common elements between Number_iMN and Number_j using set intersection
    Kaburi_j := make([]int, 0)
    for _, j := range Number_j {
        if contains(Number_iMN, j) {
            Kaburi_j = append(Kaburi_j, j)
        }
    }

    // Initialize a slice Kaburi_i to store the integer representations of the common elements
    Kaburi_i := make([]int, 0)
    for _, j := range Kaburi_j {
        Kaburi_i = append(Kaburi_i, int(j * N / M))
    }

    // Initialize a counter variable to keep track of the current index in Kaburi_i
    counter := 0

    // Initialize a flag variable to indicate whether there is a mismatch between S and T
    Flag := 0

    // Determine the size of Kaburi_i
    Kaburi_Size := len(Kaburi_i)

    // Iterate through each index in Kaburi_i until the end of the list
    for counter <= Kaburi_Size-1 {
        // Check if the corresponding elements in S and T match
        if list_S[Kaburi_i[counter]]!= list_T[Kaburi_j[counter]] {
            // Set the flag variable to 1 if there is a mismatch
            Flag = 1
            // Break out of the loop
            break
        }
        // Increment the counter variable
        counter += 1
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
        fmt.Println(int(N * M / gcd(N, M)))
    }
}

// Define a function contains(s []int, e int) to check if a slice contains a specific element
func contains(s []int, e int) bool {
    for _, a := range s {
        if a == e {
            return true
        }
    }
    return false
}

// Define a function readInt() to read an integer from the user
func readInt() int {
    reader := bufio.NewReader(os.Stdin)
    str, _ := reader.ReadString('\n')
    intVal, _ := strconv.Atoi(strings.TrimSpace(str))
    return intVal
}

// Define a function readString() to read a string from the user
func readString() string {
    reader := bufio.NewReader(os.Stdin)
    str, _ := reader.ReadString('\n')
    return strings.TrimSpace(str)
}

// Define a function readStrings() to read multiple strings from the user
func readStrings() []string {
    reader := bufio.NewReader(os.Stdin)
    str, _ := reader.ReadString('\n')
    strings := strings.Split(strings.TrimSpace(str), " ")
    return strings
}

// Define a function readIntSlice() to read a slice of integers from the user
func readIntSlice(n int) []int {
    intSlice := make([]int, n)
    for i := 0; i < n; i++ {
        intSlice[i] = readInt()
    }
    return intSlice
}

// Define a function readStringSlice() to read a slice of strings from the user
func readStringSlice(n int) []string {
    stringSlice := make([]string, n)
    for i := 0; i < n; i++ {
        stringSlice[i] = readString()
    }
    return stringSlice
}

// Define a function readIntMatrix(n, m int) to read a matrix of integers from the user
func readIntMatrix(n, m int) [][]int {
    matrix := make([][]int, n)
    for i := 0; i < n; i++ {
        matrix[i] = readIntSlice(m)
    }
    return matrix
}

// Define a function readStringMatrix(n, m int) to read a matrix of strings from the user
func readStringMatrix(n, m int) [][]string {
    matrix := make([][]string, n)
    for i := 0; i < n; i++ {
        matrix[i] = readStringSlice(m)
    }
    return matrix
}

// Define a function min(a, b int) to find the minimum of two integers
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

// Define a function max(a, b int) to find the maximum of two integers
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

// Define a function abs(a int) to find the absolute value of an integer
func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

// Define a function pow(a, b int) to calculate the power of a number
func pow(a, b int) int {
    result := 1
    for i := 0; i < b; i++ {
        result *= a
    }
    return result
}

// Define a function powMod(a, b, mod int) to calculate the power of a number modulo a given modulus
func powMod(a, b, mod int) int {
    result := 1
    for i := 0; i < b; i++ {
        result = (result * a) % mod
    }
    return result
}

// Define a function factorial(n int) to calculate the factorial of a number
func factorial(n int) int {
    result := 1
    for i := 1; i <= n; i++ {
        result *= i
    }
    return result
}

// Define a function factorialMod(n, mod int) to calculate the factorial of a number modulo a given modulus
func factorialMod(n, mod int) int {
    result := 1
    for i := 1; i <= n; i++ {
        result = (result * i) % mod
    }
    return result
}

// Define a function isPrime(n int) to check if a number is prime
func isPrime(n int) bool {
    if n <= 1 {
        return false
    }
    for i := 2; i*i <= n; i++ {
        if n%i == 0 {
            return false
        }
    }
    return true
}

// Define a function gcd(a, b int) to calculate the greatest common divisor of two numbers
func gcd(a, b int) int {
    for b!= 0 {
        a, b = b, a%b
    }
    return a
}

// Define a function lcm(a, b int) to calculate the least common multiple of two numbers
func lcm(a, b int) int {
    return a * b / gcd(a, b)
}

// Define a function isPerfectSquare(n int) to check if a number is a perfect square
func isPerfectSquare(n int) bool {
    x := int(math.Sqrt(float64(n)))
    return x*x == n
}

// Define a function modInverse(a, m int) to calculate the modular inverse of a number modulo a given modulus
func modInverse(a, m int) int {
    a %= m
    for x := 1; x < m; x++ {
        if (a*x)%m == 1 {
            return x
        }
    }
    return -1
}

// Define a function modDivide(a, b, m int) to calculate the modular division of two numbers modulo a given modulus
func modDivide(a, b, m int) int {
    a %= m
    b %= m
    inv := modInverse(b, m)
    if inv == -1 {
        return -1
    } else {
        return (a * inv) % m
    }
}

// Define a function nCr(n, r int) to calculate the binomial coefficient n choose r
func nCr(n, r int) int {
    return factorial(n) / (factorial(r) * factorial(n-r))
}

// Define a function nCrMod(n, r, mod int) to calculate the binomial coefficient n choose r modulo a given modulus
func nCrMod(n, r, mod int) int {
    return factorialMod(n, mod) / (factorialMod(r, mod) * factorialMod(n-r, mod))
}

// Define a function nPr(n, r int) to calculate the permutation nPr
func nPr(n, r int) int {
    return factorial(n) / factorial(n-r)
}

// Define a function nPrMod(n, r, mod int) to calculate the permutation nPr modulo a given modulus
func nPrMod(n, r, mod int) int {
    return factorialMod(n, mod) / factorialMod(n-r, mod)
}

// Define a function knapsack(w, wt []int, val []int, n int) int to solve the 0-1 knapsack problem
func knapsack(w, wt []int, val []int, n int) int {
    dp := make([]int, n+1)
    for i := 1; i <= n; i++ {
        dp[i] = dp[i-1]
        if wt[i-1] <= w {
            dp[i] = max(dp[i], dp[i-1]+val[i-1])
        }
    }
    return dp[n]
}

// Define a function knapsack01Mod(w, wt []int, val []int, n, mod int) int to solve the 0-1 knapsack problem modulo a given modulus
func knapsack01Mod(w, wt []int, val []int, n, mod int) int {
    dp := make([]int, n+1)
    for i := 1; i <= n; i++ {
        dp[i] = dp[i-1]
        if wt[i-1] <= w {
            dp[i] = (dp[i] + val[i-1]) % mod
        }
    }
    return dp[n]
}

// Define a function longestCommonSubsequence(s1, s2 string) int to find the length of the longest common subsequence of two strings
func longestCommonSubsequence(s1, s2 string) int {
    m := len(s1)
    n := len(s2)
    dp := make([][]int, m+1)
    for i := 0; i <= m; i++ {
        dp[i] = make([]int, n+1)
    }
    for i := 1; i <= m; i++ {
        for j := 1; j <= n; j++ {
            if s1[i-1] == s2[j-1] {
                dp[i][j] = dp[i-1][j-1] + 1
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
            }
        }
    }
    return dp[m][n]
}

// Define a function longestCommonSubsequenceMod(s1, s2 string, mod int) int to find the length of the longest common subsequence of two strings modulo a given modulus
func longestCommonSubsequenceMod(s1, s2 string, mod int) int {
    m := len(s1)
    n := len(s2)
    dp := make([][]int, m+1)
    for i := 0; i <= m; i++ {
        dp[i] = make([]