

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Initializing Scanner object to read input from the console
    scanner := bufio.NewScanner(os.Stdin)

    var a int64 // Declaring and initializing integer variable 'a'
    fmt.Fscanf(scanner, "%d", &a) // Reading integer value from the console and assigning it to 'a'

    var b string // Declaring and initializing String variable 'b'
    fmt.Fscanf(scanner, "%s", &b) // Reading String value from the console and assigning it to 'b'

    b = strings.Replace(b, ".", "", -1) // Removing all occurrences of '.' from String 'b'

    bInt, _ := strconv.Atoi(b) // Converting String 'b' to integer and assigning it to 'bInt'

    result := (a * int64(bInt)) / 100 // Multiplying 'a' with 'bInt', then dividing the result by 100 and assigning it to'result'

    fmt.Println(result) // Printing the value of'result' to the console

Translate the above Go code to C++ and end with comment "