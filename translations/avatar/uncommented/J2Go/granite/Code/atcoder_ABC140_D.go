
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
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	K, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	S := readLine(reader)
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
	fmt.Println(int(math.Max(float64(sum1), float64(sum3))))
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}