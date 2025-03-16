
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	result := int((float64(n)*2 + 1) / 3)
	fmt.Println(result)
}

