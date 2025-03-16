
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    N := nextInt(scanner)
    A := make([]int, N)
    for i := 0; i < N; i++ {
        A[i] = nextInt(scanner)
    }
    if possible(N, A) {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}

func nextInt(scanner *bufio.Scanner) int {
    scanner.Scan()
    n, _ := strconv.Atoi(scanner.Text())
    return n
}

func possible(N int, A []int) bool {
    sum := 0
    for i := 0; i < N; i++ {
        sum += A[i]
    }
    NS := (N * (N + 1)) / 2
    if sum%NS != 0 {
        return false
    }
    K := sum / NS
    for i := 0; i < N; i++ {
        j := i - 1
        if j < 0 {
            j = N - 1
        }
        d := K - (A[i] - A[j])
        if d < 0 || d%N != 0 {
            return false
        }
    }
    return true
}

// 