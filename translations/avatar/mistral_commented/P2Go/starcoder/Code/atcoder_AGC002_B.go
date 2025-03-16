#######
// Code
#######

// Import necessary modules and functions
import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Define constants
const (
	INF = math.MaxInt32
	mod = 1e9 + 7
)

// Read input number of balls and number of events
func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the first line
	line, _ := reader.ReadString('\n')
	// Split the line into two space-separated integers
	N, M := strings.Split(line, " "), 0
	// Convert the two space-separated integers into integers
	N, _ = strconv.Atoi(N[0])
	M, _ = strconv.Atoi(N[1])
	// Initialize list of balls with their weight and position
	balls := make([][]int, N)
	for i := 0; i < N; i++ {
		balls[i] = make([]int, 2)
	}
	balls[0][0], balls[0][1] = 0, 1
	// Process each event
	for i := 0; i < M; i++ {
		// Read x and y coordinates of the event
		line, _ := reader.ReadString('\n')
		// Split the line into two space-separated integers
		x, y := strings.Split(line, " "), 0
		// Convert the two space-separated integers into integers
		x, _ = strconv.Atoi(x[0])
		y, _ = strconv.Atoi(x[1])
		// Get weight and position of balls at x and y
		w_x, r_x := balls[x - 1][0], balls[x - 1][1]
		w_y, r_y := balls[y - 1][0], balls[y - 1][1]
		// Update balls' weights and positions based on the event
		if w_x >= 1 && r_x >= 1 {
			// Ball x collides with ball y
			balls[x - 1][0] -= 1
			balls[y - 1][1] += 1
		} else if w_x == 0 {
			// Ball x is stationary and ball y collides with another ball
			balls[x - 1][1] -= 1
			balls[y - 1][1] += 1
		} else {
			// Ball x is moving and collides with ball y
			balls[x - 1][0] -= 1
			balls[y - 1][0] += 1
	}
	// Calculate answer
	ans := 0
	// Iterate through the list of balls and count the number of moving balls
	for i := 0; i < N; i++ {
		if balls[i][1] {
			ans += 1
	}
	// Print the answer
	fmt.Println(ans)
}

// 