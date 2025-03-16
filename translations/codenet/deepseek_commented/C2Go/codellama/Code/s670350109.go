package main
import "fmt"
func main() {
    var str1,str2,temp string
    fmt.Scan(&str1)
    fmt.Scan(&str2)
    var i,j,t int
    i=len(str1)
    t=i-1
    if len(str1)!=len(str2) {
        fmt.Println("NO")
    } else {
        for j=0;str1[j]!='\0';j++ {
            temp=string(str1[t])+temp
            t--
        }
        t=0
        i=0
        for i=0;temp[i]!='\0';i++ {
            if temp[i]==str2[i] {
                t++
            }
        }
        if len(str2)==t {
            fmt.Println("YES")
        } else {
            fmt.Println("NO")
        }
    }
}
