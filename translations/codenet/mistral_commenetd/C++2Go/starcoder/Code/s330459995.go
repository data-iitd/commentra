<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
)

// Declare variables
var W, H, x, y, r int

func main() {
	// Read input values from user
	fmt.Scanf("%d %d %d %d %d", &W, &H, &x, &y, &r)

	// Check if point is inside the rectangle or not
	if x-r < 0 || x+r > W || y-r < 0 || y+r > H {
		// If point is outside the rectangle
		fmt.Println("No")
	} else if x-r >= 0 && x+r <= W && y-r >= 0 && y+r <= H {
		// If point is inside the rectangle
		fmt.Println("Yes")
	}
}

