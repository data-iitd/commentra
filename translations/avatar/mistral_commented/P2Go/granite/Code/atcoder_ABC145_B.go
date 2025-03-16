
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    // Read an integer value from the user
    nTemp, err := reader.ReadString('\n')
    checkError(err)
    n, err := strconv.ParseInt(nTemp, 10, 64)
    checkError(err)

    // Read a string value from the user
    sTemp, err := reader.ReadString('\n')
    checkError(err)
    s := string(sTemp[:len(sTemp)-1])

    // Check if n is odd
    if n%2!= 0 {
        fmt.Println("No")
    }

    // Check if the first half of the string is equal to the second half
    else if s[:int(n/2)] == s[int(n/2):] {
        fmt.Println("Yes")
    }

    // If the first half is not equal to the second half, print 'No'
    else {
        fmt.Println("No")
    }
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

