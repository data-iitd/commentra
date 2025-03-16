
package main

import "fmt"
import "os"

func main() {
    sc := bufio.NewScanner(os.Stdin)
    t := 0
    count := 0
    for sc.Scan() {
        t, _ = strconv.Atoi(sc.Text())
        for i := 0; i < t; i++ {
            a, _ := strconv.Atoi(sc.Text())
            b, _ := strconv.Atoi(sc.Text())
            c, _ := strconv.Atoi(sc.Text())
            if a == 1 || b == 1 || c == 1 || a == 1 && b == 1 && c == 1 {
                count++
            }
        }
    }
    fmt.Println(count)
}

