
package main

import (
	"fmt"
	"time"
)

func main() {
	var s, t string
	fmt.Scan(&s, &t)
	x := time.Now()
	y := time.Now()
	fmt.Println(x.Sub(y))
}

