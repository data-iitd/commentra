<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import (
	"fmt"
	"os"
	"strconv"
	"strings"
)
func main() {
	var n int
	fmt.Scanf("%d", &n)
	var s string
	fmt.Scanf("%s", &s)
	cnt := 0
	for i := 0; i < n; i++ {
		cnt++
		for j := i + 1; j < n; j++ {
			if s[i]!= s[j] {
				break
			}
		}
		i = j - 1
	}
	fmt.Println(cnt)
}

