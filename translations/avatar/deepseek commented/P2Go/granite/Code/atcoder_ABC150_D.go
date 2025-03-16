

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
	fmt.Println("Enter the values for n and num:")
	text, _ := reader.ReadString('\n')
	n, num := readTwoNumbers(text)
	fmt.Println("Enter the set of integers:")
	text, _ = reader.ReadString('\n')
	numSet := readIntSet(text)
	twoTimesSet := make(map[int]bool)
	for i := range numSet {
		for j := 1; j <= 30; j++ {
			numSet[i] /= 2
			if numSet[i]%2!= 0 {
				twoTimesSet[j] = true
				break
			}
		}
		if len(twoTimesSet) > 1 {
			fmt.Println(0)
			return
		}
	}
	numList := make([]int, 0, len(numSet))
	for i := range numSet {
		numList = append(numList, int(numSet[i]))
	}
	lcm := numList[0]
	for i := 1; i < len(numList); i++ {
		lcm = lcm * numList[i] / gcd(lcm, numList[i])
	}
	fmt.Println((num-lcm/2)/lcm + 1)
}

func readTwoNumbers(line string) (int, int) {
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	n, _ := strconv.Atoi(parts[0])
	num, _ := strconv.Atoi(parts[1])
	return n, num
}

func readIntSet(line string) []int64 {
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	numSet := make([]int64, len(parts))
	for i, part := range parts {
		numSet[i], _ = strconv.ParseInt(part, 10, 64)
	}
	return numSet
}

func gcd(a, b int64) int64 {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

