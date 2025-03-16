<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import "fmt"
import "sort"
import "os"
import "bufio"
import "strconv"

func main() {
    // Step 7: Main function
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(reader.ReadString('\n'))
    a := make([]int, n+1)
    for i := 1; i <= n; i++ {
        a[i], _ = strconv.Atoi(reader.ReadString('\n'))
    }
    sort.Ints(a[1:])
    var tot int
    for i := 1; i <= n; i++ {
        if a[i] == a[i+1] {
            tot++
        } else {
            break
        }
    }
    fmt.Println(a[tot] * a[tot-1])
}

