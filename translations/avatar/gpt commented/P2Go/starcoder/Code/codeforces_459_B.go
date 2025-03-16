// Read an integer input for the number of elements
n := int(input())

// Read a line of input, split it into individual strings, convert them to integers, and store them in a list
l1 := strings.Split(input(), " ")
l1 = make([]int, len(l1))
for i := range l1 {
    l1[i], _ = strconv.Atoi(l1[i])
}

// Sort the list of integers in ascending order
sort.Ints(l1)

// Assign the maximum value in the list to variable 'a'
a := l1[len(l1)-1]

// Assign the minimum value in the list to variable 'b'
b := l1[0]

// Check if the maximum and minimum values are the same
if a == b {
    // If they are the same, the difference is zero and the number of pairs is n choose 2
    fmt.Println(a - b, (n) * (n - 1) / 2)
} else {
    // Count occurrences of the maximum value 'a' in the list
    ac := 0
    for _, v := range l1 {
        if v == a {
            ac++
        }
    }

    // Count occurrences of the minimum value 'b' in the list
    bc := 0
    for _, v := range l1 {
        if v == b {
            bc++
        }
    }

    // Calculate the difference between the maximum and minimum values, and the product of their counts
    fmt.Println(a - b, ac * bc)
}

