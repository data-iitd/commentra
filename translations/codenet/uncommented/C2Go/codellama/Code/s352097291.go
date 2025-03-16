package main
import "fmt"
func main(){
    var c string
    fmt.Scan(&c)
    var ans string
    for i:=0;i<len(c);i++{
        if c[i]!='B'{
            ans += string(c[i])
        }else{
            ans = ans[:len(ans)-1]
        }
    }
    fmt.Println(ans)
}
