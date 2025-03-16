// Define a function to read multiple integers from input
func R() (int, int, int, int) {
	var n, m, s, f int
	fmt.Scan(&n, &m, &s, &f)
	return n, m, s, f
}

// Determine the direction of movement based on the starting and finishing positions
var d int
var c string
if s < f {
	d = 1 // Move right
	c = "R" // Character representing right movement
} else {
	d = -1 // Move left
	c = "L" // Character representing left movement
}

// Initialize the result string to store the path taken
var res string

// Initialize the step counter and current position
var i, j int = 1, s

// Read the first obstacle's position and range
t, l, r := R()
k := 1 // Counter for the number of obstacles processed

// Loop until the current position reaches the finishing position
for j != f {
	// Check if we need to read a new obstacle's position and range
	if i > t && k < m {
		t, l, r = R() // Read the next obstacle's position and range
		k++ // Increment the obstacle counter
	}

	// Check if the current position is at an obstacle
	if i == t && (l <= j <= r || l <= j+d <= r) {
		res += "X" // Mark the position with 'X' if it's blocked by an obstacle
	} else {
		res += c // Append the direction character to the result
		j += d // Move to the next position in the determined direction
	}

	i++ // Increment the step counter
}

// Print the resulting path taken
fmt.Println(res)

