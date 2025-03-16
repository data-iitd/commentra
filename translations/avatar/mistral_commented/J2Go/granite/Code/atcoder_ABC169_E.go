

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    num := 998244353
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)

    n, _ := strconv.Atoi(reader.ReadLine())
    a := make([]int, n)
    b := make([]int, n)

    for i := 0; i < n; i++ {
        s := strings.Split(reader.ReadLine(), " ")
        a[i], _ = strconv.Atoi(s[0])
        b[i], _ = strconv.Atoi(s[1])
    }

    // Sorting the arrays in ascending order
    for i := 0; i < n; i++ {
        for j := i + 1; j < n; j++ {
            if a[i] > a[j] {
                a[i], a[j] = a[j], a[i]
            }
            if b[i] > b[j] {
                b[i], b[j] = b[j], b[i]
            }
        }
    }

    if n%2 == 1 {
        writer.WriteString(strconv.Itoa(b[n/2]-a[n/2]+1) + "\n")
    } else {
        writer.WriteString(strconv.Itoa(int((float64(b[n/2]+b[n/2-1])/2+0.5)-float64(a[n/2]+a[n/2-1])/2+0.5)) + "\n")
    }

    writer.Flush()
}

These comments should provide a clear understanding of the code logic for anyone who reads it.

Translate the above Go code to C++ and end with comment "