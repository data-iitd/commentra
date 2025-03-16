package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	var n int
	fmt.Sscan(scanner.Text(), &n)

	mapCount := make(map[int]int)

	for n > 0 {
		scanner.Scan()
		var num int
		fmt.Sscan(scanner.Text(), &num)

		if lowerKey := findLowerKey(mapCount, num); lowerKey == -1 {
			mapCount[num]++
		} else {
			val := mapCount[lowerKey]
			if val == 1 {
				delete(mapCount, lowerKey)
			} else {
				mapCount[lowerKey]--
			}
			mapCount[num]++
		}
		n--
	}

	ans := 0
	for _, val := range mapCount {
		ans += val
	}
	fmt.Println(ans)
}

func findLowerKey(m map[int]int, num int) int {
	lowerKey := -1
	for key := range m {
		if key < num {
			if lowerKey == -1 || key > lowerKey {
				lowerKey = key
			}
		}
	}
	return lowerKey
}

// <END-OF-CODE>
