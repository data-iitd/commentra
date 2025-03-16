
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    a, b := readInt(), readInt()
    ans := 0
    if a >= 13 {
        ans = b
    } else if a >= 6 {
        ans = b / 2
    }
    fmt.Println(ans)
}

func readInt() int {
    i, _ := strconv.Atoi(readWord())
    return i
}

func readWord() string {
    s, _ := in.ReadString(' ')
    return strings.TrimSpace(s)
}

func readLine() string {
    s, _ := in.ReadString('\n')
    return strings.TrimSpace(s)
}

func readBytes() []byte {
    buf, _ := in.ReadBytes('\n')
    return buf
}

func readInt64() int64 {
    i, _ := strconv.ParseInt(readWord(), 10, 64)
    return i
}

func readFloat64() float64 {
    f, _ := strconv.ParseFloat(readWord(), 64)
    return f
}

func readBool() bool {
    s := readWord()
    if s == "true" {
        return true
    } else {
        return false
    }
}

func readLineSlice() []string {
    return strings.Split(readLine(), " ")
}

func readLineIntSlice() []int {
    slice := readLineSlice()
    var intSlice []int

    for _, tmp := range slice {
        val, _ := strconv.Atoi(tmp)
        intSlice = append(intSlice, val)
    }

    return intSlice
}

func readLineInt64Slice() []int64 {
    slice := readLineSlice()
    var int64Slice []int64

    for _, tmp := range slice {
        val, _ := strconv.ParseInt(tmp, 10, 64)
        int64Slice = append(int64Slice, val)
    }

    return int64Slice
}

func readLineFloat64Slice() []float64 {
    slice := readLineSlice()
    var float64Slice []float64

    for _, tmp := range slice {
        val, _ := strconv.ParseFloat(tmp, 64)
        float64Slice = append(float64Slice, val)
    }

    return float64Slice
}

func readLineBoolSlice() []bool {
    slice := readLineSlice()
    var boolSlice []bool

    for _, tmp := range slice {
        val := tmp == "true"
        boolSlice = append(boolSlice, val)
    }

    return boolSlice
}

func readLineStringSlice() []string {
    return strings.Split(readLine(), " ")
}

func readMatrix(r int, c int) [][]int {
    var matrix [][]int
    for i := 0; i < r; i++ {
        matrix = append(matrix, readLineIntSlice())
    }
    return matrix
}

func readMatrixString(r int, c int) [][]string {
    var matrix [][]string
    for i := 0; i < r; i++ {
        matrix = append(matrix, readLineStringSlice())
    }
    return matrix
}

func readMatrixBool(r int, c int) [][]bool {
    var matrix [][]bool
    for i := 0; i < r; i++ {
        matrix = append(matrix, readLineBoolSlice())
    }
    return matrix
}

func readMatrixInt64(r int, c int) [][]int64 {
    var matrix [][]int64
    for i := 0; i < r; i++ {
        matrix = append(matrix, readLineInt64Slice())
    }
    return matrix
}

func readMatrixFloat64(r int, c int) [][]float64 {
    var matrix [][]float64
    for i := 0; i < r; i++ {
        matrix = append(matrix, readLineFloat64Slice())
    }
    return matrix
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func pow(x, n int) int {
    if n == 0 {
        return 1
    }
    tmp := pow(x, n/2)
    if n%2 == 0 {
        return tmp * tmp
    } else {
        return tmp * tmp * x
    }
}

func powMod(x, n, mod int) int {
    if n == 0 {
        return 1
    }
    tmp := powMod(x, n/2, mod)
    tmp %= mod
    if n%2 == 0 {
        return (tmp * tmp) % mod
    } else {
        return (tmp * tmp * x) % mod
    }
}

func allDivisor(n int) []int {
    var divisor []int
    for i := 1; i <= int(math.Sqrt(float64(n))); i++ {
        if n%i == 0 {
            divisor = append(divisor, i)
            if i*i!= n {
                divisor = append(divisor, n/i)
            }
        }
    }
    return divisor
}

func isPrime(n int) bool {
    if n <= 1 {
        return false
    }
    for i := 2; i <= int(math.Sqrt(float64(n))); i++ {
        if n%i == 0 {
            return false
        }
    }
    return true
}

func nextPrime(n int) int {
    if n <= 1 {
        return 2
    }
    x := n
    for {
        x++
        if isPrime(x) {
            return x
        }
    }
}

func isPermutation(s1 string, s2 string) bool {
    if len(s1)!= len(s2) {
        return false
    }

    count := make(map[rune]int)
    for _, r := range s1 {
        count[r]++
    }
    for _, r := range s2 {
        if count[r] <= 0 {
            return false
        }
        count[r]--
    }

    return true
}

func gcd(m, n int) int {
    for m%n!= 0 {
        m, n = n, m%n
    }
    return n
}

func lcm(m, n int) int {
    return m * n / gcd(m, n)
}

func sortInt(a []int) []int {
    sort.Ints(a)
    return a
}

func sortInt64(a []int64) []int64 {
    sort.Int64s(a)
    return a
}

func sortString(a []string) []string {
    sort.Strings(a)
    return a
}

func readLineSliceInt() []int {
    return readLineIntSlice()
}

func readLineSliceInt64() []int64 {
    return readLineInt64Slice()
}

func readLineSliceString() []string {
    return readLineStringSlice()
}

func readLineSliceBool() []bool {
    return readLineBoolSlice()
}

func readLineSliceFloat64() []float64 {
    return readLineFloat64Slice()
}

func main() {
    a, b := readInt(), readInt()
    ans := 0
    if a >= 13 {
        ans = b
    } else if a >= 6 {
        ans = b / 2
    }
    fmt.Println(ans)
}

