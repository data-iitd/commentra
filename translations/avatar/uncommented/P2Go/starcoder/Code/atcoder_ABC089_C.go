package main
import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scanf("%d", &N)
	S := make([]string, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%s", &S[i])
	}
	march := []string{"M", "A", "R", "C", "H"}
	march_lis := make([]int, 5)
	for _, s := range S {
		if s[0] == strings.ToUpper(march[0]) {
			march_lis[0]++
		} else if s[0] == strings.ToUpper(march[1]) {
			march_lis[1]++
		} else if s[0] == strings.ToUpper(march[2]) {
			march_lis[2]++
		} else if s[0] == strings.ToUpper(march[3]) {
			march_lis[3]++
		} else if s[0] == strings.ToUpper(march[4]) {
			march_lis[4]++
		}
	}
	ans := 0
	for x, y, z := range combinations(march_lis, 3) {
		ans += x * y * z
	}
	fmt.Printf("%d", ans)
}
