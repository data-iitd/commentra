package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := fmt.Sscan(scanner.Text(), &N)
	
	map1 := make(map[int]string)
	for i := 0; i < N; i++ {
		scanner.Scan()
		map1[i] = scanner.Text()
	}
	
	ans := true
	map2 := make(map[int]string)
	next := ""
	for i := 0; i < N; i++ {
		if _, exists := map2[i]; exists {
			ans = false
			break
		}
		map2[i] = map1[i]
		if i != 0 {
			if next != string(map1[i][0]) {
				ans = false
				break
			}
		}
		next = string(map1[i][len(map1[i])-1])
	}
	
	if ans {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

