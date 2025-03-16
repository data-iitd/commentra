

package main

import (
    "bufio"
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    // Reading the number of vectors N and their dimensions D from user input
    N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    D, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    // Creating a 2D integer array'vectors' of size N x D to store the vectors
    vectors := make([][]int, N)
    for i := 0; i < N; i++ {
        vectors[i] = make([]int, D)
        for j := 0; j < D; j++ {
            vectors[i][j], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
        }
    }

    // Initializing the answer variable to 0
    answer := 0

    // Iterating through all pairs of vectors (i, j) where i < j
    for i := 0; i < N-1; i++ {
        for j := i + 1; j < N; j++ {

            // Calculating the Euclidean distance between the vectors i and j
            dist := 0
            for d := 0; d < D; d++ {
                x := vectors[i][d] - vectors[j][d] // Difference between corresponding components
                dist += x * x // Squaring the difference and adding to the distance
            }

            // Calculating the square root of the distance and checking if it is a perfect square
            sq := math.Sqrt(float64(dist))
            if math.Abs(sq-math.Floor(sq)) < 0.001 {
                answer++
            }
        }
    }

    // Printing the final answer
    fmt.Println(answer)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

