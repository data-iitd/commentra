// Read initial velocities v1 and v2 from user input
v1, v2 := fmt.Scanf("%d %d", &v1, &v2)
// Read time t and distance increment d from user input
t, d := fmt.Scanf("%d %d", &t, &d)

// Convert input values from strings to integers
v1 = int(v1)
v2 = int(v2)
t = int(t)
d = int(d)

// Initialize acceleration factor and current velocity
a := 1
v := v1

// Initialize total distance traveled
distance := 0

// Loop through each time unit from 0 to t-1
for i := 0; i < t; i++ {
    // Check if the current velocity can exceed the maximum allowed velocity
    if v - v2 > (t - i - 1) * d {
        // Reverse acceleration direction if the velocity exceeds the limit
        a *= -1
        // Adjust current velocity to not exceed the maximum allowed velocity
        v = (t - i - 1) * d + v2
    }

    // Add current velocity to total distance
    distance += v

    // Update current velocity based on acceleration direction
    v += a * d
}

// Print the total distance traveled after t time units
fmt.Printf("%d", distance)

