
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var n, k int
    var err error
    var p []int

    // Read the number of elements (n) and the number of elements to sum (k)
    n, err = strconv.Atoi(reader.ReadLine())
    if err!= nil {
        fmt.Println(err)
        return
    }
    k, err = strconv.Atoi(reader.ReadLine())
    if err!= nil {
        fmt.Println(err)
        return
    }

    // Read n integers and store them in the array p
    for i := 0; i < n; i++ {
        line, _, err := reader.ReadLine()
        if err!= nil {
            fmt.Println(err)
            return
        }
        num, err := strconv.Atoi(string(line))
        if err!= nil {
            fmt.Println(err)
            return
        }
        p = append(p, num)
    }

    // Perform selection sort on the array p
    for i := 0; i < n; i++ {
        l := i
        for j := i + 1; j < n; j++ {
            if p[j] < p[l] {
                l = j
            }
        }
        if l!= i {
            m := p[i]
            p[i] = p[l]
            p[l] = m
        }
    }

    // Sum the first k elements of the sorted array
    sum := 0
    for i := 0; i < k; i++ {
        sum += p[i]
    }

    // Print the sum of the first k elements
    fmt.Println(sum)
}

