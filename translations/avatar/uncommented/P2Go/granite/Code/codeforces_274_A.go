
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
    var num, k int
    var err error
    var temp int
    var different map[int]bool
    var arr []int
    var str string
    str, err = reader.ReadString('\n')
    str = strings.TrimSpace(str)
    strs := strings.Split(str, " ")
    num, err = strconv.Atoi(strs[0])
    k, err = strconv.Atoi(strs[1])
    str, err = reader.ReadString('\n')
    str = strings.TrimSpace(str)
    strs = strings.Split(str, " ")
    for _, str := range strs {
        temp, err = strconv.Atoi(str)
        arr = append(arr, temp)
    }
    different = make(map[int]bool)
    for _, x := range arr {
        if x%k!= 0 ||!different[x/k] {
            different[x] = true
        }
    }
    fmt.Println(len(different))
}
