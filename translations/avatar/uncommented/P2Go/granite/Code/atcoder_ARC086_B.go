
package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    N := readInt()
    a := readIntSlice(N)
    max_val := 0
    max_sign := 0
    max_index := -1
    for i, a0 := range a {
        if abs(a0) > max_val {
            max_val = abs(a0)
            max_sign = sign(a0)
            max_index = i
        }
    }
    if max_sign == 0 {
        fmt.Println(0)
    } else if max_sign == 1 {
        fmt.Println(2*N - 1)
        for i := 0; i < N; i++ {
            fmt.Printf("%d %d\n", max_index+1, i+1)
        }
        for i := 0; i < N-1; i++ {
            fmt.Printf("%d %d\n", i+1, i+2)
        }
    } else {
        fmt.Println(2*N - 1)
        for i := 0; i < N; i++ {
            fmt.Printf("%d %d\n", max_index+1, i+1)
        }
        for i := N - 1; i > 0; i-- {
            fmt.Printf("%d %d\n", i+1, i)
        }
    }
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func sign(x int) int {
    if x > 0 {
        return 1
    } else if x < 0 {
        return -1
    }
    return 0
}

func readString() string {
    s, _ := in.ReadString('\n')
    return strings.TrimSpace(s)
}

func readBytes() []byte {
    s, _ := in.ReadBytes('\n')
    return s[:len(s)-1]
}

func readInt() int {
    res, _ := strconv.Atoi(readString())
    return res
}

func readInt64() int64 {
    res, _ := strconv.ParseInt(readString(), 10, 64)
    return res
}

func readIntSlice(n int) []int {
    res := make([]int, n)
    for i := 0; i < n; i++ {
        res[i] = readInt()
    }
    return res
}

func readInt64Slice(n int) []int64 {
    res := make([]int64, n)
    for i := 0; i < n; i++ {
        res[i] = readInt64()
    }
    return res
}

func readFloat64() float64 {
    res, _ := strconv.ParseFloat(readString(), 64)
    return res
}

func readFloat64Slice(n int) []float64 {
    res := make([]float64, n)
    for i := 0; i < n; i++ {
        res[i] = readFloat64()
    }
    return res
}

func readStringSlice(n int) []string {
    res := make([]string, n)
    for i := 0; i < n; i++ {
        res[i] = readString()
    }
    return res
}

func readBytesSlice(n int) [][]byte {
    res := make([][]byte, n)
    for i := 0; i < n; i++ {
        res[i] = readBytes()
    }
    return res
}

func maxInt(a...int) int {
    res := a[0]
    for _, v := range a[1:] {
        if v > res {
            res = v
        }
    }
    return res
}

func minInt(a...int) int {
    res := a[0]
    for _, v := range a[1:] {
        if v < res {
            res = v
        }
    }
    return res
}

func maxInt64(a...int64) int64 {
    res := a[0]
    for _, v := range a[1:] {
        if v > res {
            res = v
        }
    }
    return res
}

func minInt64(a...int64) int64 {
    res := a[0]
    for _, v := range a[1:] {
        if v < res {
            res = v
        }
    }
    return res
}

func maxFloat64(a...float64) float64 {
    res := a[0]
    for _, v := range a[1:] {
        if v > res {
            res = v
        }
    }
    return res
}

func minFloat64(a...float64) float64 {
    res := a[0]
    for _, v := range a[1:] {
        if v < res {
            res = v
        }
    }
    return res
}

func pow(x, n int) int {
    res := 1
    for n > 0 {
        if n&1 == 1 {
            res *= x
        }
        x *= x
        n >>= 1
    }
    return res
}

func powMod(x, n, mod int) int {
    res := 1
    for n > 0 {
        if n&1 == 1 {
            res = (res * x) % mod
        }
        x = (x * x) % mod
        n >>= 1
    }
    return res
}

func allBitsSet(num int) bool {
    return num == (1<<32 - 1)
}

func anyBitsSet(num int) bool {
    return num > 0
}

func modInverse(x, mod int) int {
    return powMod(x, mod-2, mod)
}

func gcd(a, b int) int {
    for b!= 0 {
        a, b = b, a%b
    }
    return a
}

func lcm(a, b int) int {
    return a * b / gcd(a, b)
}

func isPrime(n int) bool {
    if n <= 1 {
        return false
    }
    for i := 2; i*i <= n; i++ {
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
    res := n
    for!isPrime(res) {
        res++
    }
    return res
}

func prevPrime(n int) int {
    if n <= 2 {
        return 2
    }
    res := n
    for!isPrime(res) {
        res--
    }
    return res
}

func randInt() int {
    res := rand.nextInt()
    return res
}

func randIntN(n int) int {
    res := rand.nextInt() % n
    return res
}

func randIntRange(from, to int) int {
    res := rand.nextInt() % (to-from+1) + from
    return res
}

func randFloat64() float64 {
    res := rand.nextFloat64()
    return res
}

func randFloat64Range(from, to float64) float64 {
    res := rand.nextFloat64() * (to-from) + from
    return res
}

func shuffleIntSlice(a []int) {
    for i := len(a) - 1; i > 0; i-- {
        j := randIntRange(0, i)
        a[i], a[j] = a[j], a[i]
    }
}

func shuffleInt64Slice(a []int64) {
    for i := len(a) - 1; i > 0; i-- {
        j := randIntRange(0, i)
        a[i], a[j] = a[j], a[i]
    }
}

func shuffleStringSlice(a []string) {
    for i := len(a) - 1; i > 0; i-- {
        j := randIntRange(0, i)
        a[i], a[j] = a[j], a[i]
    }
}

func reverseIntSlice(a []int) {
    for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
        a[i], a[j] = a[j], a[i]
    }
}

