<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

const N = 2000

var num1, math [N+1]int

func main() {
    var a, num2, ans, sum int
    for i := 0; i < N+1; i++ {
        math[i] = 0
    }
    fmt.Scanf("%d", &num1)
    for i := 0; i < num1; i++ {
        fmt.Scanf("%d", &a)
        sum += a
        for j := sum - a; j >= 0; j-- {
            if math[j] == 1 {
                math[j+a] = 1
            }
        }
    }
    fmt.Scanf("%d", &num2)
    for i := 0; i < num2; i++ {
        fmt.Scanf("%d", &ans)
        if math[ans] == 1 {
            fmt.Println("yes")
        } else {
            fmt.Println("no")
        }
    }
}

