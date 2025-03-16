
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var n int
	var t, h []string
	var taro, hanako int
	var i int

	// Read the number of strings to be compared from the standard input
<<<<<<< HEAD
	fmt.Scanf("%d", &n)
=======
	fmt.Scanf("%d\n", &n)
>>>>>>> 98c87cb78a (data updated)

	// Initialize the loops for t and h arrays
	for i = 0; i < n; i++ {
		// Read strings from the standard input and store them in t and h arrays
		t = append(t, readString())
		h = append(h, readString())

		// Compare the strings and update the scores accordingly
		if strings.Compare(t[i], h[i]) < 0 {
			hanako += 3
		} else if strings.Compare(t[i], h[i]) > 0 {
			taro += 3
		} else {
			taro += 1
			hanako += 1
		}
	}

	// Print the scores for Taro and Hanako
	fmt.Printf("%d %d\n", taro, hanako)
}

func readString() string {
	reader := bufio.NewReader(os.Stdin)
<<<<<<< HEAD
	input, _ := reader.ReadString('\n')
	return strings.TrimSpace(input)
=======
	str, _, _ := reader.ReadLine()
	return strings.TrimSpace(string(str))
>>>>>>> 98c87cb78a (data updated)
}

