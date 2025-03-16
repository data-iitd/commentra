
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
	n, _ := strconv.Atoi(readLine(reader))
	s := make([][]int, n)
	for i := 0; i < n; i++ {
		s[i] = make([]int, n)
		s_temp := strings.Split(readLine(reader), " ")
		for j := 0; j < n; j++ {
			s[i][j], _ = strconv.Atoi(s_temp[j])
		}
	}
	flag := 0
	d1 := make([]int, n)
	d2 := make([]int, n)
	rem := make(map[int]int)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i == j {
				d1[i] = s[i][j]
			}
			if i == n-j-1 {
				d2[i] = s[i][j]
			}
			if i!= j && i!= n-j-1 {
				rem[s[i][j]] = 1
			}
		}
	}
	if len(rem)!= 1 {
		fmt.Println("NO")
	} else if d1!= d2 {
		fmt.Println("NO")
	} else if len(d1)!= 1 {
		fmt.Println("NO")
	} else if d1[0] == 0 {
		fmt.Println("NO")
	} else {
		fmt.Println("YES")
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

