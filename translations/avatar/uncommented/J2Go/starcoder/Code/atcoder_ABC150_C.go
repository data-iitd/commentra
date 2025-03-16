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
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the elements of the array")
	line := make([]string, 2)
	for i := 0; i < 2; i++ {
		line[i] = strings.Fields(reader.ReadString('\n'))[0]
	}
	number := ""
	for i := 1; i <= n; i++ {
		number += string(i)
	}
	listA := make([]string, 0)
	permutation(listA, number, "", line)
	sum := 0
	for j := 0; j < len(line); j++ {
		for i := 0; i < len(listA); i++ {
			if listA[i] == line[j] {
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

func permutation(listA []string, number string, ans string, line []string) {
	if len(number) <= 1 {
		listA = append(listA, ans+number)
	} else {
		for i := 0; i < len(number); i++ {
			permutation(listA, number[0:i]+number[i+1:], ans+number[i], line)
		}
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

