
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
	fmt.Println("Enter the length of the string")
	N, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the number of times the string is to be rotated")
	K, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the string")
	S := reader.ReadString('\n')
	S = strings.TrimSpace(S)
	c1 := []rune(S)
	c3 := []rune(S)
	flag1 := false
	count1 := 0
	for i := 0; i < N; i++ {
		if flag1 && c1[i] == 'R' {
			flag1 = false
			count1++
		}
		if count1 == K {
			break
		}
		if c1[i] == 'L' {
			flag1 = true
		}
	}
	flag3 := false
	count3 := 0
	for i := 0; i < N; i++ {
		if flag3 && c3[i] == 'L' {
			flag3 = false
			count3++
		}
		if count3 == K {
			break
		}
		if c3[i] == 'R' {
			flag3 = true
		}
	}
	S1 := string(c1)
	S3 := string(c3)
	count2 := 1
	sum1 := 0
	bef1 := S1[0]
	for i := 1; i < N; i++ {
		if S1[i] == bef1 {
			count2++
		} else {
			sum1 += count2 - 1
			count2 = 1
			bef1 = S1[i]
		}
	}
	sum1 += count2 - 1
	count4 := 1
	sum3 := 0
	bef3 := S3[0]
	for i := 1; i < N; i++ {
		if S3[i] == bef3 {
			count4++
		} else {
			sum3 += count4 - 1
			count4 = 1
			bef3 = S3[i]
		}
	}
	sum3 += count4 - 1
	fmt.Println(max(sum1, sum3))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

