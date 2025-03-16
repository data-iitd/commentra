
package main

import "fmt"

func generateString() string {
	var sb string
	for i := 1; i <= 1000; i++ {
		sb += string(i)
	}
	return sb
}

func main() {
	var n int
	fmt.Scan(&n)
	fmt.Println(generateString()[n-1])
}

