package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	K, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	S := scanner.Text()
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

