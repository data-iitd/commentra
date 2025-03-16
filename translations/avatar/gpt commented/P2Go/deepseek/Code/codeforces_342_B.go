package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read the values of n (total positions), m (number of obstacles), s (starting position), and f (finishing position)
	readInt := func() int {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		return num
	}

	n := readInt()
	m := readInt()
	s := readInt()
	f := readInt()

	// Determine the direction of movement based on the starting and finishing positions
	var d int
	var c string
	if s < f {
		d = 1  // Move right
		c = "R"  // Character representing right movement
	} else {
		d = -1  // Move left
		c = "L"  // Character representing left movement
	}

	// Initialize the result string to store the path taken
	var res string

	// Initialize the step counter and current position
	i := 1
	j := s

	// Read the first obstacle's position and range
	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	l, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	r, _ := strconv.Atoi(scanner.Text())
	k := 1  // Counter for the number of obstacles processed

	// Loop until the current position reaches the finishing position
	for j != f {
		// Check if we need to read a new obstacle's position and range
		if i > t && k < m {
			scanner.Scan()
			t, _ = strconv.Atoi(scanner.Text())
			scanner.Scan()
			l, _ = strconv.Atoi(scanner.Text())
			scanner.Scan()
			r, _ = strconv.Atoi(scanner.Text())
			k += 1  // Increment the obstacle counter
		}

		// Check if the current position is at an obstacle
		if i == t && (l <= j && j <= r || l <= j+d && j+d <= r) {
			res += "X"  // Mark the position with 'X' if it's blocked by an obstacle
		} else {
			res += c  // Append the direction character to the result
			j += d  // Move to the next position in the determined direction
		}

		i += 1  // Increment the step counter
	}

	// Print the resulting path taken
	fmt.Println(res)
}
