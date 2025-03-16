<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Step 1: Input Reading
    // The code starts by reading the input value N and the array A of size N.
    reader := bufio.NewReader(os.Stdin)
    N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    A := make([]int, N+1)
    for i := 1; i <= N; i++ {
        A[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
    }

    // Step 2: Initialization
    // The dp array is initialized to a very large negative value to represent infinity,
    // except for dp[0][0][10] which is initialized to 0. This setup helps in finding the maximum value using dynamic programming.
    dp := make([][][20]int, N+1)
    for i := 0; i <= N; i++ {
        dp[i] = make([][20]int, 2)
        for j := 0; j < 20; j++ {
            dp[i][0][j] = -(1 << 60)
            dp[i][1][j] = -(1 << 60)
        }
    }
    dp[0][0][10] = 0

    // Step 3: Dynamic Programming Transition
    // The main loop iterates through each element of the array A and updates the dp array based on the previous states.
    // The transitions are carefully crafted to ensure the maximum value is computed considering two states: whether the current element is included or not.
    for i := 1; i <= N; i++ {
        for j := 6; j <= 14; j++ {
            if dp[i-1][0][j]!= (1 << 60) {
                dp[i][1][j+1] = max(dp[i][1][j+1], dp[i-1][0][j]+A[i])
                dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][0][j])
            }
            if dp[i-1][1][j]!= (1 << 60) {
                dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][1][j])
            }
        }
    }

    // Step 4: Calculating the Result
    // After processing all elements, the code calculates the index V which is used to access the final states in the dp array.
    // It then outputs the maximum value between dp[N][0][V] and dp[N][1][V].
    V := 10 + (N/2) - (N-(N/2))
    T1 := dp[N][0][V]
    T2 := dp[N][1][V]
    fmt.Println(max(T1, T2))
}

<<<<<<< HEAD
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

=======
>>>>>>> 98c87cb78a (data updated)
func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

<<<<<<< HEAD
=======
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

>>>>>>> 98c87cb78a (data updated)
