package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	
	var n int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n)
	
	treeMap := make(map[int]int)
	
	for i := 0; i < n; i++ {
		scanner.Scan()
		num := 0
		fmt.Sscan(scanner.Text(), &num)
		
		if lowerKey, exists := findLowerKey(treeMap, num); !exists {
			val := treeMap[num]
			if val == 0 {
				val = 0
			}
			treeMap[num] = val + 1
		} else {
			key := lowerKey
			val := treeMap[key]
			if val == 1 {
				delete(treeMap, key)
			} else {
				treeMap[key] = val - 1
			}
			treeMap[num] = treeMap[num] + 1
		}
	}
	
	ans := 0
	for _, val := range treeMap {
		ans += val
	}
	fmt.Println(ans)
}

func findLowerKey(treeMap map[int]int, num int) (int, bool) {
	for key := range treeMap {
		if key < num {
			return key, true
		}
	}
	return 0, false
}

