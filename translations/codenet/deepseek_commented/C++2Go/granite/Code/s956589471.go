
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Step 3: Declare variables to store input values
    var a, b, c, d, e, k int

    // Step 4: Read input values from the user
    reader := bufio.NewReader(os.Stdin)
    input, _ := reader.ReadString('\n')
    values := strings.Split(input, " ")
    a, _ = strconv.Atoi(values[0])
    b, _ = strconv.Atoi(values[1])
    c, _ = strconv.Atoi(values[2])
    d, _ = strconv.Atoi(values[3])
    e, _ = strconv.Atoi(values[4])
    k, _ = strconv.Atoi(values[5])

    // Step 5: Calculate the difference between e and a and check if it is less than or equal to k
    if e-a <= k {
        fmt.Println("Yay!")
    } else {
        fmt.Println(":(")
    }

    // Step 7: Return 0 to indicate successful execution
    os.Exit(0)
}

