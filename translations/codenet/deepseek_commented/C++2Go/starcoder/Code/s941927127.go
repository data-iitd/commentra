
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

func main() {
	// Step 1: Read input
	// The program reads a string `W` from the standard input.
	reader := bufio.NewReader(os.Stdin)
	W, _ := reader.ReadString('\n')
	W = strings.TrimSpace(W)

	// Step 2: Sort the string
	// The string `W` is sorted in ascending order.
	sort.Strings(strings.Split(W, ""))

	// Step 3: Check for character pairs
	// The program iterates through the sorted string, checking if each character
	// is followed by its identical pair.
	for i := 0; i < len(W); i += 2 {
		if W[i]!= W[i+1] {
			// If a character is not followed by its pair, output "No" and exit.
			fmt.Println("No")
			return
		}
	}

	// Step 4: Output result
	// If all characters are in pairs, the program outputs "Yes"; otherwise,
	// it outputs "No".
	fmt.Println("Yes")
}

