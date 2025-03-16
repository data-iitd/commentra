
package main

import "fmt"

func main() {
	var t, s, q int
	fmt.Scan(&t, &s, &q)
	var ans int
	for s < t {
		s *= q
		ans++
	}
	fmt.Println(ans)
}

