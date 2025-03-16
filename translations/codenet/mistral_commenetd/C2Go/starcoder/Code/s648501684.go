
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
<<<<<<< HEAD
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the number of elements in the array")
    n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    fmt.Println("Enter the value of k")
    k, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    fmt.Println("Enter the value of q")
    q, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
=======
    var n, k, q int
    fmt.Scanf("%d %d %d", &n, &k, &q)
>>>>>>> 98c87cb78a (data updated)
    arr := make([]int, n)
    for i := 0; i < n; i++ {
        arr[i] = 0
    }
    for i := 0; i < q; i++ {
<<<<<<< HEAD
        temp, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
=======
        var temp int
        fmt.Scanf("%d", &temp)
>>>>>>> 98c87cb78a (data updated)
        arr[temp-1] += 1
    }
    for i := 0; i < n; i++ {
        if arr[i] > q-k {
            fmt.Println("Yes")
        } else {
            fmt.Println("No")
        }
    }
}

