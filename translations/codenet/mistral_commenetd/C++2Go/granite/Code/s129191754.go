

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)

    // Read the number of elements in the vector
    nTemp, err := reader.ReadString('\n')
    checkError(err)
    n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
    checkError(err)

    // Initialize a vector of size n with default-constructed elements
    a := make([]int, int(n))

    // Read the elements of the vector
    for i := int64(0); i < n; i++ {
        aTemp, err := reader.ReadString('\n')
        checkError(err)
        a[i], err = strconv.ParseInt(strings.TrimSpace(aTemp), 10, 64)
        checkError(err)
    }

    // Sort the vector in ascending order
    sort.Ints(a)

    // Check if there are any consecutive elements in the sorted vector
    for i := int64(0); i < n-1; i++ {
        // If there are consecutive elements, print "NO" and exit the program
        if a[i] == a[i+1] {
            fmt.Fprintln(writer, "NO")
            writer.Flush()
            return
        }
    }

    // If no consecutive elements were found, print "YES"
    fmt.Fprintln(writer, "YES")
    writer.Flush()
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

