package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the number of sweet items (N) and the initial amount of money (x)
	line, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(line))
	line, _ = reader.ReadString('\n')
	x, _ := strconv.Atoi(strings.TrimSpace(line))

	// Initialize a list to store the sweetness values of the items
	sweet := make([]int, N)

	// Read the sweetness values and add them to the list
	for i := 0; i < N; i++ {
		line, _ := reader.ReadString('\n')
		sweet[i], _ = strconv.Atoi(strings.TrimSpace(line))
	}

	// Sort the list of sweetness values in ascending order
	sort.Ints(sweet)

	// Initialize a counter for the number of sweet items that can be bought
	num := 0

	// Iterate through the sorted sweetness values
	for i := 0; i < N; i++ {
		// Check if the current sweetness value can be bought with the remaining money
		if x-sweet[num] >= 0 {
			// Deduct the sweetness value from the total money
			x = x - sweet[num]
			// Increment the count of items bought
			num++
		} else {
			// If the current item cannot be bought, exit the loop
			break
		}
	}

	// Adjust the count if all items were bought but there is still money left
	if num == N && x > 0 {
		num -= 1
	}

	// Print the total number of sweet items that can be bought
	fmt.Println(num)
}

