
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var n int
    var a []int
    var avg, s, ans float64
    
    // Step 1: Input the number of elements (n) and the array elements (a[100])
    fmt.Fscanf(reader, "%d\n", &n)
    for i := 0; i < n; i++ {
        var tmp string
        fmt.Fscanf(reader, "%s\n", &tmp)
        num, _ := strconv.Atoi(tmp)
        a = append(a, num)
        avg += float64(num)
    }
    
    // Step 2: Calculate the average of the array elements
    avg /= float64(n)
    
    // Step 3: Find the element closest to the average
    s = float64(abs(a[0]-int(avg)))
    ans = 0
    for i := 1; i < n; i++ {
        if s > float64(abs(a[i]-int(avg))) {
            s = float64(abs(a[i]-int(avg)))
            ans = float64(i)
        }
    }
    
    // Step 4: Output the index of the closest element
    fmt.Println(int(ans))
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

