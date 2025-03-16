<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read input from stdin
    reader := bufio.NewReader(os.Stdin)

    // Read the first line of input
    line, err := reader.ReadString('\n')
    if err!= nil {
        fmt.Println(err)
        return
    }

    // Split the input into two space-separated integers
    input := strings.Split(line, " ")
    N, err := strconv.Atoi(input[0])
    if err!= nil {
        fmt.Println(err)
        return
    }
    K, err := strconv.Atoi(input[1])
    if err!= nil {
        fmt.Println(err)
        return
    }

    // Read the next N lines of input
    var v []int
    for i := 0; i < N; i++ {
        line, err := reader.ReadString('\n')
        if err!= nil {
            fmt.Println(err)
            return
        }

        // Split the input into a single integer
        input := strings.Split(line, " ")
        val, err := strconv.Atoi(input[0])
        if err!= nil {
            fmt.Println(err)
            return
        }

        // Append the integer to the vector
        v = append(v, val)
    }

    // Calculate the number of subarrays of size K that can be formed from the vector 'v'
    count := ((N - 1) + ((K - 1) - 1)) / (K - 1)

    // Output the result to the console
    fmt.Println(count)
}

