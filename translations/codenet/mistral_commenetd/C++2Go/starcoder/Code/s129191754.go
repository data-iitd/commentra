
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    // Read the number of elements in the vector
    reader := bufio.NewReader(os.Stdin)
    fmt.Fscanln(reader, &n)

    // Initialize a vector of size n with default-constructed elements
    a := make([]int, n)

    // Read the elements of the vector
    for i := 0; i < n; i++ {
        fmt.Fscanln(reader, &a[i])
    }

    // Sort the vector in ascending order
    sort.Ints(a)

    // Check if there are any consecutive elements in the sorted vector
    for i := 0; i < n-1; i++ {
        // If there are consecutive elements, print "NO" and exit the program
        if a[i] == a[i+1] {
            fmt.Println("NO")
            return
        }
    }

    // If no consecutive elements were found, print "YES"
    fmt.Println("YES")
}

