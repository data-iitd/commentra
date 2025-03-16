package main
import "fmt"
import "os"
import "strconv"
import "strings"

func main() {
    a := strings.Split(os.Args[1], " ")
    for e, i := range a {
        if i == "0" {
            fmt.Println(e + 1)
            break
        }
    }
}

