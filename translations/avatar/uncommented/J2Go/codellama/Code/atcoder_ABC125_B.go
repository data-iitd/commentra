
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scanln(&n)
	var vStr string
	fmt.Scanln(&vStr)
	vList := str2List(vStr)
	var cStr string
	fmt.Scanln(&cStr)
	cList := str2List(cStr)
	var max int
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
		valInt, _ := strconv.Atoi(val)
		ret[key] = valInt
		key++
	}
	return ret
}

