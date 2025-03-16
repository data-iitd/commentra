package main
import "fmt"
import "os"
import "bufio"
import "strings"

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter a string: ")
    text, _ := reader.ReadString('\n')
    text = strings.Replace(text, "\n", "", -1)
    vo := [ 'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y' ]
    for i := len(text) - 1; i >= 0; i-- {
        if text[i] =='' || text[i] == '?' {
            continue
        } else {
            if text[i] in vo {
                fmt.Println("YES")
            } else {
                fmt.Println("NO")
            }
            break
        }
    }
}

