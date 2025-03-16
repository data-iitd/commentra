

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the first integer n:")
    n, _ := reader.ReadString('\n')
    n, _ = strconv.Atoi(strings.TrimSpace(n))
    fmt.Println("Enter the second integer m:")
    m, _ := reader.ReadString('\n')
    m, _ = strconv.Atoi(strings.TrimSpace(m))
    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Println("Enter the next integer for array a:")
        a[i], _ = reader.ReadString('\n')
        a[i], _ = strconv.Atoi(strings.TrimSpace(a[i]))
        a[i] /= 2
    }
    var gcd, lcm int
    lcm = 1
    for i := 0; i < n; i++ {
        gcd = getGCD(lcm, a[i])
        lcm = lcm * a[i] / gcd
        if lcm > m {
            fmt.Println(0)
            return
        }
    }
    for i := 0; i < n; i++ {
        if (lcm/a[i])%2 == 0 {
            fmt.Println(0)
            return
        }
    }
    fmt.Println((m/lcm + 1) / 2)
}

func getGCD(a, b int) int {
    if b == 0 {
        return a
    } else {
        return getGCD(b, a%b)
    }
}

