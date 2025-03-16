// Read the number of elements `n` and the number of queries `k` from the standard input
n, k := strconv.Atoi(input())

// Read a single string `v` from the standard input
v := input()

// Initialize a list `d` with two elements: "LEFT" and "RIGHT"
d := []string{"LEFT", "RIGHT"}

// Determine the direction based on the difference between `k` and `n-k`
f := k-1 < n-k

// Determine the number of elements to be appended to the list `a`
m := min(k-1, n-k)

// Initialize an empty list `a`
a := []string{}

// Append "LEFT" or "RIGHT" to the list `a` based on the value of `f`
for i := 0; i < m; i++ {
    a = append(a, d[not f])
}

// Iterate through the string `v` with a step of 2 times the value of `f`
for i := 0; i < len(v); i += 2*f {
    // Append "PRINT <character>" and the corresponding direction to the list `a`
    a = append(a, fmt.Sprintf("PRINT %c", v[i]))
    a = append(a, d[f])
}

// Print all the elements of the list `a`, except the last one, separated by newline characters
fmt.Println(strings.Join(a[:len(a)-1], "\n"))

