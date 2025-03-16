package main
import (
    "fmt"
    "os"
    "bufio"
    "strings"
)
func main() {
    reader := bufio.NewReader(os.Stdin)
    s, _ := reader.ReadString('\n')
    s = strings.Replace(s, "\n", "", -1)
    dt := make(map[string]int)
    for i := 0; i < len(s); i++ {
        if _, ok := dt[string(s[i])]; ok {
            dt[string(s[i])] += 1
        } else {
            dt[string(s[i])] = 1
        }
    }
    cnt := 0
    x := true
    for key, value := range dt {
        if value % 2!= 0 && cnt < 1 {
            cnt += 1
        } else if value % 2!= 0 && cnt >= 1 {
            x = false
            break
        }
    }
    if x {
        fmt.Println("First")
    } else if!x && len(s)%2 == 0 {
        fmt.Println("Second")
    } else if!x && len(s)%2!= 0 {
        fmt.Println("First")
    }
}
