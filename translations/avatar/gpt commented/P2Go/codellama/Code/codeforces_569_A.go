// Read three integers from input: t (target), s (initial value), and q (growth factor)
t, s, q := 0, 0, 0
fmt.Scan(&t, &s, &q)

// Initialize a counter for the number of iterations
ans := 0

// Loop until the initial value s is less than the target t
for s < t {
    // Multiply the current value of s by the growth factor q
    s *= q
    // Increment the counter for each multiplication
    ans++
}

// Print the total number of multiplications needed for s to reach or exceed t
fmt.Println(ans)

