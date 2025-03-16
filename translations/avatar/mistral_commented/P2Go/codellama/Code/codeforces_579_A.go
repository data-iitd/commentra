// Import the math package for log2 function
import "math"

// Take an integer input from the user and assign it to the variable n
n := int(input())

// Initialize a counter variable x to 1
x := 1

// While loop starts
for {
    // Check if the log base 2 of n is an integer yet
    if math.Log2(float64(n)) == float64(int(math.Log2(float64(n)))) {
        break
    }

    // Increment the counter variable x by 1
    x += 1

    // Update the value of n by subtracting 2 raised to the power of the current log base 2 of n
    n -= int(math.Pow(2, math.Log2(float64(n))))
}

// Print the output value of x
fmt.Println(x)

