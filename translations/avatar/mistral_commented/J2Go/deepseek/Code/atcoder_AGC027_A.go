package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	N := toInt(scanner.Text())
	scanner.Scan()
	x := toInt(scanner.Text())

	sweet := make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		sweet[i] = toInt(scanner.Text())
	}

	sort.Ints(sweet)

	num := 0
	for i := 0; i < N; i++ {
		if x-int(sweet[num]) >= 0 {
			x -= int(sweet[num])
			num++
		} else {
			break
		}
	}

	if num == N && x > 0 {
		num--
	}

	fmt.Println(num)
}

func toInt(s string) int {
	var res int
	for i := 0; i < len(s); i++ {
		res = res*10 + int(s[i]-'0')
	}
	return res
}

