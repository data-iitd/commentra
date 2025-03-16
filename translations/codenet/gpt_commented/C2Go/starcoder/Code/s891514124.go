package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the input from the command line
    input := os.Args[1]

    // Split the input into hours, minutes and seconds
    split := strings.Split(input, ":")

    // Convert the hours, minutes and seconds to integers
    hours, _ := strconv.Atoi(split[0])
    minutes, _ := strconv.Atoi(split[1])
    seconds, _ := strconv.Atoi(split[2])

    // Check if the input seconds are less than 60
    if seconds < 60 {
        // If less than 60 seconds, print the time in the format 0:0:seconds
        fmt.Printf("0:0:%d\n", seconds)
    }
    // Check if the input seconds are less than 3600 (1 hour)
    else if seconds < 3600 {
        // If less than 1 hour, print the time in the format 0:minutes:seconds
        fmt.Printf("0:%d:%d\n", minutes, seconds)
    }
    // If the input seconds are 3600 or more (1 hour or more)
    else {
        // Print the time in the format hours:minutes:seconds
        fmt.Printf("%d:%d:%d\n", hours, minutes, seconds)
    }
}

