package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var scanner = bufio.NewScanner(os.Stdin)

func readInt() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func readString() string {
	scanner.Scan()
	return scanner.Text()
}

const MOD = 1e9 + 7

func main() {
	scanner.Split(bufio.ScanWords)
	N := readInt()
	K := readInt()
	S := readString()
	segCnt := 0
	for i := 0; i < N-1; i++ {
		if S[i] != S[i+1] {
			segCnt++
		}
	}
	curHappy := N - 1 - segCnt
	if 2*K >= segCnt {
		ans := N - 1
		fmt.Println(ans)
	} else {
		ans := curHappy + 2*K
		fmt.Println(ans)
	}
}
