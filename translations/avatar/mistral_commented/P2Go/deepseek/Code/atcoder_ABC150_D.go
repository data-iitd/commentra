package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a % b
	}
	return a
}

func main() {
	var n, num int
	fmt.Scan(&n, &num)

	var numSet []int
	numSetMap := make(map[int]bool)
	for _, v := range strings.Split(readLine(), " ") {
		num := parseInt(v)
		if !numSetMap[num] {
			numSet = append(numSet, num)
			numSetMap[num] = true
		}
	}

	twoTimesSet := make(map[int]bool)
	for _, i := range numSet {
		powerOfTwo := 0
		for i%2 == 0 {
			powerOfTwo++
			i /= 2
		}
		if powerOfTwo > 1 {
			fmt.Println(0)
			return
		}
		twoTimesSet[powerOfTwo] = true
	}

	if len(twoTimesSet) != 1 {
		fmt.Println(0)
		return
	}

	lcm := numSet[0]
	for _, i := range numSet[1:] {
		lcm = lcm * i / gcd(lcm, i)
	}

	fmt.Println((num - lcm/2) / lcm + 1)
}

func readLine() string {
	buf := make([]byte, 0, 1024)
	for {
		line, prefix, err := bufio.Reader.ReadLine(bufio.Reader)
		if err != nil {
			panic(err)
		}
		buf = append(buf, line...)
		if !prefix {
			break
		}
	}
	return string(buf)
}

func parseInt(s string) int {
	n, err := strconv.Atoi(s)
	if err != nil {
		panic(err)
	}
	return n
}
