package main

import (
	"fmt"
	"strings"
)

func solve() {
	var maxsize int
	var maxcnt int
	var ansNum int
	var ansNum2 int
	strV := []string{}

	var in string
	for {
		_, err := fmt.Scan(&in)
		if err != nil {
			break
		}
		strV = append(strV, in)
		if maxsize < len(in) {
			maxsize = len(in)
			ansNum = len(strV) - 1
		}
	}

	for i := 0; i < len(strV); i++ {
		cnt := 0
		for j := 0; j < len(strV); j++ {
			if strV[i] == strV[j] {
				cnt++
			}
		}
		if maxcnt < cnt {
			maxcnt = cnt
			ansNum2 = i
		}
	}

	fmt.Println(strV[ansNum2], strV[ansNum])
}

func main() {
	solve()
}

// <END-OF-CODE>
