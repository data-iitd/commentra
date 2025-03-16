package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the number of points (n) and the number of dimensions (d)
    n, d := readInts()

    // Declare a 2D array to store the coordinates of the points
    point := make([][]int, n+1)
    for i := range point {
        point[i] = make([]int, d+1)
    }

    // Input the coordinates for each point
    for i := 1; i <= n; i++ {
        for j := 1; j <= d; j++ {
            point[i][j] = readInt()
        }
    }

    // Initialize a counter for the number of pairs with integer distance
    count := 0

    // Iterate through all unique pairs of points
    for i := 1; i <= n-1; i++ {
        for j := i + 1; j <= n; j++ {

            // Calculate the squared distance between point i and point j
            sum := 0
            for k := 1; k <= d; k++ {
                sum += (point[i][k] - point[j][k]) * (point[i][k] - point[j][k])
            }

            // Compute the Euclidean distance
            kyori := sqrt(float64(sum))

            // Check if the distance is an integer
            if int(kyori) == kyori {
                count++ // Increment the count if the distance is an integer
            }
        }
    }

    // Output the total count of pairs with integer distance
    fmt.Println(count)
}

func readInt() int {
    r := bufio.NewReader(os.Stdin)
    i, _ := strconv.Atoi(strings.TrimSpace(r.ReadString()))
    return i
}

func readInts() (int, int) {
    r := bufio.NewReader(os.Stdin)
    line, _ := r.ReadString()
    splitted := strings.Split(line, " ")
    return atoi(splitted[0]), atoi(splitted[1])
}

func atoi(s string) int {
    i, _ := strconv.Atoi(s)
    return i
}

func sqrt(x float64) float64 {
    return float64(int(x + 0.5))
}

