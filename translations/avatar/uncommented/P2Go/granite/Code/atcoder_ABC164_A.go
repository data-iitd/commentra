
package main
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)
func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("unsafe")
    S, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])
    W, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])
    if S <= W {
        fmt.Println("unsafe")
    } else {
        fmt.Println("safe")
    }
}
