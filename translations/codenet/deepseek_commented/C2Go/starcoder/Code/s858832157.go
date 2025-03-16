<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var i int = 1
    var Input int
    var InputString string
    var InputStringSlice []string
    var InputStringScanner *bufio.Scanner
    var InputStringScannerErr error

    // Start an infinite loop
    for {
        InputStringScanner = bufio.NewScanner(os.Stdin)
        InputStringScanner.Scan()
        InputString = InputStringScanner.Text()
        InputStringSlice = strings.Split(InputString, " ")
        Input, _ = strconv.Atoi(InputStringSlice[0])
        if Input == 0 {
            break
        }
        fmt.Printf("Case %d: %d\n", i, Input)
        i++
    }
}

