

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
    fmt.Println("Enter the array elements:")
    for i := 0; i < n; i++ {
        a[i], _ = reader.ReadString('\n')
        a[i], _ = strconv.Atoi(strings.TrimSpace(a[i]))
        a[i] /= 2
    }
    gcd := int64(0)
    lcm := int64(1)
    for i := 0; i < n; i++ {
        gcd = getGCD(lcm, int64(a[i]))
        lcm = lcm * int64(a[i]) / gcd
        if lcm > int64(m) {
            fmt.Println(0)
            return
        }
    }
    for i := 0; i < n; i++ {
        if (lcm/int64(a[i]))%2 == 0 {
            fmt.Println(0)
            return
        }
    }
    fmt.Println((m / lcm + 1) / 2)
}

func getGCD(a, b int64) int64 {
    if b == 0 {
        return a
    }
    return getGCD(b, a%b)
}

