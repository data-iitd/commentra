// Create a list 'A' from the input, which is a sequence of space-separated integers
var A []int
for _, value := range strings.Fields(input()) {
    A = append(A, strconv.Atoi(value))
}

// Check if the second or third element of the list 'A' is less than or equal to the first element
if A[1] <= A[2] || A[3] <= A[0] {
    // If the condition is true, print '0'
    fmt.Println(0)
} else {
    // If the condition is false, sort the list 'A' in ascending order
    sort.Ints(A)

    // Print the difference between the third and second elements of the sorted list
    fmt.Println(A[2] - A[1])
}

