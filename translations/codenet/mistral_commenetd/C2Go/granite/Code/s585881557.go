
package main

import "fmt"

func main() {
	var h, r int
	fmt.Scan(&h, &r)
	if r > -h {
		fmt.Println(1)
	} else if r == -h {
		fmt.Println(0)
	} else {
		fmt.Println(-1)
	}
}

