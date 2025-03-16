package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	from sys import setrecursionlimit, stdin
	from os import environ
	from collections import defaultdict, deque, Counter
	from math import ceil, floor, gcd
	from itertools import accumulate, combinations, combinations_with_replacement
	setrecursionlimit(10**6)
	dbg := (func(something ...interface{}) {
		fmt.Println(something...)
	})
	if "TERM_PROGRAM" in environ {
		dbg = func(something ...interface{}) {}
	}
	input := func() string {
		return stdin.ReadString('\n')
	}
	LMIIS := func() []int {
		return map(int, input().Split())
	}
	II := func() int {
		return int(input())
	}
	P := 10**9 + 7
	INF := 10**9 + 10
	sa, sb := input().Split()
	a := int(sa)
	b := int(float64(sb) * 100 + 0.1)
	fmt.Println(a*b/100)
}

