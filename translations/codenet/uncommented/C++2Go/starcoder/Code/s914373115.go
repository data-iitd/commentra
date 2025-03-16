package main
import "fmt"

func main() {
    B()
}

func B() {
    var x, sum int64
    fmt.Scanf("%d\n", &x)
    sum = 100
    for i := 0; sum < x; i++ {
        sum += sum / 100
    }
    fmt.Println(i)
}

