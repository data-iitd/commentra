
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    // Reading the number of rows and columns of the 2D char array from the standard input stream
    nTemp, err := reader.ReadString('\n')
    checkError(err)
    n, err := strconv.Atoi(strings.TrimSpace(nTemp))
    checkError(err)

    // Allocating memory for the 2D char array and the String array
    arr := make([][]byte, n)
    str := make([]string, n)

    // Reading the strings from the standard input stream and storing them in the String array
    for i := 0; i < n; i++ {
        strTemp, err := reader.ReadString('\n')
        checkError(err)
        str[i] = strings.TrimSpace(strTemp)
    }

    // Converting each String to a 2D char array and storing it in the corresponding position of the 2D char array
    for i := 0; i < n; i++ {
        arr[i] = []byte(str[i])
    }

    // Initializing two variables 'a' and 'b' with the characters at the first position of the first row of the 2D char array
    a := arr[0][0]
    b := arr[0][1]

    // Checking if the first characters of the first row are equal or not
    if a == b {
        fmt.Println("NO") // Printing "NO" if they are equal
    } else {
        res := true // Initializing a boolean variable'res' to true

        // Checking if there exists any pair of distinct characters in the 2D char array such that they form a diagonal line
        for i := 0; i < n; i++ {
            for j := 0; j < n; j++ {
                // Checking if the current pair (i, j) and (j, i) form a diagonal line
                if i == j || i+j == n-1 {
                    // Checking if the characters at the current position of the 2D char array are equal to 'a' or 'b'
                    if arr[i][j]!= a {
                        res = false // Setting'res' to false if any pair of distinct characters is found on a diagonal line
                        break // Exiting the inner loop as soon as a pair of distinct characters is found
                    }
                } else {
                    // Checking if the characters at the current position of the 2D char array are equal to 'b'
                    if arr[i][j]!= b {
                        res = false // Setting'res' to false if any character other than 'a' or 'b' is found at a position not on a diagonal line
                        break // Exiting the inner loop as soon as a character other than 'a' or 'b' is found
                    }
                }
            }
        }

        // Printing "YES" if all the characters in the 2D char array form either a single diagonal line of 'a's and 'b's or two separate diagonal lines of 'a's and 'b's
        if res {
            fmt.Println("YES")
        } else {
            fmt.Println("NO") // Printing "NO" if any character other than 'a' or 'b' is found at a position not on a diagonal line
        }
    }
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

// END-OF-CODE