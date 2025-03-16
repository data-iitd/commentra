
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Create a scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)
	
	// Read the number of sweet items (N) and the initial amount of money (x)
	sc.Scan()
	N, _ := fmt.Sscanf(sc.Text(), "%d", &N)
	sc.Scan()
	x, _ := fmt.Sscanf(sc.Text(), "%d", &x)
	
	// Initialize a slice to store the sweetness values of the items
	sweet := make([]int64, N)
	
	// Read the sweetness values and add them to the slice
	for i := 0; i < N; i++ {
		sc.Scan()
		a, _ := fmt.Sscanf(sc.Text(), "%d", &a)
		sweet[i] = int64(a)
	}
	
	// Sort the slice of sweetness values in ascending order
	sort.Slice(sweet, func(i, j int) bool {
		return sweet[i] < sweet[j]
	})
	
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

