
package main

import "fmt"

func main() {
	var n int
	fmt.Scanf("%d", &n)
	s := ""
	for i := 0; i < n; i++ {
		s += "abcd"[i%4]
	}
	fmt.Println(s)
}

