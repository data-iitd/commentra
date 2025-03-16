// Read an integer input which represents the number of elements
n, _ := strconv.Atoi(input())

// Read a line of input, split it into individual elements, convert them to integers,
// and create a list that contains 1 for odd numbers and 0 for even numbers
list := make([]int, n)
for i := 0; i < n; i++ {
    list[i], _ = strconv.Atoi(input())
}

// Check if there is exactly one odd number in the list
var oddCount int
for _, v := range list {
    if v % 2 == 1 {
        oddCount++
    }
}
if oddCount == 1 {
    // If there is one odd number, print its position (1-based index)
    fmt.Println(list[oddCount-1])
} else {
    // If there are no odd numbers, print the position of the first even number (1-based index)
    for i, v := range list {
        if v % 2 == 0 {
            fmt.Println(i + 1)
            break
        }
    }
}

// 