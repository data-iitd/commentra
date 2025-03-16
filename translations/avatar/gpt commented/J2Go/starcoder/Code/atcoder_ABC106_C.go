package main

import "fmt"

func main() {
    // Reading a string input from the user
    var str string
    fmt.Scanf("%s", &str)
    
    // Converting the string to a character array for easier manipulation
    c := []rune(str)
    
    // Reading a long integer input from the user
    var k int64
    fmt.Scanf("%d", &k)
    
    // Getting the length of the input string
    n := len(str)
    
    // Looping through the first k characters of the character array
    for i := 0; i < k; i++ {
        // Checking if the current character is '1'
        if c[i] == '1' {
            // If it's the last character in the range, print 1 and exit
            if i == k - 1 {
                fmt.Println(1)
                return
            }
        } else {
            // If the current character is not '1', print it and exit
            fmt.Println(c[i])
            return
        }
    }
}

