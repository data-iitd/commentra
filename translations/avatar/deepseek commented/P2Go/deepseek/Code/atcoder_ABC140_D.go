package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MOD = 1e9 + 7

func readString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func readInt() int {
	data := readString()
	num, _ := strconv.Atoi(data)
	return num
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	N := len(scanner.Text())

	scanner.Scan()
	K := readInt()

	scanner.Scan()
	S := scanner.Text()

	segCnt := 0
	for i := 0; i < N-1; i++ {
		if S[i] != S[i+1] {
			segCnt++
		}
	}

	curHappy := N - 1 - segCnt

	if 2*K >= segCnt {
		fmt.Println(N - 1)
	} else {
		fmt.Println(curHappy + 2*K)
	}
}

