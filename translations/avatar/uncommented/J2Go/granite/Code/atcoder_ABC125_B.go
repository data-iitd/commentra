
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nStr))
	vStr, _ := reader.ReadString('\n')
	vList := str2List(vStr)
	cStr, _ := reader.ReadString('\n')
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

func str2List(str string) []int {
	vArrStr := strings.Split(str, " ")
	ret := make([]int, len(vArrStr))
	for i, val := range vArrStr {
		v, _ := strconv.Atoi(val)
		ret[i] = v
	}
	return ret
}

