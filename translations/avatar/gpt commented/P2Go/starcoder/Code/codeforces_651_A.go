// Read two integers from input and assign them to x and y
x, y := strconv.Atoi(input())

// Calculate the maximum value based on the formula and print it
// The formula computes x + y - 3 and adjusts based on the difference between y and x
// It ensures the result is not negative by taking the maximum with 0
fmt.Println(int(math.Max(float64(x + y - 3 + ((y - x) % 3 > 0)), 0)))

// 