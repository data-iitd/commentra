
package main

import "fmt"

func main() {
	var a, at int
	fmt.Scan(&a, &at)
	var b, bt int
	fmt.Scan(&b, &bt)
	var t1, t2 int
	fmt.Scan(&t1, &t2)
	st := t2 + (t1 - 5) * 60
	fin := st + at
	now := 0
	ans := 0
	for now < fin && now < 1140 {
		if now+bt > st {
			ans++
		}
		now += b
	}
	fmt.Println(ans)
}