func reverseInt64Slice(a []int64) {
    for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
        a[i], a[j] = a[j], a[i]
    }
}

func reverseStringSlice(a []string) {
    for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
        a[i], a[j] = a[j], a[i]
    }
}

func uniqueIntSlice(a []int) []int {
    keys := make(map[int]bool)
    list := []int{}
    for _, entry := range a {
        if _, value := keys[entry];!value {
            keys[entry] = true
            list = append(list, entry)
        }
    }
    return list
}

func uniqueInt64Slice(a []int64) []int64 {
    keys := make(map[int64]bool)
    list := []int64{}
    for _, entry := range a {
        if _, value := keys[entry];!value {
            keys[entry] = true
            list = append(list, entry)
        }
    }
    return list
}

func uniqueStringSlice(a []string) []string {
    keys := make(map[string]bool)
    list := []string{}
    for _, entry := range a {
        if _, value := keys[entry];!value {
            keys[entry] = true
            list = append(list, entry)
        }
    }
    return list
}

func containsInt(a []int, x int) bool {
    for _, n := range a {
        if x == n {
            return true
        }
    }
    return false
}

func containsInt64(a []int64, x int64) bool {
    for _, n := range a {
        if x == n {
            return true
        }
    }
    return false
}

func containsString(a []string, x string) bool {
    for _, n := range a {
        if x == n {
            return true
        }
    }
    return false
}

func sumIntSlice(a []int) int {
    sum := 0
    for _, num := range a {
        sum += num
    }
    return sum
}

func sumInt64Slice(a []int64) int64 {
    sum := int64(0)
    for _, num := range a {
        sum += num
    }
    return sum
}

func sumFloat64Slice(a []float64) float64 {
    sum := float64(0)
    for _, num := range a {
        sum += num
    }
    return sum
}

func productIntSlice(a []int) int {
    product := 1
    for _, num := range a {
        product *= num
    }
    return product
}

func productInt64Slice(a []int64) int64 {
    product := int64(1)
    for _, num := range a {
        product *= num
    }
    return product
}

func minIntSlice(a []int) int {
    res := a[0]
    for _, num := range a {
        if num < res {
            res = num
        }
    }
    return res
}

func maxIntSlice(a []int) int {
    res := a[0]
    for _, num := range a {
        if num > res {
            res = num
        }
    }
    return res
}

func minInt64Slice(a []int64) int64 {
    res := a[0]
    for _, num := range a {
        if num < res {
            res = num
        }
    }
    return res
}

func maxInt64Slice(a []int64) int64 {
    res := a[0]
    for _, num := range a {
        if num > res {
            res = num
        }
    }
    return res
}

func minFloat64Slice(a []float64) float64 {
    res := a[0]
    for _, num := range a {
        if num < res {
            res = num
        }
    }
    return res
}

func maxFloat64Slice(a []float64) float64 {
    res := a[0]
    for _, num := range a {
        if num > res {
            res = num
        }
    }
    return res
}

func argsortInt(a []int) []int {
    indexes := sort.IntSlice(a)
    sorted := make([]int, len(a))
    for i, v := range indexes {
        sorted[i] = v
    }
    return sorted
}

func argsortInt64(a []int64) []int {
    indexes := sort.Int64Slice(a)
    sorted := make([]int, len(a))
    for i, v := range indexes {
        sorted[i] = int(v)
    }
    return sorted
}

func argsortFloat64(a []float64) []int {
    indexes := sort.Float64Slice(a)
    sorted := make([]int, len(a))
    for i, v := range indexes {
        sorted[i] = int(v)
    }
    return sorted
}

func kthLargestInt(a []int, k int) int {
    a = argsortInt(a)
    return a[len(a)-k]
}

func kthLargestInt64(a []int64, k int) int64 {
    a = argsortInt64(a)
    return a[len(a)-k]
}

func kthLargestFloat64(a []float64, k int) float64 {
    a = argsortFloat64(a)
    return a[len(a)-k]
}

func kthSmallestInt(a []int, k int) int {
    a = argsortInt(a)
    return a[k-1]
}

func kthSmallestInt64(a []int64, k int) int64 {
    a = argsortInt64(a)
    return a[k-1]
}

func kthSmallestFloat64(a []float64, k int) float64 {
    a = argsortFloat64(a)
    return a[k-1]
}

func intersectIntSlice(a, b []int) []int {
    res := []int{}
    for _, num := range a {
        if containsInt(b, num) {
            res = append(res, num)
        }
    }
    return res
}

func intersectInt64Slice(a, b []int64) []int64 {
    res := 