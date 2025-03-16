
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Declare and initialize variables
func main() {
	var s string
<<<<<<< HEAD
	fmt.Scanln(&s)
=======
	fmt.Scanf("%s", &s)
>>>>>>> 98c87cb78a (data updated)
	n := len(s)
	v := make([]int, 26)

	// Read each character of the string's' and increment the corresponding index in array 'v'
	for i := 0; i < n; i++ {
		v[int(s[i]-'a')]++
	}

	// Initialize answer string to "Yes"
	ans := "Yes"

	// Check if all elements in array 'v' are even
	for i := 0; i < 26; i++ {
		if v[i]%2!= 0 {
			ans = "No"
			break
		}
	}

	// Print the answer
	fmt.Println(ans)
}

