package main
import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	a := make([]int, n)
	b := make([]int, n)
	var sum int
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &b[i])
		if a[i]-b[i] > 0 {
			sum += a[i] - b[i]
		}
	}
	fmt.Printf("%d\n", sum)
}

