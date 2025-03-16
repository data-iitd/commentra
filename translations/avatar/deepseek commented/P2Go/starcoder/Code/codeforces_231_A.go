// Take an integer input `n` which represents the number of lists to be provided as input.
n := int(input())

// Initialize a counter `c` to 0. This will keep track of the number of lists where the sum of elements is greater than 1.
c := 0

// Loop `n` times to process each list of integers.
for i := 0; i < n; i++ {
    // Take a list of integers as input, split them by spaces, convert them to integers, and store them in `l1`.
    l1 := strings.Split(input(), " ")
    l1 = make([]int, len(l1))
    for j := 0; j < len(l1); j++ {
        l1[j], _ = strconv.Atoi(l1[j])
    }

    // Calculate the sum of the elements in `l1`.
    // If the sum is greater than 1, increment the counter `c` by 1.
    if sum(l1) > 1 {
        c++
    }
}

// After the loop completes, print the final value of `c`, which represents the number of lists where the sum of elements is greater than 1.
fmt.Println(c)

