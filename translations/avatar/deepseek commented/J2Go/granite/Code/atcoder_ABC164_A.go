

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
    var sheep, wolves int
    var err error
    for {
        line, _, err := reader.ReadLine()
        if err!= nil {
            break
        }
        numlist := strings.Split(string(line), " ")
        sheep, err = strconv.Atoi(numlist[0])
        if err!= nil {
            break
        }
        wolves, err = strconv.Atoi(numlist[1])
        if err!= nil {
            break
        }
        if wolves >= sheep {
            fmt.Println("unsafe")
        } else {
            fmt.Println("safe")
        }
    }
}
