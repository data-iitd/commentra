package main

import (
	"bufio"
	"fmt"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(bufio.NewReader(os.Stdin))
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	vStr := scanner.Text()
	vList := str2List(vStr)
	scanner.Scan()
	cStr := scanner.Text()
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
	for key, val := range vArrStr {
		num, _ := strconv.Atoi(val)
		ret[key] = num
	}
	return ret
}

