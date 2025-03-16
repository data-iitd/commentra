package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	lstStr := scanner.Text()
	lst := []int{}
	for _, numStr := range strings.Split(lstStr, " ") {
		num, _ := strconv.Atoi(numStr)
		lst = append(lst, num)
	}
	sort.Ints(lst)
	for i, j := 0, len(lst)-1; i < j; i, j = i+1, j-1 {
		lst[i], lst[j] = lst[j], lst[i]
	}
	od := 0
	for _, i := range lst {
		if i%2 != 0 {
			od += 1
		}
	}
	sum := 0
	ok := false
	for i := 0; i < n; i++ {
		if lst[i]%2 == 0 {
			sum += lst[i]
		} else {
			if ok || od > 1 {
				sum += lst[i]
				od -= 1
				ok = !ok
			}
		}
	}
	fmt.Println(sum)
}
