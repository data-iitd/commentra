<<<<<<< HEAD
import "fmt"
import "math"
import "os"
import "strconv"
import "strings"
import "unicode"

func main() {
    // Read input
    tc, n, m := 0, 0, 0
    fmt.Scanf("%d%d%d", &tc, &n, &m)
    // Check if 'n' is greater than'm' and swap them if necessary
    if n > m {
        n, m = m, n
    }
    // Iterate through each possible value of 'i' from 1 to'm'
    for i := 1; i <= m; i++ {
        // Check if 'i' multiplied by 'tc' is within the range of 'n' to'm'
        if i*tc >= n && i*tc <= m {
            // If so, print "OK" and break out of the loop since we have found the answer
=======
package main
import "fmt"

func main() {
    var tc, n, m int
    fmt.Scanf("%d%d%d", &tc, &n, &m)
    if n > m {
        n, m = m, n
    }
    for i := 1; i <= m; i++ {
        if i*tc >= n && i*tc <= m {
>>>>>>> 98c87cb78a (data updated)
            fmt.Println("OK")
            break
        }
    }
<<<<<<< HEAD
    // If the loop has not been broken out of, print "NG"
    if i > m {
=======
    if i*tc > m {
>>>>>>> 98c87cb78a (data updated)
        fmt.Println("NG")
    }
}

