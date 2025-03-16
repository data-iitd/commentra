package main
import (
"bufio"
"fmt"
"os"
"strconv"
"strings"
)
func check ( lis []int, k int, mid int ) bool {
    for _, i := range lis {
        if ( i % mid == 0 ) {
            k += 1
        }
        k -= ( i / mid )
    }
    return k >= 0
}
func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)
    fmt.Println("Enter the number of elements in the list")
    n, err := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    if err!= nil {
        panic(err)
    }
    fmt.Println("Enter the number of elements to be removed")
    k, err := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    if err!= nil {
        panic(err)
    }
    fmt.Println("Enter the elements of the list")
    lis := make([]int, n)
    for i := 0; i < n; i++ {
        lis[i], err = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
        if err!= nil {
            panic(err)
        }
    }
    a, b := 1, 0
    for a <= b {
        mid := (a + b) / 2
        if check(lis, k, mid) {
            a = mid + 1
        } else {
            b = mid - 1
        }
    }
    fmt.Println(a)
}
