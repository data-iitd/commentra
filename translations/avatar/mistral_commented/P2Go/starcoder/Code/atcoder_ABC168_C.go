// Assign values to variables a, b, h, and m using the input function and map function
var a, b, h, m int
fmt.Scanf("%d %d %d %d", &a, &b, &h, &m)

// Import the math module for mathematical functions
import "math"

// Calculate the angle C between hour hand and minute hand
C := math.Abs(360 / 60 * m - 360 / 12 * h - 360 / 12 / 60 * m)
if C > 180 {
    // If angle C is greater than 180 degrees, subtract it from 360 to get the correct value
    C = 360 - C
}

// Calculate the cosine of angle C
cosC := math.Cos(math.Pi / 180 * C)

// Calculate and print the length of the side of the right triangle formed by the hour and minute hands
fmt.Println(math.Sqrt(float64(a * a + b * b - 2 * a * b * cosC)))

