
package main

import "fmt"

func main() {
	var n, m, s, f int
	fmt.Scanf("%d %d %d %d", &n, &m, &s, &f)
	var d int
	var c string
	if s < f {
		d = 1
		c = "R"
	} else {
		d = -1
		c = "L"
	}
	var res string
	var i, j, t, l, r, k int
	fmt.Scanf("%d %d %d", &t, &l, &r)
	k = 1
	for j = s; j!= f; j += d {
		if i > t && k < m {
			fmt.Scanf("%d %d %d", &t, &l, &r)
			k++
		}
		if i == t && (l <= j && j <= r || l <= j+d && j+d <= r) {
			res += "X"
		} else {
			res += c
		}
		i++
	}
	fmt.Println(res)
}

