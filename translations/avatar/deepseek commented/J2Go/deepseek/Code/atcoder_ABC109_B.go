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
	N := 0
	fmt.Sscanf(scanner.Text(), "%d", &N)
	
	mp := make(map[int]string)
	
	for i := 0; i < N; i++ {
		scanner.Scan()
		mp[i] = scanner.Text()
	}
	
	ans := true
	past := make(map[int]string)
	var next string
	
	for i := 0; i < N; i++ {
		if _, ok := past[i]; ok {
			ans = false
			break
		}
		past[i] = mp[i]
		
		if i != 0 {
			if next != string(mp[i][0]) {
				ans = false
				break
			}
		}
		next = string(mp[i][len(mp[i])-1])
	}
	
	if ans {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
