

package main
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)
var debug bool = false
func log(text string) {
    if debug {
        fmt.Println(text)
    }
}
// Function to parse input from either user input or a string
func parse_input(lines_as_string string) (c string) {
    global debug
    lines := []string{}
    if lines_as_string == "" {
        debug = false
        lines = append(lines, bufio.NewReader(os.Stdin).ReadString('\n'))
    } else {
        debug = true
        lines = strings.Split(lines_as_string, "\n")
    }
    c = strings.Split(lines[0], " ")[0]
    return
}
// Function to solve the problem by finding the next character in the alphabet
func solve(c string) (result string) {
    a := "abcdefghijklmnopqrstuvwxyz"
    i, _ := strconv.Atoi(string(a[c[0]]))
    result = string(a[i+1])
    return
}
// Main function to orchestrate the execution of the program
func main() {
    result := solve(parse_input())
    fmt.Println(result)
}
// 