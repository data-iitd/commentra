// Read input values for 'a', 'b', and 't' from the user
var a, b, t int
fmt.Scanf("%d %d %d", &a, &b, &t)

// Initialize the cookie count to zero
var cookie int

// Set the initial time to 'a'
var time int = a

// Loop until the time exceeds 't + 0.5'
for time <= t + 0.5 {
    // Add 'b' cookies for each time interval
    cookie += b
    // Increment the time by 'a' for the next iteration
    time += a
}

// Print the total number of cookies collected
fmt.Println(cookie)

