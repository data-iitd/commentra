package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Read the number of elements
    N := nextInt()
    // Read the heights into a slice
    h := nextInts(N)

    // Initialize a dynamic programming slice to store minimum costs
    dp := make([]int, N)
    for i := 0; i < N; i++ {
        dp[i] = 0 // Set initial values to zero
    }
    
    // Base case: cost to jump from the first to the second height
    dp[1] = Abs(h[0] - h[1])

    // Fill the dp slice with minimum costs for each position
    for i := 2; i < N; i++ {
        dp[i] = Min([]int{
            dp[i-1] + Abs(h[i] - h[i-1]), // Cost from the previous height
            dp[i-2] + Abs(h[i] - h[i-2]), // Cost from two heights back
        })
    }

    // Output the minimum cost to reach the last height
    fmt.Println(dp[N-1])
}

/* templates */

// Max function returns the maximum value from a slice of integers
func Max(a []int) int {
    r := a[0]
    for i := 0; i < len(a); i++ {
        if r < a[i] {
            r = a[i]
        }
    }
    return r
}

// Min function returns the minimum value from a slice of integers
func Min(a []int) int {
    r := a[0]
    for i := 0; i < len(a); i++ {
        if r > a[i] {
            r = a[i]
        }
    }
    return r
}

// Sum function calculates the sum of a slice of integers
func Sum(a []int) (r int) {
    for i := range a {
        r += a[i]
    }
    return r
}

// Abs function returns the absolute value of an integer
func Abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

// Pair struct represents a pair of integers
type Pair struct {
    a, b int
}

// Pairs is a slice of Pair
type Pairs []Pair

// Len returns the length of the Pairs slice
func (p Pairs) Len() int {
    return len(p)
}

// Swap exchanges the elements at indices i and j in the Pairs slice
func (p Pairs) Swap(i, j int) {
    p[i], p[j] = p[j], p[i]
}

// Less compares two pairs based on the second element of the pair
func (p Pairs) Less(i, j int) bool {
    return p[i].b < p[j].b
}

// nextReader is a function that reads input from standard input
var nextReader func() string

// init function initializes the nextReader function
func init() {
    nextReader = NewScanner()
}

// NewScanner creates a new scanner for reading input
func NewScanner() func() string {
    r := bufio.NewScanner(os.Stdin)
    r.Buffer(make([]byte, 1024), int(1e+11))
    r.Split(bufio.ScanWords)
    return func() string {
        r.Scan()
        return r.Text()
    }
}

// nextString reads the next string from input
func nextString() string {
    return nextReader()
}

// nextInt64 reads the next int64 from input
func nextInt64() int64 {
    v, _ := strconv.ParseInt(nextReader(), 10, 64)
    return v
}

// nextInt reads the next int from input
func nextInt() int {
    v, _ := strconv.Atoi(nextReader())
    return v
}

// nextInts reads n integers from input and returns them as a slice
func nextInts(n int) []int {
    r := make([]int, n)
    for i := 0; i < n; i++ {
        r[i] = nextInt()
    }
    return r
}

// nextStrings reads n strings from input and returns them as a slice
func nextStrings(n int) []string {
    r := make([]string, n)
    for i := 0; i < n; i++ {
        r[i] = nextString()
    }
    return r
}

// nextFloat64 reads the next float64 from input
func nextFloat64() float64 {
    f, _ := strconv.ParseFloat(nextReader(), 64)
    return f
}
