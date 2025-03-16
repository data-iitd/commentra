package main
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)
func main() {
    // Read the values of S and W from a single line of input
    reader := bufio.NewReaderSize(os.Stdin, 16)
    fmt.Fscan(reader, &S, &W)
    // Check if the value of W is greater than or equal to S
    // If true, print "unsafe"
    if S <= W {
        fmt.Println("unsafe")
    } else {
        fmt.Println("safe")
    }
}
