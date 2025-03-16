
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Creating a Scanner object to read input from the console
    scan := bufio.NewScanner(os.Stdin)

    // Initializing an empty slice to store the input strings
    scList := []string{}

    // Continuously read input lines until an exception occurs (e.g., EOF)
    for scan.Scan() {
        // Adding the input line to the slice
        scList = append(scList, scan.Text())
    }

    // Splitting the first line of input into an array of strings
    numlist := strings.Split(scList[0], " ")

    // Parsing the first number as the count of sheep
    Sheep, _ := strconv.Atoi(numlist[0])

    // Parsing the second number as the count of wolves
    Wolve, _ := strconv.Atoi(numlist[1])

    // Checking if the number of wolves is greater than or equal to the number of sheep
    if Wolve >= Sheep {
        // If wolves are greater than or equal to sheep, it's unsafe
        fmt.Println("unsafe")
    } else {
        // If wolves are fewer than sheep, it's safe
        fmt.Println("safe")
    }
}

