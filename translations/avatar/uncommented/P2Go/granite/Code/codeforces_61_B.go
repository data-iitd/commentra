
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
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

func sqfun(a, b, c int) float64 {
	return (-b + math.Sqrt(b*b-4*a*c)) / 2 * a
}

func value() (int, int) {
	x, _ := fmt.Scanf("%d %d", &x, &y)
	return x, y
}

func values() (int, int, int) {
	x, y, z := 0, 0, 0
	fmt.Scanf("%d %d %d", &x, &y, &z)
	return x, y, z
}

func inlst() []int {
	res := make([]int, 0)
	buf := bufio.NewReader(os.Stdin)
	line, _, _ := buf.ReadLine()
	for _, num := range bytes.Split(line, []byte{' '}) {
		res = append(res, int(num[0]-'0'))
	}
	return res
}

func inlsts() []int {
	res := make([]int, 0)
	buf := bufio.NewReader(os.Stdin)
	line, _, _ := buf.ReadLine()
	for _, num := range bytes.Split(line, []byte{' '}) {
		res = append(res, int(num[0]-'0'))
	}
	return res
}

func inp() int {
	x := 0
	fmt.Scanf("%d", &x)
	return x
}

func inps() int {
	x := 0
	fmt.Scanf("%d", &x)
	return x
}

func instr() string {
	res := ""
	buf := bufio.NewReader(os.Stdin)
	line, _, _ := buf.ReadLine()
	res = string(line)
	return res
}

func f(s string) string {
	res := ""
	for _, c := range s {
		if c!= '-' && c!= ';' && c!= '_' {
			res += string(c | 0x20)
		}
	}
	return res
}

func solve() {
	l := make([]string, 3)
	for i := 0; i < 3; i++ {
		l[i] = f(instr())
	}
	t := make([][]string, 0)
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			for k := 0; k < 3; k++ {
				if i!= j && j!= k && i!= k {
					t = append(t, []string{l[i], l[j], l[k]})
				}
			}
		}
	}
	for i := 0; i < inp(); i++ {
		if f(instr()) == t[i][0]+t[i][1]+t[i][2] {
			fmt.Println("ACC")
		} else {
			fmt.Println("WA")
		}
	}
}

func main() {
	solve()
}
