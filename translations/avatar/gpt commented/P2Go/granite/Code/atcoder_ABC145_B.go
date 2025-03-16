
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    // Read an integer input from the user
    n, _ := strconv.Atoi(readln(reader))

    // Read a string input from the user
    s := readln(reader)

    // Check if the length of the string is odd
    if n%2!= 0 {
        // If the length is odd, print 'No' since it cannot be split into two equal halves
        fmt.Println("No")
    }
    // Check if the first half of the string is equal to the second half
    else if s[:n/2] == s[n/2:] {
        // If both halves are equal, print 'Yes'
        fmt.Println("Yes")
    } else {
        // If the halves are not equal, print 'No'
        fmt.Println("No")
    }
}

func readln(reader *bufio.Reader) string {
    buf := make([]byte, 0)
    for {
        line, prefix, err := reader.ReadLine()
        if err!= nil {
            panic(err)
        }
        buf = append(buf, line...)
        if prefix == false {
            break
        }
    }
    return string(buf)
}
