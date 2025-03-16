
package main

import "fmt"

func main() {
    var a string
    fmt.Scan(&a)
    vo := []string{"a", "e", "i", "o", "u", "y", "A", "E", "I", "O", "U", "Y"}
    for i := len(a) - 1; i >= 0; i-- {
        if a[i] == ' ' || a[i] == '?' {
            continue
        } else {
            if a[i] == vo[0] || a[i] == vo[1] || a[i] == vo[2] || a[i] == vo[3] || a[i] == vo[4] || a[i] == vo[5] || a[i] == vo[6] || a[i] == vo[7] || a[i] == vo[8] || a[i] == vo[9] || a[i] == vo[10] {
                fmt.Println("YES")
            } else {
                fmt.Println("NO")
            }
            break
        }
    }
}

