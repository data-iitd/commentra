
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Step 1: Read three integers from input.
	reader := bufio.NewReader(os.Stdin)
	for {
		line, _, err := reader.ReadLine()
		if err!= nil {
			break
		}
		cards := strings.Fields(string(line))
		c := make([]int, 3)
		for i := 0; i < 3; i++ {
			c[i], _ = strconv.Atoi(cards[i])
		}
		
		// Step 2: Initialize an array to keep track of the cards.
		card := make([]bool, 10)
		// Initialize a counter to count the number of valid cards.
		count := 0
		// Calculate the sum of the two known cards.
		sum := c[0] + c[1]
		
		// Step 3: Loop through the cards and mark them in the array.
		for i := 0; i < 3; i++ {
			card[c[i]-1] = true
		}
		
		// Step 4: Check which cards can be added to the sum without exceeding 20.
		for i := 0; i < 10; i++ {
			if!card[i] && sum+i+1 <= 20 {
				count++
			}
		}
		
		// Step 5: Determine if at least 4 such cards exist.
		if count >= 4 {
			// Step 6: Print "YES" if such cards exist.
			fmt.Println("YES")
		} else {
			// Step 7: Print "NO" otherwise.
			fmt.Println("NO")
		}
	}
}
