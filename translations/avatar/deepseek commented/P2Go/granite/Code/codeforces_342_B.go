

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	n, m, s, f := readLine(r)
	d, c := 1, "R"
	if s > f {
		d, c = -1, "L"
	}
	res := ""
	i, j := 1, s
	t, l, r := readLine(r)
	k := 1
	for j!= f {
		if i > t && k < m {
			t, l, r = readLine(r)
			k++
		}
		if i == t && (l <= j && j <= r || l <= j+d && j+d <= r) {
			res += "X"
		} else {
			res += string(c)
			j += d
		}
		i++
	}
	fmt.Println(res)
}

func readLine(r *bufio.Reader) (int, int, int) {
	line, _, _ := r.ReadLine()
	parts := strings.Split(string(line), " ")
	t, _ := strconv.Atoi(parts[0])
	l, _ := strconv.Atoi(parts[1])
	r, _ := strconv.Atoi(parts[2])
	return t, l, r
}

