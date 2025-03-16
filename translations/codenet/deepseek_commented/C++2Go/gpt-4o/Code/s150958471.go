package main

import (
    "fmt"
)

func main() {
    // Declare arrays
    // Two arrays, `train` and `bus`, are declared to store the values.
    var train [2]int
    var bus [2]int

    // Input values
    // The values for `train` and `bus` are taken from the user.
    fmt.Scan(&train[0], &train[1])
    fmt.Scan(&bus[0], &bus[1])

    // Calculate the sum
    // The code then calculates the sum of the minimum values from both arrays.
    minTrain := train[0]
    if train[1] < minTrain {
        minTrain = train[1]
    }

    minBus := bus[0]
    if bus[1] < minBus {
        minBus = bus[1]
    }

    // Output the result
    // Finally, the result is printed to the console.
    fmt.Println(minTrain + minBus)
}

// <END-OF-CODE>
