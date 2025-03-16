

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Create a scanner to read input from the standard input stream
    in := bufio.NewScanner(os.Stdin)

    // Read the first line of input, split by spaces, and store in an array of strings
    in.Scan()
    str := strings.Split(in.Text(), " ")

    // Read the next line of input as integers
    in.Scan()
    st := strings.Fields(in.Text())

    // Parse the first integer from the tokenized input
    a, _ := strconv.Atoi(st[0])

    // Parse the second integer from the tokenized input
    b, _ := strconv.Atoi(st[1])

    // Read another string from the input
    in.Scan()
    u := in.Text()

    // Check if the read string is equal to the first element of the array and print accordingly
    if u == str[0] {
        fmt.Println((a - 1), b)
    } else {
        fmt.Println(a, (b - 1))
    }
}

