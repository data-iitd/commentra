

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Create a Scanner object to read input from the standard input stream
    scanner := bufio.NewScanner(os.Stdin)

    // Read the number of switches (N) and the number of lights (M)
    scanner.Scan()
    line := scanner.Text()
    parts := strings.Split(line, " ")
    N, _ := strconv.Atoi(parts[0])
    M, _ := strconv.Atoi(parts[1])

    // Initialize an array of integers with N elements, all set to 0
    a := make([]int, N)

    // Read M groups of integers, where each group represents a switch and its corresponding states
    for i := 0; i < M; i++ {
        scanner.Scan()
        line = scanner.Text()
        k, _ := strconv.Atoi(line)
        for j := 0; j < k; j++ {
            scanner.Scan()
            s, _ := strconv.Atoi(scanner.Text())
            s--
            a[s] |= 1 << i
        }
    }

    // Read the final state of each light
    p := 0
    for i := 0; i < M; i++ {
        scanner.Scan()
        x, _ := strconv.Atoi(scanner.Text())
        p |= x << i
    }

    // Calculate the number of possible configurations of switch states that match the final state of the lights
    ans := 0
    for s := 0; s < 1<<N; s++ {
        t := 0
        for i := 0; i < N; i++ {
            if (s>>i)&1 == 1 {
                t ^= a[i]
            }
        }
        if p == t {
            ans++
        }
    }

    // Print the result
    fmt.Println(ans)
}

