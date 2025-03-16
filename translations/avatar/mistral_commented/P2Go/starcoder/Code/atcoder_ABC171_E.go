// Importing necessary functions
import "fmt"

// Reading input
var N int
var a []int
fmt.Scanf("%d", &N)
a = make([]int, N)
for i := 0; i < N; i++ {
    fmt.Scanf("%d", &a[i])
}

// Calculating the XOR of all elements in the list 'a'
total := 0
for _, ai := range a {
    total ^= ai
}

// Printing the result
for _, ai := range a {
    fmt.Printf("%d ", ai ^ total)
}

// 