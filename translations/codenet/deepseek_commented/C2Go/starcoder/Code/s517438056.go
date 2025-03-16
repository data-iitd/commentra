<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Step 1: Reading Input
    var N, D int
    fmt.Scanf("%d%d", &N, &D)
    
    // Step 2: Inputting Points
    var matrix [N][D]int
    for i := 0; i < N; i++ {
        for j := 0; j < D; j++ {
            fmt.Scanf("%d", &matrix[i][j])
        }
    }
    
    // Step 3: Calculating Distances
    var k int
    for i := 0; i < N - 1; i++ {
        for j := i + 1; j < N; j++ {
            var m int
            for n := 0; n < D; n++ {
                m += (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n])
            }
            l := math.Sqrt(float64(m))
            if math.Ceil(l) == math.Floor(l) {
                k++
            }
        }
    }
    
    // Step 4: Outputting the Result
    fmt.Printf("%d\n", k)
}

