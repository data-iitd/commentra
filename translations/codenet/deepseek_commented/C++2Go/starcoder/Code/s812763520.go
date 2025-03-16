<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	var a, b, c string
<<<<<<< HEAD
	fmt.Scanf("%d\n", &n)
	fmt.Scanf("%s\n%s\n%s\n", &a, &b, &c)
=======
	fmt.Scanf("%d", &n)
	fmt.Scanf("%s %s %s", &a, &b, &c)
>>>>>>> 98c87cb78a (data updated)
	var ans int
	for i := 0; i < n; i++ {
		if a[i] == b[i] && b[i] == c[i] {
			// Do nothing
		} else if a[i] == b[i] || b[i] == c[i] || a[i] == c[i] {
			ans++
		} else {
			ans += 2
		}
	}
	fmt.Println(ans)
}

