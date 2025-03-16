
package main

import "fmt"

func generateString() []byte {
	var sb []byte
	for i := 1; i <= 1000; i++ {
		sb = append(sb, byte(i))
	}
	return sb
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	fmt.Printf("%c\n", generateString()[n-1])
}

