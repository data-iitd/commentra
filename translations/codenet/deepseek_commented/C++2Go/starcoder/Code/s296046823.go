<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math"
)

func main() {
    var N, K int
    fmt.Scanf("%d %d\n", &N, &K) // 1. Reading the values of N and K from the standard input.

    v := make([]int, N) // 2. Initializing a vector of size N to store N integers.
    for i := 0; i < N; i++ {
        fmt.Scanf("%d\n", &v[i]) // 3. Reading N integers from the standard input and storing them in the vector v.
    }

    // 4. Calculating the number of groups that can be formed using the formula ceil((N-1) / (K-1)).
    count := int(math.Ceil((float64(N-1)) / (float64(K-1))))
    fmt.Printf("%d\n", count) // 5. Outputting the calculated count.
}

