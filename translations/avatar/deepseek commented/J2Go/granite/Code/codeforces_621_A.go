

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements:")
	nTemp, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nTemp))
	arrTemp, _ := reader.ReadString('\n')
	arr := strings.Split(strings.TrimSpace(arrTemp), " ")
	var arrItems []int64
	for _, arrItem := range arr {
		arrItemTemp, _ := strconv.ParseInt(arrItem, 10, 64)
		arrItems = append(arrItems, arrItemTemp)
	}
	var even []int64
	var odd []int64
	sum := int64(0)
	for _, arrItem := range arrItems {
		if arrItem%2 == 0 {
			even = append(even, arrItem)
		} else {
			odd = append(odd, arrItem)
		}
	}
	sort.Slice(odd, func(i, j int) bool {
		return odd[i] < odd[j]
	})
	for _, oddItem := range odd {
		sum += oddItem
	}
	if len(odd)%2!= 0 {
		sum -= odd[0]
	}
	fmt.Println(sum)
}

