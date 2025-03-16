
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare arrays to hold the arrival times for train and bus
    var train [2]int
    var bus [2]int

    // Create a scanner to read input from the standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Input the arrival times for the train
    for i := 0; i < 2; i++ {
        scanner.Scan()
        train[i], _ = strconv.Atoi(scanner.Text())
    }
    // Input the arrival times for the bus
    for i := 0; i < 2; i++ {
        scanner.Scan()
        bus[i], _ = strconv.Atoi(scanner.Text())
    }

    // Calculate the minimum arrival time between the two times for train and bus,
    // and output the total minimum arrival time
    fmt.Println(min(train[0], train[1]) + min(bus[0], bus[1]))
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

