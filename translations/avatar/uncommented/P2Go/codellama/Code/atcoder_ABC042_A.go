
package main

import "fmt"

func main() {
	var ABC [3]int
	fmt.Scan(&ABC[0], &ABC[1], &ABC[2])
	if ABC[0] == 5 && ABC[1] == 5 {
		if ABC[2] == 7 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	} else {
		fmt.Println("NO")
	}
}

