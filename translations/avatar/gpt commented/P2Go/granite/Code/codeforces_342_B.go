
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Define a function to read multiple integers from input
	R := func() []int {
		data, _ := bufio.NewReader(os.Stdin).ReadString('\n')
		data = strings.Replace(data, "\n", "", -1)
		list := strings.Split(data, " ")
		res := make([]int, len(list))
		for i := 0; i < len(list); i++ {
			res[i], _ = strconv.Atoi(list[i])
		}
		return res
	}

	// Read the values of n (total positions), m (number of obstacles), s (starting position), and f (finishing position)
	n, m, s, f := R()

	// Determine the direction of movement based on the starting and finishing positions
	d := 1
	c := "R"
	if s < f {
		d = 1
		c = "R"
	} else {
		d = -1
		c = "L"
	}

	// Initialize the result string to store the path taken
	res := ""

	// Initialize the step counter and current position
	i := 1
	j := s

	// Read the first obstacle's position and range
	t, l, r := R()
	k := 1

	// Loop until the current position reaches the finishing position
	for j!= f {
		// Check if we need to read a new obstacle's position and range
		if i > t && k < m {
			t, l, r = R()
			k++
		}

		// Check if the current position is at an obstacle
		if i == t && (l <= j && j <= r || l <= j+d && j+d <= r) {
			res += "X"
		} else {
			res += c
			j += d
		}

		i++
	}

	// Print the resulting path taken
	fmt.Println(res)
}
