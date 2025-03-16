
package main

import "fmt"

func main() {
    var a int
    fmt.Scan(&a)
    fmt.Printf("%d:%d:%d\n", a/(60*60), a%(60*60)/60, a%(60*60)%60)
}

