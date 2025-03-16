<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

func main() {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)
	ans := 0
	ans += n * (n - 1) / 2
	ans += m * (m - 1) / 2
	fmt.Println(ans)
}

