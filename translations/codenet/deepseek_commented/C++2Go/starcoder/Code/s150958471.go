<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
    // Declare arrays
    // Two arrays, `train` and `bus`, are declared to store the values.
    var train [2]int
    var bus [2]int

    // Input values
    // The values for `train` and `bus` are taken from the user.
    fmt.Scanf("%d %d\n%d %d", &train[0], &train[1], &bus[0], &bus[1])

    // Calculate the sum
    // The code then calculates the sum of the minimum values from both arrays.
    fmt.Println((train[0] < train[1]) && (train[0] < bus[0]) && (train[0] < bus[1]) && (train[1] < bus[0]) && (train[1] < bus[1]) && (bus[0] < bus[1]))

    // Output the result
    // Finally, the result is printed to the console.
    return
}

