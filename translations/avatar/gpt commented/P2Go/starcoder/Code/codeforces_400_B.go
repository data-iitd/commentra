// Read two integers n and m from input, representing the number of strings and some other parameter
n, m := strconv.Atoi(input())

// Create a set comprehension to calculate the difference in indices of 'S' and 'G' for each string
// The difference is calculated as the index of 'S' minus the index of 'G'
c := map[int]struct{}{}
for i := 0; i < n; i++ {
	s := input()
	c[s.Index("S") - s.Index("G")] = struct{}{}
}

// Check if any of the calculated differences are negative
// If any difference is negative, print -1; otherwise, print the number of unique differences
if len(c) == 0 {
	fmt.Println(-1)
} else {
	fmt.Println(len(c))
}

