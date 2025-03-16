
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Main function: This is the entry point of the program.
func main() {
	reader := bufio.NewReader(os.Stdin)
	var testCases int
	fmt.Fscan(reader, &testCases)
	for i := 0; i < testCases; i++ {
		var s string
		fmt.Fscan(reader, &s)
		if strings.Contains(s, "A") && strings.Contains(s, "B") {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

// END-OF-CODE

