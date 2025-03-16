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
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the number of flips")
	K, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the array")
	S := strings.TrimSpace(reader.ReadString('\n'))
	c1 := []rune(S)
	c3 := []rune(S)
	flag := false
	count := 0
	for i := 0; i < N; i++ {
		if flag && c1[i] == 'R' {
			flag = false
			count++
		}
		if count == K {
			break
		}
		if c1[i] == 'L' {
			flag = true
			c1[i] = 'R'
		}
	}
	flag = false
	count = 0
	for i := 0; i < N; i++ {
		if flag && c3[i] == 'L' {
			flag = false
			count++
		}
		if count == K {
			break
		}
		if c3[i] == 'R' {
			flag = true
			c3[i] = 'L'
		}
	}
	S1 := string(c1)
	S3 := string(c3)
	count = 1
	sum1 := 0
	bef := S1[0]
	for i := 1; i < N; i++ {
		if S1[i] == bef {
			count++
			if i == N-1 {
				sum1 += count - 1
			}
		} else {
			bef = S1[i]
			sum1 += count - 1
			count = 1
		}
	}
	count = 1
	sum3 := 0
	bef = S3[0]
	for i := 1; i < N; i++ {
		if S3[i] == bef {
			count++
			if i == N-1 {
				sum3 += count - 1
			}
		} else {
			bef = S3[i]
			sum3 += count - 1
			count = 1
		}
	}
	fmt.Println(max(sum1, sum3))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

