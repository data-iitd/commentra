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

// gcd function: This function computes the greatest common divisor of two
// integers using the Euclidean algorithm.
func gcd(a, b int) int {
    if a < b {
        a, b = b, a
    }
    for b!= 0 {
        a, b = b, a%b
    }
    return a
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the number of integers:")
    n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))

    fmt.Println("Enter the first integer:")
    ans, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))

    for i := 1; i < n; i++ {
        fmt.Println("Enter the next integer:")
        a, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
        ans = gcd(ans, a)
    }

    fmt.Println(ans)
}

