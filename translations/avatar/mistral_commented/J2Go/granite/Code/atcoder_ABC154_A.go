
###
// Importing necessary Go libraries
###
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

###
// Main function is the entry point of the Go application
###
func main() {

    // Creating a bufio.Scanner object to read input from the console
    scanner := bufio.NewScanner(os.Stdin)

    // Reading the first line of input as an array of strings
    scanner.Scan()
    str := strings.Split(scanner.Text(), " ")

    // Reading the second line of input as separate tokens
    scanner.Scan()
    st := strings.Fields(scanner.Text())

    // Reading the first two integers as input
    a, _ := strconv.Atoi(st[0])
    b, _ := strconv.Atoi(st[1])

    // Reading the third line of input as a string
    scanner.Scan()
    u := scanner.Text()

    // Checking if the first string from the first line matches with the given string 'u'
    if u == str[0] {

        // If the condition is true, then print the result as (a-1) and b
        fmt.Println((a - 1), b)

    } else {

        // If the condition is false, then print the result as a and (b-1)
        fmt.Println(a, (b - 1))
    }

    // Closing the bufio.Scanner object to release the system resources
    scanner.Close()
}

