
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func permutation(list []string, target string, ans string) []string {
	if len(target) <= 1 {
		list = append(list, ans+target)
	} else {
		for i := 0; i < len(target); i++ {
			list = permutation(list, target[:i]+target[i+1:], ans+string(target[i]))
		}
	}
	return list
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	n, _ := strconv.Atoi(scanner.Text())
	line := make([][]string, 2)
	for i := 0; i < 2; i++ {
		line[i] = make([]string, n)
		for j := 0; j < n; j++ {
			scanner.Scan()
			line[i][j] = scanner.Text()
		}
	}
	number := ""
	for i := 1; i <= n; i++ {
		number += strconv.Itoa(i)
	}
	listA := make([]string, 0)
	listA = permutation(listA, number, "")
	sum := 0
	for j := 0; j < len(line); j++ {
		for i := 0; i < len(listA); i++ {
			if listA[i] == line[j][0] {
				if sum == 0 {
					sum += i
				} else {
					sum -= i
				}
			}
		}
	}
	fmt.Println(abs(sum))
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

