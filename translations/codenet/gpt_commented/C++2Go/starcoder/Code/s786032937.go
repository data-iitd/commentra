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
    fmt.Print("Enter the number of sides of the polygon: ")
    input, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(input))
    fmt.Printf("The sum of interior angles of a polygon with %d sides is %d\n", n, (n-2)*180)
}

