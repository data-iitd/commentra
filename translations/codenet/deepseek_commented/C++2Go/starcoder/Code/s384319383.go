<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	cnt := make([]int, 26)
	s := make([]byte, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%c", &s[i])
		cnt[int(s[i]-'a')]++
	}
	ans := cnt[0]
	for i := 1; i < 26; i++ {
		ans *= cnt[i]
		ans %= int(math.Pow10(9) + 7)
	}
	fmt.Println(ans - 1)
}

