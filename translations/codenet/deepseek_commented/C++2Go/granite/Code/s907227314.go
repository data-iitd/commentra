
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter a string: ")
    text, _ := reader.ReadString('\n')
    text = strings.TrimSpace(text)

    a := -1
    z := -1

    // The first for loop iterates through the string to find the position of the first occurrence of 'A'
    for i, char := range text {
        if char == 'A' {
            a = i
            break
        }
    }

    // The second for loop iterates through the string in reverse to find the position of the last occurrence of 'Z'
    for i := len(text) - 1; i >= 0; i-- {
        if text[i] == 'Z' {
            z = i
            break
        }
    }

    // Calculate the length of the substring between the first 'A' and the last 'Z' and print it
    if a!= -1 && z!= -1 {
        length := z - a + 1
        fmt.Println(length)
    }

    // 