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
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	ch := make([]byte, n)
	s1, s2 := 0, 0
	i, j, flag, dif := 0, 0, 0, 0
	for i = 0; i < n; i++ {
		x, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		y, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		temp1 := s1 + x
		temp2 := s2 + y
		if abs(temp1-s2) <= 500 {
			s1 += x
			ch[j] = 'A'
			j++
			continue
		}
		if abs(temp2-s1) <= 500 {
			s2 += y
			ch[j] = 'G'
			j++
			continue
		}
		flag = 1
		break
	}
	if flag == 1 {
		fmt.Println("-1")
	} else {
		fmt.Println(string(ch[:j]))
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

