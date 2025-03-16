

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	soz := readString()
	a := make([]int, len(soz)+1)
	for i := 1; i < len(soz); i++ {
		a[i] = a[i-1]
		if soz[i-1] == soz[i] {
			a[i]++
		}
	}
	n := readInt()
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		m, l := readString(), readString()
		arr[i] = a[toInt(l)-1] - a[toInt(m)-1]
	}
	for _, v := range arr {
		fmt.Println(v)
	}
}

func readString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func readInt() int {
	res, err := strconv.Atoi(readString())
	if err!= nil {
		panic(err)
	}
	return res
}

func toInt(s string) int {
	res, err := strconv.Atoi(s)
	if err!= nil {
		panic(err)
	}
	return res
}

