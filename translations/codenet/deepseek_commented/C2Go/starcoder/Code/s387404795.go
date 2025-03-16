<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"strings"
)

func main() {
	var str, tmp, p string
	var slen, plen int
	var i, j int
	var flag int

	// Read two strings from the user
	fmt.Scanf("%s %s", &str, &p)

	// Duplicate and concatenate the string
	tmp = str
	str += tmp

	// Calculate the lengths of the strings
	slen = len(str)
	plen = len(p)

	// Initialize flag to 0 (not found)
	flag = 0

	// Check if the pattern exists in the concatenated string
	for i = 0; i < slen-plen; i++ {
		if strings.Compare(str[i:i+plen], p) == 0 {
			flag = 1
		}
	}

	// Output the result
	if flag == 1 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

