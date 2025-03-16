package main
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N, A, B int
	fmt.Fscanln(reader, &N, &A, &B)
	var ans int
	rep := N / (A + B)
	ans += rep * A
	res := N - rep * (A + B)
	ans += min(res, A)
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

