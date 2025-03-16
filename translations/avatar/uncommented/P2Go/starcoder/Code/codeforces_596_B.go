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
    fmt.Println("Enter the number of elements in the array")
    n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
    fmt.Println("Enter the elements of the array")
    r := make([]int, n)
    for i := 0; i < n; i++ {
        r[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
    }
    ans := 0
    for i := 0; i < n; i++ {
        if i == 0 {
            ans = int(math.Abs(float64(r[i])))
        } else {
            ans += int(math.Abs(float64(r[i] - r[i-1])))
        }
    }
    fmt.Println(ans)
}

