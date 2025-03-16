
package main

import "fmt"

func main() {
	var N, A int
	fmt.Scan(&N, &A)
	if N%500 <= A {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
