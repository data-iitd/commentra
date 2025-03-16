package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

func solve() {
	maxsize := 0
	maxcnt := 0
	var ansNum, ansNum2 int
	strV := []string{}

	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		in := scanner.Text()
		strV = append(strV, in)
		if maxsize < len(in) {
			maxsize = len(in)
			ansNum = len(strV) - 1
		}
	}

	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading standard input:", err)
	}

	cntMap := make(map[string]int)
	for _, str := range strV {
		cntMap[str]++
	}

	for i, str := range strV {
		if cnt, ok := cntMap[str]; ok && cnt > maxcnt {
			maxcnt = cnt
			ansNum2 = i
		}
	}

	fmt.Println(strV[ansNum2], strV[ansNum])
}

func main() {
	solve()
}

