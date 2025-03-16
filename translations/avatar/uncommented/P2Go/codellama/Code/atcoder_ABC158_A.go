
package main

import (
	"fmt"
	"os"
)

func main() {
	var s string
	fmt.Scan(&s)
	if (s == "A" || s == "B") {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

