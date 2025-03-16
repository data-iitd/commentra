<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import "fmt"
import "strings"
func main() {
    var str1, str2, temp string
    fmt.Scanf("%s\n", &str1)
    fmt.Scanf("%s\n", &str2)
    i := len(str1)
    t := i - 1
    if len(str1)!= len(str2) {
        fmt.Println("NO")
    } else {
        for j := 0; str1[j]!= '\0'; j++ {
            temp += string(str1[t])
            t--
        }
        t = 0
        i = 0
        for ; temp[i]!= '\0'; i++ {
            if temp[i] == str2[i] {
                t++
            }
        }
        if len(str2) == t {
            fmt.Println("YES")
        } else {
            fmt.Println("NO")
        }
    }
}
