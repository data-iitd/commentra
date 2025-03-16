// Get user input as a list of strings, split by space character, and convert each to an integer
var a, b int
fmt.Scanf("%d %d", &a, &b)

// Find the minimum value between 'a' and 'b'
minValue := min(a, b)

// Find the maximum value between 'a' and 'b'
maxValue := max(a, b)

// Print the minimum value and the average of the difference between minimum and maximum values
fmt.Printf("%d %d\n", minValue, (maxValue - minValue) / 2)

