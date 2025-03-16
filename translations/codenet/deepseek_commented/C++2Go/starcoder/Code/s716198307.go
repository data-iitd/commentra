<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math"
)

func main() {
    var n int
    var a [100]int
    var avg float64
    var s, ans int

    // Step 1: Input the number of elements (n) and the array elements (a[100])
    fmt.Scanf("%d", &n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &a[i])
        avg += float64(a[i])
    }

    // Step 2: Calculate the average of the array elements
    avg /= float64(n)

    // Step 3: Find the element closest to the average
<<<<<<< HEAD
    s = int(math.Abs(float64(a[0]-avg)))
    ans = 0
    for i := 1; i < n; i++ {
        if s > int(math.Abs(float64(a[i]-avg))) {
            s = int(math.Abs(float64(a[i]-avg)))
=======
    s = int(math.Abs(float64(a[0] - avg)))
    ans = 0
    for i := 1; i < n; i++ {
        if s > int(math.Abs(float64(a[i] - avg))) {
            s = int(math.Abs(float64(a[i] - avg)))
>>>>>>> 98c87cb78a (data updated)
            ans = i
        }
    }

    // Step 4: Output the index of the closest element
    fmt.Println(ans)
}

