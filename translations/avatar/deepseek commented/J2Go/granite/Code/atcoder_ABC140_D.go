
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	buf := make([]byte, 0)
	sc.Buffer(buf, 1010000)
	sc.Split(bufio.ScanWords)

	N := nextInt(sc)
	K := nextInt(sc)
	S := nextString(sc)

	c1 := []rune(S)
	c3 := []rune(S)

	flag := false
	count := 0

	// Process c1 (Left to Right)
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

	// Process c3 (Right to Left)
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

	// Count consecutive characters in S1
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

	// Count consecutive characters in S3
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

	// Print the maximum of the two sums
	fmt.Println(int(math.Max(float64(sum1), float64(sum3))))
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextNumber(sc *bufio.Scanner) float64 {
	sc.Scan()
	f, err := strconv.ParseFloat(sc.Text(), 32)
	if err!= nil {
		panic(err)
	}
	return f
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, err := strconv.Atoi(sc.Text())
	if err!= nil {
		panic(err)
	}
	return n
}

func printArray(xs []int) {
	fmt.Println(xs)
}

func debugPrintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

