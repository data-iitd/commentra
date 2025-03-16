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
    // Declare two arrays to store the number of passengers in each train and bus
    var train [2]int
    var bus [2]int

    // Read the number of passengers in each train from the user
    fmt.Scanf("%d %d", &train[0], &train[1])

    // Comment: Read the number of passengers in the first and second train from the user

    // Read the number of passengers in each bus from the user
    fmt.Scanf("%d %d", &bus[0], &bus[1])

    // Comment: Read the number of passengers in the first and second bus from the user

    // Calculate the total number of passengers
    fmt.Println(int(math.Max(float64(train[0]), float64(train[1])) + math.Max(float64(bus[0]), float64(bus[1]))))

    // Comment: Output the total number of passengers in both train and bus

    // 