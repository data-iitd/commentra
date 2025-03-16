
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
    var err error
    var a []int
    var avg, s, ans float64

    // Input the number of elements
    fmt.Fscanf(reader, "%d\n", &n)

    // Loop to read n elements into the array and calculate their sum
    for i := 0; i < n; i++ {
        var input string
        input, err = reader.ReadString('\n')
        if err!= nil {
            fmt.Println(err)
            return
        }
        a = append(a, int( MustParseInt(input) ))
        avg += float64(a[i])
    }

    // Calculate the average of the elements
    avg /= float64(n)

    // Initialize the smallest difference with the absolute difference of the first element from the average
    s = float64( abs(a[0] - int(avg)) )
    ans = 0

    // Loop to find the index of the element closest to the average
    for i := 1; i < n; i++ {
        // Check if the current element's difference from the average is smaller than the smallest found so far
        if s > float64( abs(a[i] - int(avg)) ) {
            s = float64( abs(a[i] - int(avg)) )
            ans = float64(i)
        }
    }

    // Output the index of the element closest to the average
    fmt.Println(int(ans))
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func MustParseInt(s string) int64 {
    s = strings.TrimSpace(s)
    n, err := strconv.ParseInt(s, 10, 64)
    if err!= nil {
        panic(err)
    }
    return n
}

