
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var N, K int
	var S string
	fmt.Scan(&N, &K, &S)

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
	bef1 := rune(S1[0])

	for i := 1; i < N; i++ {
		if S1[i] == bef1 {
			count2++
		} else {
			sum1 += count2 - 1
			count2 = 1
			bef1 = rune(S1[i])
		}
	}
	sum1 += count2 - 1

	count4 := 1
	sum3 := 0
	bef3 := rune(S3[0])

	for i := 1; i < N; i++ {
		if S3[i] == bef3 {
			count4++
		} else {
			sum3 += count4 - 1
			count4 = 1
			bef3 = rune(S3[i])
		}
	}
	sum3 += count4 - 1

	fmt.Println(strconv.Itoa(int(math.Max(float64(sum1), float64(sum3)))))
}

