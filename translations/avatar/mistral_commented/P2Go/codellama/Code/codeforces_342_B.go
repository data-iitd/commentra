#######
# Code
#######

// Define a function to read a line of input and convert it to a list of integers
func R() (int, int, int, int) {
	var n, m, s, f int
	fmt.Scan(&n, &m, &s, &f)
	return n, m, s, f
}

// Read the input values: n (number of test cases), m (number of tracks), s (starting position), and f (final position)
n, m, s, f := R()

// Check if the starting position is less than the final position
if s < f {
	// Initialize direction and corresponding character
	d := 1
	c := 'R'
} else {
	// Initialize direction with negative sign and corresponding character 'L'
	d := -1
	c := 'L'
}

// Initialize an empty string to store the output
res := ""

// Initialize variables i and j with initial values
i := 1
j := s

// Read the next input: three integers t, l, and r representing the length, left end, and right end of a track
t, l, r := R()

// Initialize a variable k to keep track of the number of tracks
k := 1

// While the current position j is not equal to the final position f
for j != f {
	// If we have read all the tracks or the current position i is not in the current track
	if i > t && k < m {
		// Read the next input: three integers t, l, and r representing the length, left end, and right end of the next track
		t, l, r = R()
		// Increment the number of tracks
		k += 1
	}

	// If the current position i is in the current track (either it is the same track or it overlaps with the current track)
	if i == t && (l <= j <= r || l <= j+d <= r) {
		// Append 'X' to the output string
		res += "X"
	} else {
		// Append the corresponding direction character 'R' or 'L' to the output string
		res += string(c)
		// Update the current position j based on the direction
		j += d
	}
	// Increment the current position i
	i += 1
}

// Print the output string
fmt.Println(res)


