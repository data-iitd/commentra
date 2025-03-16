package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Creating a BufferedReader object to read input from the console
    reader := bufio.NewReader(os.Stdin)

    // Reading a line of input from the console
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)

    // Splitting the input string into an array of strings using space as delimiter
    x := strings.Split(input, " ")

    // Parsing the first and second elements of the input array into integers 'a' and 'b' respectively
    a, _ := strconv.Atoi(x[0])
    b, _ := strconv.Atoi(x[1])

    // Calculate the value of 'c' by subtracting 'b' multiplied by 2 from 'a'
    c := a - b*2

    // If the value of 'c' is negative, set it to zero
    if c < 0 {
        c = 0
    }

    // Print the value of 'c' to the console
    fmt.Println(c)
}

// <END-OF-CODE>
