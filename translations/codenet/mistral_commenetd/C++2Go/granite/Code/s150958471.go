
package main

import "fmt"

func main() {
    // Declare two arrays to store the number of passengers in each train and bus
    var train [2]int
    var bus [2]int

    // Read the number of passengers in each train from the user
    fmt.Scan(&train[0], &train[1])

    // Comment: Read the number of passengers in the first and second train from the user

    // Read the number of passengers in each bus from the user
    fmt.Scan(&bus[0], &bus[1])

    // Comment: Read the number of passengers in the first and second bus from the user

    // Calculate the total number of passengers
    fmt.Println(min(train[0], train[1]) + min(bus[0], bus[1]))

    // Comment: Output the total number of passengers in both train and bus

    // Define a function to calculate the minimum value of two integers
    func min(a, b int) int {
        if a < b {
            return a
        }
        return b
    }
}

