<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var str string
    var tmp string
    var sum int

    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        str = scanner.Text()
        if str == "0" {
            break
        }
        sum = 0
<<<<<<< HEAD
        for _, c := range str {
            tmp = string(c)
=======
        for _, v := range str {
            tmp = string(v)
>>>>>>> 98c87cb78a (data updated)
            num, _ := strconv.Atoi(tmp)
            sum += num
        }
        fmt.Println(sum)
    }
}
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
