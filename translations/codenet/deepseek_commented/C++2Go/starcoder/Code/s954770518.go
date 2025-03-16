<<<<<<< HEAD
=======
_
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "sort"
<<<<<<< HEAD
    "os"
    "bufio"
    "strconv"
=======
    "bufio"
    "os"
>>>>>>> 98c87cb78a (data updated)
)

func main() {
    var s [11]int
    var i int

    // Step 3: Read input numbers into the array
    for i = 0; i < 10; i++ {
        fmt.Scanf("%d", &s[i])
    }

    // Step 4: Sort the array
    sort.Ints(s[:])

    // Step 5: Print the last four numbers of the sorted array
    for i = 9; i > 6; i-- {
        fmt.Println(s[i])
    }
}

