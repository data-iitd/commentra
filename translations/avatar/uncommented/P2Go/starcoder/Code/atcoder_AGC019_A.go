package main
import (
	"fmt"
	"math"
)

func main() {
	var q, h, s, d int
	fmt.Scanf("%d %d %d %d", &q, &h, &s, &d)
	n := int(math.Min(float64(q*4), float64(h*2), float64(s)))
	if n%2 == 0 {
		fmt.Println(n/2*d)
	} else {
		fmt.Println((n/2+1)*d)
	}
}

