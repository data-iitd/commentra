<<<<<<< HEAD

import (
	"fmt"
	"math"
=======
package main

import (
	"bufio"
	"fmt"
>>>>>>> 98c87cb78a (data updated)
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input string from standard input
<<<<<<< HEAD
	str := strings.TrimSpace(string(os.Stdin.Read(1000000)))
=======
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
>>>>>>> 98c87cb78a (data updated)

	// Initialize sum variable to 0
	sum := 0

	// Iterate through each character in the string and add its ASCII value (after converting to digit) to sum
	for _, x := range str {
		sum += int(x) - 48
	}

	// Check if sum is divisible by 9
	if sum%9 == 0 {
		fmt.Println("Yes") // Output "Yes" if sum is divisible by 9
	} else {
		fmt.Println("No") // Output "No" otherwise
	}
}

Translate the above Go code to Python and end with comment "