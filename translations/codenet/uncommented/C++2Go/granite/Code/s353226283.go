
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    n, k := readInt(), readInt()
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i] = readInt()
    }
    sort.Ints(a)
    ans := 1000000001
    for i := 0; i+k-1 < n; i++ {
        diff := a[i+k-1] - a[i]
        if diff < ans {
            ans = diff
        }
    }
    fmt.Println(ans)
}

func readInt() int {
    i, _ := strconv.Atoi(readWord())
    return i
}

func readWord() string {
    s, _ := in.ReadString(' ')
    return s[:len(s)-1]
}

func readLine() string {
    s, _ := in.ReadString('\n')
    return s[:len(s)-1]
}

func readMatrix(n int) [][]int {
    m := make([][]int, n)
    for i := 0; i < n; i++ {
        m[i] = readIntArray(n)
    }
    return m
}

func readIntArray(n int) []int {
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i] = readInt()
    }
    return a
}

func readInt64Array(n int) []int64 {
    a := make([]int64, n)
    for i := 0; i < n; i++ {
        a[i] = readInt64()
    }
    return a
}

func readInt64() int64 {
    i, _ := strconv.ParseInt(readWord(), 10, 64)
    return i
}

func readFloat() float64 {
    f, _ := strconv.ParseFloat(readWord(), 64)
    return f
}

func readStringArray(n int) []string {
    a := make([]string, n)
    for i := 0; i < n; i++ {
        a[i] = readLine()
    }
    return a
}

func readString() string {
    return readLine()
}

func printArray(a []int) {
    for _, v := range a {
        fmt.Printf("%d ", v)
    }
    fmt.Println()
}

func printMatrix(m [][]int) {
    for _, v := range m {
        printArray(v)
    }
}

func printArray2D(a [][]int) {
    for _, v := range a {
        for _, u := range v {
            fmt.Printf("%d ", u)
        }
        fmt.Println()
    }
}

func printBoolMatrix(m [][]bool) {
    for _, v := range m {
        printBoolArray(v)
    }
}

func printBoolArray(a []bool) {
    for _, v := range a {
        fmt.Print(v, " ")
    }
    fmt.Println()
}

func printIntMatrix(m [][]int) {
    for _, v := range m {
        printIntArray(v)
    }
}

func printIntArray(a []int) {
    for _, v := range a {
        fmt.Print(v, " ")
    }
    fmt.Println()
}

func printInt64Array(a []int64) {
    for _, v := range a {
        fmt.Print(v, " ")
    }
    fmt.Println()
}

func printStringArray(a []string) {
    for _, v := range a {
        fmt.Print(v, " ")
    }
    fmt.Println()
}

func printStringMatrix(m [][]string) {
    for _, v := range m {
        printStringArray(v)
    }
}

func printBool(b bool) {
    if b {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}

func printBoolArray(a []bool) {
    for _, v := range a {
        printBool(v)
    }
}

func printBoolMatrix(m [][]bool) {
    for _, v := range m {
        printBoolArray(v)
    }
}

func printBoolMatrix2(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix3(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix4(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix5(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix6(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix7(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix8(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix9(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix10(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix11(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix12(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix13(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix14(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix15(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix16(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix17(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix18(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix19(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix20(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix21(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix22(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix23(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix24(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix25(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix26(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix27(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix28(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix29(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix30(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix31(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix32(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix33(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix34(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix35(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix36(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix37(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix38(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix39(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix40(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix41(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix42(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix43(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix44(m [][]bool) {
    for _, v := range m {
        for _, u := range v {
            fmt.Print(u, " ")
        }
        fmt.Println()
    }
}

func printBoolMatrix45(m [][]bool) {
    for _, 