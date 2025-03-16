<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	a := make([]int64, n+1)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	pre := make([]int64, n+1)
	last := make([]int64, n+1)
	sumpre := int64(0)
	sumlast := int64(0)
	for i := 1; i <= n; i++ {
		sumpre += a[i]
		pre[i] = sumpre
	}
	for i := n; i >= 1; i-- {
		sumlast += a[i]
		last[i] = sumlast
	}
	d := int64(math.MaxInt64)
	for i := 1; i <= n; i++ {
<<<<<<< HEAD
		d = int64(math.Min(d, int64(math.Abs(pre[i]-last[i+1]))))
=======
		d = int64(math.Min(d, abs(pre[i]-last[i+1])))
>>>>>>> 98c87cb78a (data updated)
	}
	fmt.Printf("%d\n", d)
}

