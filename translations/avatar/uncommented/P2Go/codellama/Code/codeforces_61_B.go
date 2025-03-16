import (
	"fmt"
	"io"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

func valid(i, j, n, m int) bool {
	if i < n && i >= 0 && j >= 0 && j < m {
		return true
	}
	return false
}

func sumn(i, n int) int {
	return (n - i) * (i + n) / 2
}

func sqfun(a, b, c float64) float64 {
	return (-b + math.Sqrt(b*b-4*a*c)) / 2 * a
}

func value() (int, int) {
	return valuei(), valuei()
}

func valuei() int {
	var i int
	fmt.Scan(&i)
	return i
}

func values() (int, int, int) {
	return valuesi(), valuesi(), valuesi()
}

func valuesi() int {
	var i int
	fmt.Fscan(reader, &i)
	return i
}

func inlst() []int {
	return inlsti()
}

func inlsti() []int {
	var i int
	var l []int
	for fmt.Fscan(reader, &i); i != -1; fmt.Fscan(reader, &i) {
		l = append(l, i)
	}
	return l
}

func inp() int {
	return valuei()
}

func inps() int {
	return valuesi()
}

func instr() string {
	var s string
	fmt.Scan(&s)
	return s
}

func stlst() []string {
	return stlsti()
}

func stlsti() []string {
	var s string
	var l []string
	for fmt.Fscan(reader, &s); s != ""; fmt.Fscan(reader, &s) {
		l = append(l, s)
	}
	return l
}

func f(s string) string {
	r := ""
	for _, i := range s {
		if i != '-' && i != ';' && i != '_' {
			r += strings.ToLower(string(i))
		}
	}
	return r
}

func solve() {
	l := [3]string{}
	for i := 0; i < 3; i++ {
		fmt.Scan(&l[i])
	}
	t := permutations(l[:], len(l))
	l = [][3]string{}
	for i := range t {
		l = append(l, [3]string{t[i][0], t[i][1], t[i][2]})
	}
	for i := 0; i < inp(); i++ {
		if f(instr()) == l[i] {
			fmt.Println("ACC")
		} else {
			fmt.Println("WA")
		}
	}
}

func permutations(l []string, n int) [][]string {
	if n == 1 {
		return [][]string{l}
	}
	var t [][]string
	for i := 0; i < n; i++ {
		t = append(t, permutations(l, n-1)...)
		if n%2 == 1 {
			l[i], l[n-1] = l[n-1], l[i]
		} else {
			l[0], l[n-1] = l[n-1], l[0]
		}
	}
	return t
}

var reader *bufio.Reader

func init() {
	reader = bufio.NewReader(os.Stdin)
}

func main() {
	solve()
}

