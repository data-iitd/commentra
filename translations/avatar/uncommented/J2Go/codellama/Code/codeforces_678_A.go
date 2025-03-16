
package main

import "fmt"

func main() {
	var n, k, z int
	fmt.Scan(&n, &k)
	n++
	if n%k != 0 {
		z = k - n%k
	}
	fmt.Println(n + z)
}

