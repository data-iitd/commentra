

ABC := [3]int{}  // Declare an array ABC of size 3 and initialize all elements to 0
fmt.Scan(&ABC[0], &ABC[1], &ABC[2])  // Take input from user and store in array ABC

// Check if the array contains exactly two 5s
count := 0
for _, v := range ABC {
    if v == 5 {
        count++
    }
}
if count == 2 {
    // Check if the sum of the elements in ABC is 17
    sum := 0
    for _, v := range ABC {
        sum += v
    }
    if sum == 17 {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
} else {
    fmt.Println("NO")
}

