
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	n, err := strconv.Atoi(os.Args[1])
	if err!= nil {
		fmt.Println(err)
		return
	}
	for i := n; i > 0; i-- {
		if n%i == 0 {
			n = i
			fmt.Print(i, " ")
		}
	}
	fmt.Println("