package main
import "fmt"
import "os"
import "bufio"
func main() {
    reader := bufio.NewReader(os.Stdin)
    var N, d, x int
    fmt.Fscan(reader, &N, &d, &x)
    ret := 0
    for N > 0 {
        ret += d + (N-0.5)*x
        d += d/N + (5*x)/(2*N)
        x += 2*x/N
        N--
    }
    fmt.Println(ret)
}
