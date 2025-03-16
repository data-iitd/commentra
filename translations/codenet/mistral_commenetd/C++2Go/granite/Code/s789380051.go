

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

const MOD = 1000000007

func main() {
    // Initialize variables
    n := readInt()
    a := readInt()
    b := readInt()
    ans := int64(1)

    ans = modPow(2, n)
    // Calculate 2^n
    ans--
    // Subtract 1 from the result

    nCa := combS(n, a)
    // Calculate nCa

    ans = (ans - nCa) % MOD
    // Subtract nCa from the result

    for ans < 0 {
        // If the result is negative, add MOD to make it positive
        ans += MOD
    }

    // Calculate nCb
    nCb := combS(n, b)

    ans = (ans - nCb) % MOD
    // Subtract nCb from the result

    for ans < 0 {
        // If the result is negative, add MOD to make it positive
        ans += MOD
    }

    fmt.Println(ans)
    // Print the final answer
}

func readInt() int {
    // Function to read an integer from the input
    sc := bufio.NewScanner(os.Stdin)
    sc.Split(bufio.ScanWords)
    var n int
    sc.Scan()
    fmt.Sscanf(sc.Text(), "%d", &n)
    return n
}

func modPow(x, n int64) int64 {
    // Function to calculate x raised to the power n modulo MOD
    ans := int64(1)
    for n > 0 {
        // While n is greater than 0
        if n&1 == 1 {
            // If n is odd
            ans = ans * x % MOD
            // Multiply ans with x
        }
        x = x * x % MOD
        // Square x and update ans
        n >>= 1
        // Divide n by 2
    }
    return ans
}

func combS(n, r int64) int64 {
    // Function to calculate nCr (n choose r) using combinatorics formula
    tmpN := int64(1)
    tmpD := int64(1)
    ans := int64(0)
    // Initialize temporary variables tmpN and tmpD to 1
    for i := int64(1); i <= r; i++ {
        // Loop from i=1 to i=r
        tmpN = (tmpN * (n + 1 - i)) % MOD
        // Multiply tmpN with (n+1-i)
        tmpD = (tmpD * i) % MOD
        // Multiply tmpD with i
        ans = tmpN * modPow(tmpD, MOD-2)
        // Calculate ans = tmpN * (tmpD^(MOD-2))
    }

    return ans
}

// End of Go code