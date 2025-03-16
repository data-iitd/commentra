
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Step 1: Read the input number n and the array elements
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(reader.ReadString('\n'))
    sa := strings.Split(reader.ReadString('\n'), " ")
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(sa[i])
    }

    // Step 2: Calculate the factorial of n modulo 10^9 + 7
    mod := 1000000007
    p := 1
    for i := 2; i <= n; i++ {
        p = (p * i) % mod
    }

    // Step 3: Calculate the inverse modulo for each number from 2 to n
    q := make([]int, n)
    q[0] = 1
    for i := 1; i < n; i++ {
        q[i] = (q[i-1] + modinv(i+1, mod)) % mod
    }

    // Step 4: Calculate the answer using the given formula
    ans := 0
    for i := 0; i < n; i++ {
        val := q[i] + q[n-i-1] - 1
        val *= a[i]
        val %= mod
        val *= p
        val %= mod
        ans += val
        ans %= mod
    }

    // Step 5: Print the final answer
    fmt.Println(ans)
}

// Function to calculate the modular inverse
func modinv(a, m int) int {
    b := m
    u := 1
    v := 0
    tmp := 0
    for b > 0 {
        t := a / b
        a -= t * b
        tmp = a
        a = b
        b = tmp
        u -= t * v
        tmp = u
        u = v
        v = tmp
    }
    u %= m
    if u < 0 {
        u += m
    }
    return u
}

// 