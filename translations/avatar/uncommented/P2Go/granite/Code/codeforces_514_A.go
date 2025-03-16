
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter a number: ")
    text, _ := reader.ReadString('\n')
    number, _ := strconv.Atoi(text)
    result := ""
    if len(text)!= 1 {
        if string(text[0]) == "9" {
            result = "9"
            text = text[1:]
        }
        for _, char := range text {
            if int(char-'0') > 4 {
                n := 9 - int(char-'0')
                result += string(n + '0')
            } else {
                result += string(char)
            }
        }
    } else {
        result = text
    }
    number, _ = strconv.Atoi(result)
    fmt.Println(number)
}
