package main

import "fmt"
import "os"

func main() {
    scan := bufio.NewScanner(os.Stdin)
    scan.Split(bufio.ScanWords)

    var n, k int
    fmt.Fscan(scan, &n)
    fmt.Fscan(scan, &k)

    n++

    z := 0
    if n%k!= 0 {
        z = k - n%k
    }

    fmt.Println(n + z)
}

