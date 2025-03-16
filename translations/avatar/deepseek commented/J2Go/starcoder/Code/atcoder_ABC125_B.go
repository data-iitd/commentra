
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
	fmt.Println("Enter the number of elements")
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the values of `v` (values) and store them in a list `vList`")
	vStr := reader.ReadString('\n')
	vList := str2List(vStr)
	fmt.Println("Enter the values of `c` (costs) and store them in a list `cList`")
	cStr := reader.ReadString('\n')
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

