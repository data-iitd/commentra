

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
    fmt.Print("Enter a string: ")
    text, _ := reader.ReadString('\n')
    text = strings.TrimSpace(text)
    parts := strings.Split(text, ".")
    firstPart := strings.Split(parts[0], "")
    secondPart := strings.Split(parts[1], "")
    i, _ := strconv.Atoi(secondPart[0])
    if firstPart[len(firstPart)-1] == "9" {
        fmt.Println("GOTO Vasilisa.")
    } else if firstPart[len(firstPart)-1]!= "9" && i < 5 {
        fmt.Println(strings.Join(firstPart, ""))
    } else {
        firstPart[len(firstPart)-1] = string(firstPart[len(firstPart)-1][0] + 1)
        fmt.Println(strings.Join(firstPart, ""))
    }
}

