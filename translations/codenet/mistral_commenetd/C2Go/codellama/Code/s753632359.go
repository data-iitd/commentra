
package main

import "fmt"

func main() {
	var N, D int
	fmt.Scan(&N, &D)
	ans := N / (D*2 + 1)
	rem := N % (D*2 + 1)
	if rem != 0 {
		ans++
	}
	fmt.Println(ans)
}

