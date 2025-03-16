
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

	var n, k int
	fmt.Fscanf(reader, "%d %d\n", &n, &k)

	s := make([]byte, n)
	fmt.Fscanf(reader, "%s\n", s)

	var aaaa bool
	if k >= 15 || 1<<uint(k) >= n {
		aaaa = true
	}

	if aaaa {
		fmt.Println(strings.Repeat(string(s[0]), n))
		return
	}

	get_last_dict := func(s_str string) string {
		U := s_str + strings.Reverse(s_str)
		c := byte(0)
		for i := 0; i < len(s_str); i++ {
			if s_str[i] < c {
				c = s_str[i]
			}
		}
		p := strings.Index(U, string(c))
		minindex := p
		p++
		for p <= n {
			if U[p] == c {
				if check_normal_dict(U, minindex, p) {
					minindex = p
				}
			}
			p++
		}
		return U[minindex : minindex+n]
	}

	check_normal_dict := func(u string, pointer1, pointer2 int) bool {
		for i := 0; i < n; i++ {
			if u[pointer1+i] > u[pointer2+i] {
				return true
			} else if u[pointer1+i] < u[pointer2+i] {
				return false
			}
		}
		return false
	}

	s = []byte(get_last_dict(string(s)))

	if k == 1 {
		fmt.Println(string(s))
		return
	}

	count := 0
	for i := 0; i < n; i++ {
		if s[0] == s[i] {
			count++
		} else {
			break
		}
	}

	if count*(1<<(k-1)) >= n {
		fmt.Println(strings.Repeat(string(s[0]), n))
		return
	}

	s = []byte(strings.Repeat(string(s[0]), count*(1<<(k-1))-1) + string(s))
	fmt.Println(s[:n])
}

