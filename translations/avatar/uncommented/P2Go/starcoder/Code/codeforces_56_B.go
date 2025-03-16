package main
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)
    fmt.Println("Enter the number of elements in the array")
    line, _ := reader.ReadString('\n')
    N, _ := strconv.Atoi(strings.TrimSpace(line))
    A := make([]int, N)
    fmt.Println("Enter the elements of the array")
    for i := 0; i < N; i++ {
        line, _ := reader.ReadString('\n')
        A[i], _ = strconv.Atoi(strings.TrimSpace(line))
    }
    mn, mx := N + 1, -1
    for i := 0; i < N; i++ {
        if i + 1!= A[i] {
            mn = min(mn, i)
            mx = max(mx, i)
        }
    }
    if mx == -1 {
        fmt.Println("0 0")
    } else {
        A = append(A[:mn], A[mn:mx+1][::-1]...)
        A = append(A[mx+1:], A[mn+1:]...)
        if sort.IntsAreSorted(A) {
            fmt.Println(mn+1, mx+1)
        } else {
            fmt.Println("0 0")
        }
    }
}

