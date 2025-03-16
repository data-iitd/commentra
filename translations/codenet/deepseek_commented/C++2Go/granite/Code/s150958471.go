
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Include necessary headers
    // The code starts by including necessary headers for input and output operations.
    // Headers for input and output operations are included.

    // Declare arrays
    // Two arrays, `train` and `bus`, are declared to store the values.
    train := [2]int{}
    bus := [2]int{}

    // Input values
    // The values for `train` and `bus` are taken from the user.
    reader := bufio.NewReader(os.Stdin)
    for i := 0; i < 2; i++ {
        input, _ := reader.ReadString('\n')
        value, _ := strconv.Atoi(input)
        if i == 0 {
            train[0] = value
        } else {
            train[1] = value
        }
    }
    for i := 0; i < 2; i++ {
        input, _ := reader.ReadString('\n')
        value, _ := strconv.Atoi(input)
        if i == 0 {
            bus[0] = value
        } else {
            bus[1] = value
        }
    }

    // Calculate the sum
    // The code then calculates the sum of the minimum values from both arrays.
    result := (train[0] + train[1]) / 2 + (bus[0] + bus[1]) / 2

    // Output the result
    // Finally, the result is printed to the console.
    fmt.Println(result)
}

