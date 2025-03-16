
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
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	numSet := make(map[int]bool)
	_ = readLine(reader)
	for _, numStr := range strings.Split(readLine(reader), " ") {
		num, _ := strconv.Atoi(numStr)
		numSet[num] = true
	}
	twoTimesSet := make(map[int]bool)
	for num := range numSet {
		for i := 1; i < 30; i++ {
			num /= 2
			if num%2!= 0 {
				twoTimesSet[i] = true
				break
			}
			if len(twoTimesSet)!= 1 {
				fmt.Println(0)
				return
			}
		}
	}
	numList := make([]int, 0)
	for num := range numSet {
		numList = append(numList, num)
	}
	lcm := numList[0]
	for i := 1; i < len(numList); i++ {
		lcm = lcm*numList[i] / gcd(lcm, numList[i])
	}
	fmt.Println((n-lcm/2)/lcm + 1)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimSpace(string(str))
	}
	panic(err)
}

func gcd(a, b int) int {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

