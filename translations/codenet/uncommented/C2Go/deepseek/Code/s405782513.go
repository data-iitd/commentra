package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	
	for scanner.Scan() {
		var c [3]int
		_, err := fmt.Sscanf(scanner.Text(), "%d %d %d", &c[0], &c[1], &c[2])
		if err != nil {
			break
		}
		
		card := [10]int{}
		for i := 0; i < 3; i++ {
			card[c[i]-1] = 1
		}
		
		sum := c[0] + c[1]
		count := 0
		for i := 0; i < 10; i++ {
			if card[i] == 0 && sum+i+1 <= 20 {
				count++
			}
		}
		
		if count >= 4 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

