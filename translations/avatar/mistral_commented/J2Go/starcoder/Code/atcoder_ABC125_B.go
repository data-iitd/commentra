
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)

	n, _ := strconv.Atoi(sc.Scan())
	vStr := sc.Scan()
	vList := str2List(vStr)

	cStr := sc.Scan()
	cList := str2List(cStr)

	max := 0

	for i := 0; i < n; i++ {
		profit := vList[i] - cList[i]
		if profit > 0 {
			max += profit
		}
	}

	fmt.Println(max)
}

func str2List(str string) map[int]int {
	vArrStr := strings.Split(str, " ")
	ret := make(map[int]int)
	key := 0

	for _, val := range vArrStr {
		ret[key] = atoi(val)
		key++
	}

	return ret
}

func atoi(str string) int {
	i, _ := strconv.Atoi(str)
	return i
}

