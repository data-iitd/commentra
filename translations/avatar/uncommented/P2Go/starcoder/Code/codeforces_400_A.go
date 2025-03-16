package main
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)
func main() {
	var (
		n int
		x string
		s []int
	)
	fmt.Scanf("%d", &n)
	x = strings.TrimSpace(bufio.NewReader(os.Stdin).ReadString('\n'))
	for i := 0; i < len(x); i++ {
		if x[i] == 'O' {
			s = append(s, 0)
		} else {
			s = append(s, 1)
		}
	}
	var (
		tot [][2]int
	)
	for i := 1; i < 13; i++ {
		if 12%i == 0 {
			if help(i, 12/i, s) {
				tot = append(tot, [2]int{i, 12/i})
			}
		}
	}
	fmt.Printf("%d", len(tot))
	for _, v := range tot {
		fmt.Printf(" %dx%d", v[0], v[1])
	}
	fmt.Println()
}
func help(a, b int, l []int) bool {
	tot := make([][]int, 0)
	for i := 0; i < b; i++ {
		tot = append(tot, l[i*a:i*a+a])
	}
	for i := range tot {
		if sum(tot[i]) == b {
			return true
		}
	}
	return false
}
func sum(l []int) int {
	var (
		tot int
	)
	for _, v := range l {
		tot += v
	}
	return tot
}
