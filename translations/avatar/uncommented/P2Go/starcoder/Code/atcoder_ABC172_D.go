package main
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)
func main() {
	var N int
	fmt.Scanf("%d\n", &N)
	ans := 0
	for i := 1; i <= N; i++ {
		ans += i * (N / i) * (N / i + 1) / 2
	}
	fmt.Printf("%d\n", ans)
}
