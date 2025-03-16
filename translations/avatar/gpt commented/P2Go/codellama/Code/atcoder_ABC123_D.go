// Read integers x, y, z, and k from input
x, y, z, k := 0, 0, 0, 0
fmt.Scan(&x, &y, &z, &k)

// Read list a of size x from input
a := make([]int, x)
for i := 0; i < x; i++ {
	fmt.Scan(&a[i])
}

// Read list b of size y from input
b := make([]int, y)
for i := 0; i < y; i++ {
	fmt.Scan(&b[i])
}

// Read list c of size z from input
c := make([]int, z)
for i := 0; i < z; i++ {
	fmt.Scan(&c[i])
}

// Initialize an empty list to store the sums of elements from lists a and b
ab := make([]int, 0)

// Calculate all possible sums of elements from list a and list b
for i := 0; i < x; i++ {
	for j := 0; j < y; j++ {
		ab = append(ab, a[i]+b[j])
	}
}

// Sort the list of sums in descending order
sort.Sort(sort.Reverse(sort.IntSlice(ab)))

// Initialize an empty list to store the sums of the top k elements from ab and elements from list c
abc := make([]int, 0)

// Calculate sums of the top k elements from ab with each element in c
for i := 0; i < min(k, x*y); i++ {
	for j := 0; j < z; j++ {
		abc = append(abc, ab[i]+c[j])
	}
}

// Sort the resulting sums in descending order
sort.Sort(sort.Reverse(sort.IntSlice(abc)))

// Print the top k sums from the final list abc
for i := 0; i < k; i++ {
	fmt.Println(abc[i])
}

