package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Reading input from the console
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter a string: ")
    input, _ := reader.ReadString('\n')
    input = strings.Replace(input, "\n", "", -1)
    n, _ := strconv.Atoi(input)

    // Initializing variables to hold parts of the input string
    a := ""
    b := ""
    str := ""

    // Loop to construct the first half of the string
    for i := 0; i < n/2; i++ {
        a = a + string(input[i]) // Appending characters from the first half of the string to 'a'
    }

    // Checking if the string is made up of two identical halves
    if str == a+a {
        fmt.Println("Yes") // If true, print "Yes"
    } else {
        fmt.Println("No") // If false, print "No"
    }
}

