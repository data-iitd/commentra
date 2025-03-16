// Import the gcd function from the math module to calculate the greatest common divisor
import "math"

// Take an integer input from the user
var x int
fmt.Scanf("%d", &x)

// Calculate and print the number of equal parts in a full circle (360 degrees) 
// that can be formed with the given angle x using the gcd
fmt.Println(360 / int(math.GCD(360, float64(x))))

