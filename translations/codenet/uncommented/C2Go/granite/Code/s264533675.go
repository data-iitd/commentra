
package main

import "fmt"
import "bufio"
import "os"

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter a string: ")
    text, _ := reader.ReadString('\n')
    text = text[:len(text)-1]
    text = text[:5] + " " + text[6:13] + " " + text[14:]
    fmt.Println(text)
}

