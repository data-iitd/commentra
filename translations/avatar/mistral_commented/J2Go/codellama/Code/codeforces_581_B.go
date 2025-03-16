
package main

import (
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

func main() {
    var n int
    var a []int64
    var dp []int64
    var set map[int64]bool

    n = nextInt()
    a = make([]int64, n)
    dp = make([]int64, n+1)
    set = make(map[int64]bool)

    for i := 0; i < n; i++ {
        a[i] = nextInt64()
    }

    dp[n-1] = a[n-1]

    for i := n - 1; i >= 0; i-- {
        dp[i] = int64(math.Max(float64(dp[i+1]), float64(a[i])))
    }

    for i := 0; i < n; i++ {
        if a[i] > dp[i+1] {
            fmt.Printf("0 ")
        } else {
            fmt.Printf("%d ", (dp[i+1]-a[i]+1))
        }
    }

    fmt.Println()
}

func nextInt() int {
    var n int
    fmt.Scan(&n)
    return n
}

func nextInt64() int64 {
    var n int64
    fmt.Scan(&n)
    return n
}

func nextString() string {
    var s string
    fmt.Scan(&s)
    return s
}

func nextFloat() float64 {
    var n float64
    fmt.Scan(&n)
    return n
}

func nextFloat64() float64 {
    var n float64
    fmt.Scan(&n)
    return n
}

func nextLine() string {
    var s string
    fmt.Scan(&s)
    return s
}

func nextLines() []string {
    var s []string
    fmt.Scan(&s)
    return s
}

func nextInts() []int {
    var s []int
    fmt.Scan(&s)
    return s
}

func nextInt64s() []int64 {
    var s []int64
    fmt.Scan(&s)
    return s
}

func nextFloat64s() []float64 {
    var s []float64
    fmt.Scan(&s)
    return s
}

func nextFloat64Lines() [][]float64 {
    var s [][]float64
    fmt.Scan(&s)
    return s
}

func nextIntLines() [][]int {
    var s [][]int
    fmt.Scan(&s)
    return s
}

func nextInt64Lines() [][]int64 {
    var s [][]int64
    fmt.Scan(&s)
    return s
}

func nextStringLines() [][]string {
    var s [][]string
    fmt.Scan(&s)
    return s
}

func nextIntMatrix() [][]int {
    var s [][]int
    fmt.Scan(&s)
    return s
}

func nextInt64Matrix() [][]int64 {
    var s [][]int64
    fmt.Scan(&s)
    return s
}

func nextFloat64Matrix() [][]float64 {
    var s [][]float64
    fmt.Scan(&s)
    return s
}

func nextStringMatrix() [][]string {
    var s [][]string
    fmt.Scan(&s)
    return s
}

func nextIntMatrixLines() [][][]int {
    var s [][][]int
    fmt.Scan(&s)
    return s
}

func nextInt64MatrixLines() [][][]int64 {
    var s [][][]int64
    fmt.Scan(&s)
    return s
}

func nextFloat64MatrixLines() [][][]float64 {
    var s [][][]float64
    fmt.Scan(&s)
    return s
}

func nextStringMatrixLines() [][][]string {
    var s [][][]string
    fmt.Scan(&s)
    return s
}

func nextIntMatrixLinesSlice() [][][]int {
    var s [][][]int
    fmt.Scan(&s)
    return s
}

func nextInt64MatrixLinesSlice() [][][]int64 {
    var s [][][]int64
    fmt.Scan(&s)
    return s
}

func nextFloat64MatrixLinesSlice() [][][]float64 {
    var s [][][]float64
    fmt.Scan(&s)
    return s
}

func nextStringMatrixLinesSlice() [][][]string {
    var s [][][]string
    fmt.Scan(&s)
    return s
}

func nextIntMatrixSlice() [][]int {
    var s [][]int
    fmt.Scan(&s)
    return s
}

func nextInt64MatrixSlice() [][]int64 {
    var s [][]int64
    fmt.Scan(&s)
    return s
}

func nextFloat64MatrixSlice() [][]float64 {
    var s [][]float64
    fmt.Scan(&s)
    return s
}

func nextStringMatrixSlice() [][]string {
    var s [][]string
    fmt.Scan(&s)
    return s
}

func nextIntMatrixSliceLines() [][][]int {
    var s [][][]int
    fmt.Scan(&s)
    return s
}

func nextInt64MatrixSliceLines() [][][]int64 {
    var s [][][]int64
    fmt.Scan(&s)
    return s
}

func nextFloat64MatrixSliceLines() [][][]float64 {
    var s [][][]float64
    fmt.Scan(&s)
    return s
}

func nextStringMatrixSliceLines() [][][]string {
    var s [][][]string
    fmt.Scan(&s)
    return s
}

func nextIntMatrixSliceSlice() [][][]int {
    var s [][][]int
    fmt.Scan(&s)
    return s
}

func nextInt64MatrixSliceSlice() [][][]int64 {
    var s [][][]int64
    fmt.Scan(&s)
    return s
}

func nextFloat64MatrixSliceSlice() [][][]float64 {
    var s [][][]float64
    fmt.Scan(&s)
    return s
}

func nextStringMatrixSliceSlice() [][][]string {
    var s [][][]string
    fmt.Scan(&s)
    return s
}

func nextIntMatrixSliceSliceLines() [][][][]int {
    var s [][][][]int
    fmt.Scan(&s)
    return s
}

func nextInt64MatrixSliceSliceLines() [][][][]int64 {
    var s [][][][]int64
    fmt.Scan(&s)
    return s
}

func nextFloat64MatrixSliceSliceLines() [][][][]float64 {
    var s [][][][]float64
    fmt.Scan(&s)
    return s
}

func nextStringMatrixSliceSliceLines() [][][][]string {
    var s [][][][]string
    fmt.Scan(&s)
    return s
}

func nextIntMatrixSliceSliceSlice() [][][][]int {
    var s [][][][]int
    fmt.Scan(&s)
    return s
}

func nextInt64MatrixSliceSliceSlice() [][][][]int64 {
    var s [][][][]int64
    fmt.Scan(&s)
    return s
}

func nextFloat64MatrixSliceSliceSlice() [][][][]float64 {
    var s [][][][]float64
    fmt.Scan(&s)
    return s
}

func nextStringMatrixSliceSliceSlice() [][][][]string {
    var s [][][][]string
    fmt.Scan(&s)
    return s
}

func nextIntMatrixSliceSliceSliceLines() [][][][][]int {
    var s [][][][][]int
    fmt.Scan(&s)
    return s
}

func nextInt64MatrixSliceSliceSliceLines() [][][][][]int64 {
    var s [][][][][]int64
    fmt.Scan(&s)
    return s
}

func nextFloat64MatrixSliceSliceSliceLines() [][][][][]float64 {
    var s [][][][][]float64
    fmt.Scan(&s)
    return s
}

func nextStringMatrixSliceSliceSliceLines() [][][][][]string {
    var s [][][][][]string
    fmt.Scan(&s)
    return s
}

func nextIntMatrixSliceSliceSliceSlice() [][][][][]int {
    var s [][][][][]int
    fmt.Scan(&s)
    return s
}

func nextInt64MatrixSliceSliceSliceSlice() [][][][][]int64 {
    var s [][][][][]int64
    fmt.Scan(&s)
    return s
}

func nextFloat64MatrixSliceSliceSliceSlice() [][][][][]float64 {
    var s [][][][][]float64
    fmt.Scan(&s)
    return s
}

func nextStringMatrixSliceSliceSliceSlice() [][][][][]string {
    var s [][][][][]string
    fmt.Scan(&s)
    return s
}

func nextIntMatrixSliceSliceSliceSliceLines() [][][][][][]int {
    var s [][][][][][]int
    fmt.Scan(&s)
    return s
}

func nextInt64MatrixSliceSliceSliceSliceLines() [][][][][][]int64 {
    var s [][][][][][]int64
    fmt.Scan(&s)
    return s
}

func nextFloat64MatrixSliceSliceSliceSliceLines() [][][][][][]float64 {
    var s [][][][][][]float64
    fmt.Scan(&s)
    return s
}

func nextStringMatrixSliceSliceSliceSliceLines() [][][][][][]string {
    var s [][][][][][]string
    fmt.Scan(&s)
    return s
}

func nextIntMatrixSliceSliceSliceSliceSlice() [][][][][][]int {
    var s [][][][][][]int
    fmt.Scan(&s)
    return s
}

func nextInt64MatrixSliceSliceSliceSliceSlice() [][][][][][]int64 {
    var s [][][][][][]int64
    fmt.Scan(&s)
    return s
}

func nextFloat64MatrixSliceSliceSliceSliceSlice() [][][][][][]float64 {
    var s [][][][][][]float64
    fmt.Scan(&s)
    return s
}

func nextStringMatrixSliceSliceSliceSliceSlice() [][][][][][]string {
    var s [][][][][][]string
    fmt.Scan(&s)
    return s
}

func nextIntMatrixSliceSliceSliceSliceSliceLines() [][][][][][][]int {
    var s [][][][][][][]int
    fmt.Scan(&s)
    return s
}

func nextInt64MatrixSliceSliceSliceSliceSliceLines() [][][][][][][]int64 {
    var s [][][][][][][]int64
    fmt.Scan(&s)
    return s
}

func nextFloat64MatrixSliceSliceSliceSliceSliceLines() [][][][][][][]float64 {
    var s [][][][][][][]float64
    fmt.Scan(&s)
    return s
}

func nextStringMatrixSliceSliceSliceSliceSliceLines() [][][][][][][]string {
    var s [][][][][][][]string
    fmt.Scan(&s)
    return s
}

func nextIntMatrixSliceSliceSliceSliceSliceSlice() [][][][][][][]int {
    var s [][][][][][][]int
    fmt.Scan(&s)
    return s
}

func nextInt64MatrixSliceSliceSliceSliceSliceSlice() [][][][][][][]int64 {
    var s [][][][][][][]int64
    fmt.Scan(&s)
    return s
}

func nextFloat64MatrixSliceSliceSliceSliceSliceSlice() [][][][][][][]float64 {
    var s [][][][][][][]float64
    fmt.Scan(&s)
    return s
}

func nextStringMatrixSliceSliceSliceSliceSliceSlice() [][][][][][][]string {
    var s [][][][][][][]string
    fmt.Scan(&s)
    return s
}

func nextIntMatrixSliceSliceSliceSliceSliceSliceLines() [][][][][][][][]int {
    var s [][][][][][][][]int
    fmt.Scan(&s)
    return s
}

func nextInt64MatrixSliceSliceSliceSliceSliceSliceLines() [][][][][][][][]int64 {
    var s [][][][][][][][]int64
    fmt.Scan(&s)
    return s
}

func nextFloat64MatrixSliceSliceSliceSliceSliceSliceLines() [][][][][][][][]float64 {
    var s [][][][][][][][]float64
    fmt.Scan(&s)
    return s
}

func nextStringMatrixSliceSliceSliceSliceSliceSliceLines() [][][][][][][][]string {
    var s [][][][][][][][]string
    fmt.Scan(&s)
    return s
}

func nextIntMatrixSliceSliceSliceSliceSliceSliceSlice() [][][][][][][][]int {
    var s [][][][][][][][]int
    fmt.Scan(&s)
    return s
}

func nextInt64MatrixSliceSliceSliceSliceSliceSliceSlice() [][][][][][][][]int64 {
    var s [][][][][][][][]int64
    fmt.Scan(&s)
    return s
}

func nextFloat64MatrixSliceSliceSliceSliceSliceSliceSlice() [][][][][][][][]float64 {
    var s [][][][][][][][]float64
    fmt.Scan(&s)
    return s
}

func nextStringMatrixSliceSliceSliceSliceSliceSliceSlice() [][][][][][][][]string {
    var s [][][][][][][][]string
    fmt.Scan(&s)
    return s
}

func nextIntMatrixSliceSliceSliceSliceSliceSliceSliceLines() [][][][][][][][][]int {
    var s [][][][][][][][][]int
    fmt.Scan(&s)
    return s
}

func nextInt64MatrixSliceSliceSliceSliceSliceSliceSliceLines() [][][][][][][][][]int64 {
    var s [][][][][][][][][]int64
    fmt.Scan(&s)
    return s
}

func nextFloat64MatrixSliceSliceSliceSliceSliceSliceSliceLines() [][][][][][][][][]float64 {
    var s [][][][][][][][][]float64
    fmt.Scan(&s)
    return s
}

func nextStringMatrixSliceSliceSliceSliceSliceSliceSliceLines() [][][][][][][][][]string {
    var s [][][][][][][][][]string
    fmt.Scan(&s)
    return s
}

func nextIntMatrixSliceSliceSliceSliceSliceSlice