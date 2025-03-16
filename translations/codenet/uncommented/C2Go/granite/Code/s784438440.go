
package main

import "fmt"

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	fmt.Println(((b - 1) + (a - 2)) / (a - 1))
	//END-OF-CODE
}

The above Go code is a translation of the given C code. It reads two integers from the user, calculates the result of the given expression, and prints the result. The comment "