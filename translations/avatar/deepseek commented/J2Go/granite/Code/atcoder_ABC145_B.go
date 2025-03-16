

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func cout(str string) {
    fmt.Println(str)
}

func main() {
    reader := bufio.NewReader(os.Stdin)

    // Reading the integer input n
    n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])

    // Reading the string input str
    str := reader.ReadLine()[2 : len(reader.ReadLine())]

    // Constructing the string a by taking the first n/2 characters of str
    a := ""
    for i := 0; i < n/2; i++ {
        a += string(str[i])
    }

    // Checking if str is equal to a + a and printing the result
    if str == a+a {
        cout("Yes")
    } else {
        cout("No")
    }
}

