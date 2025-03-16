package main

import (
    "fmt"
    "os"
    "bufio"
    "strconv"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    n, _ := strconv.Atoi(scanner.Text())
    scanner.Scan()
    k, _ := strconv.Atoi(scanner.Text())
    scanner.Scan()
    a := scanner.Text()

    if k > n/2 {
        for k < n {
            fmt.Println("RIGHT")
            k++
        }
    } else {
        for k > 1 {
            fmt.Println("LEFT")
            k--
        }
    }

    if k == 1 {
        for i := 0; i < len(a); i++ {
            fmt.Println("PRINT", string(a[i]))
            if i+1 < len(a) {
                fmt.Println("RIGHT")
            }
        }
    } else {
        for i := len(a) - 1; i >= 0; i-- {
            fmt.Println("PRINT", string(a[i]))
            if i-1 >= 0 {
                fmt.Println("LEFT")
            }
        }
    }
}

