// Get the initial values of v1, v2, t, and d from user input
v1, v2 := input.Split()
t, d := input.Split()

// Convert the input strings to integers
v1, _ = strconv.Atoi(v1)
v2, _ = strconv.Atoi(v2)
t, _ = strconv.Atoi(t)
d, _ = strconv.Atoi(d)

// Initialize variables
a := 1
v := v1
distance := 0

// For loop to calculate the total distance
for i := 0; i < t; i++ {
    // Check if v is ahead of v2 by more than the difference * (time - i)
    if v-v2 > (t-i)*d {
        // If so, change the direction of acceleration
        a *= -1
        // Update the position of v
        v = (t-i)*d + v2
    }

    // Add the current position of v to the total distance
    distance += v

    // Update the position of v based on the acceleration
    v += a * d
}

// Print the total distance
fmt.Println(distance)

