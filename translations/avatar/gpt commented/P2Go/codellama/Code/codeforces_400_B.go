// Read two integers n and m from input, representing the number of strings and some other parameter
n, m := 0, 0
fmt.Scan(&n, &m)

// Create a set comprehension to calculate the difference in indices of 'S' and 'G' for each string
// The difference is calculated as the index of 'S' minus the index of 'G'
c := make(map[int]bool)
for i := 0; i < n; i++ {
	s := ""
	fmt.Scan(&s)
	c[strings.Index(s, "S")-strings.Index(s, "G")] = true
}

// Check if any of the calculated differences are negative
// If any difference is negative, print -1; otherwise, print the number of unique differences
for k := range c {
	if k < 0 {
		fmt.Println(-1)
		return
	}
}
fmt.Println(len(c))


