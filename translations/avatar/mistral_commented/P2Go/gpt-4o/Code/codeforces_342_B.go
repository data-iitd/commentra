package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Define a function to read a line of input and convert it to a slice of integers
	var R = func() []int {
		var input string
		fmt.Scanln(&input)
		parts := strings.Split(input, " ")
		var result []int
		for _, part := range parts {
			num, _ := strconv.Atoi(part)
			result = append(result, num)
		}
		return result
	}

	// Read the input values: n (number of test cases), m (number of tracks), s (starting position), and f (final position)
	input := R()
	n, m, s, f := input[0], input[1], input[2], input[3]

	// Check if the starting position is less than the final position
	var d int
	var c string
	if s < f {
		d = 1
		c = "R"
	} else {
		d = -1
		c = "L"
	}

	// Initialize an empty string to store the output
	res := ""

	// Initialize variables i and j with initial values
	i := 1
	j := s

	// Read the next input: three integers t, l, and r representing the length, left end, and right end of a track
	t, l, r := R()[0], R()[1], R()[2]

	// Initialize a variable k to keep track of the number of tracks
	k := 1

	// While the current position j is not equal to the final position f
	for j != f {
		// If we have read all the tracks or the current position i is not in the current track
		if i > t && k < m {
			// Read the next input: three integers t, l, and r representing the length, left end, and right end of the next track
			nextInput := R()
			t, l, r = nextInput[0], nextInput[1], nextInput[2]
			// Increment the number of tracks
			k++
		}

		// If the current position i is in the current track (either it is the same track or it overlaps with the current track)
		if i == t && (l <= j && j <= r || l <= j+d && j+d <= r) {
			// Append 'X' to the output string
			res += "X"
		} else {
			// Append the corresponding direction character 'R' or 'L' to the output string
			res += c
			// Update the current position j based on the direction
			j += d
		}
		// Increment the current position i
		i++
	}

	// Print the output string
	fmt.Println(res)
}

// <END-OF-CODE>
