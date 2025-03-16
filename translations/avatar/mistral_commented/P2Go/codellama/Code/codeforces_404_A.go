// Take the number of rows as input
n := int(input())

// Initialize an empty list 's' to store the rows
s := []

// Read each row and append it to the list 's'
for i := 0; i < n; i++ {
	// Read a row as a string and convert it to a list
	k := strings.Split(input(), " ")
	// Append the list to the list 's'
	s = append(s, k)
}

// Initialize flags and empty lists 'd1' and 'd2'
flag := 0
d1 := []
d2 := []

// Iterate through each element in the list 's'
for i := 0; i < n; i++ {
	// Iterate through each element in the same row and in the reverse order
	for j := 0; j < n; j++ {
		// If the current indices are same, append the element to 'd1'
		if i == j {
			d1 = append(d1, s[i][j])
		}
		// If the current indices are reverse of each other, append the element to 'd2'
		if i == n-j {
			d2 = append(d2, s[i][j])
		}
		// If the current indices are not same and not reverse, add the element to 'rem' set
		if i != j && i != n-j {
			rem.Add(s[i][j])
		}
	}
}

// Check if the size of 'rem' set is not equal to 1
if len(rem) != 1 {
	// If the condition is true, print 'NO' and exit
	fmt.Println("NO")
	os.Exit(0)
}

// Check if 'd1' and 'd2' lists are equal
if d1 != d2 {
	// If the condition is true, print 'NO' and exit
	fmt.Println("NO")
	os.Exit(0)
}

// Check if all elements in 'd1' are same
if len(rem) != 1 {
	// If the condition is true, print 'NO' and exit
	fmt.Println("NO")
	os.Exit(0)
}

// Check if all elements in 'd1' are present in 'rem' set
if rem.Equal(d1) {
	// If the condition is true, print 'NO' and exit
	fmt.Println("NO")
	os.Exit(0)
}

// If all the above conditions are false, print 'YES'
fmt.Println("YES")

