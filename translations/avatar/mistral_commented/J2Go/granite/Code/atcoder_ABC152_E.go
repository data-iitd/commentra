
package main

import (
    "bufio"
    "fmt"
    "io"
    "math/big"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    NTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    N := int32(NTemp)

    ATemp := strings.Split(readLine(reader), " ")

    var A []int32

    for i := 0; i < int(N); i++ {
        AItemTemp, err := strconv.ParseInt(ATemp[i], 10, 64)
        checkError(err)
        AItem := int32(AItemTemp)
        A = append(A, AItem)
    }

    lcm := big.NewInt(1)

    for _, a := range A {
        lcm.Div(lcm, big.NewInt(int64(a)).GCD(nil, nil, lcm))
        lcm.Mul(lcm, big.NewInt(int64(a)))
    }

    mod := int64(1e9 + 7)
    modLcm := lcm.Mod(lcm, big.NewInt(mod)).Int64()

    ans := int64(0)

    for _, a := range A {
        ans = (ans + modDiv(modLcm, int64(a), mod)) % mod
    }

    fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

func modDiv(a, b, mod int64) int64 {
    a %= mod
    return (a * modInv(b, mod)) % mod
}

func modInv(x, mod int64) int64 {
    return modPow(x, mod-2, mod)
}

func modPow(b, e, mod int64) int64 {
    ans := int64(1)
    x := b % mod

    for y := e; y!= 0; y >>= 1 {
        if y&1 == 1 {
            ans = (ans * x) % mod
        }
        x = (x * x) % mod
    }

    return ans
}

