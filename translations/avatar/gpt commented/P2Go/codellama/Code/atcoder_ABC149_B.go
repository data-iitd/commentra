// Read a line of input, split it into parts, and convert each part to an integer
cookies := make([]int, 3)
fmt.Scan(&cookies[0], &cookies[1], &cookies[2])

// Calculate the leftover cookies after taking some from the third type
leftOver := cookies[0] - cookies[2]

// Determine the number of cookies Takahashi can take, ensuring it's not negative
takahashi := 0
if leftOver > 0 {
    takahashi = leftOver
}

// Print the number of cookies Takahashi can take, and the remaining cookies of the second type
// If Takahashi can take cookies, print the second type's count; otherwise, calculate the remaining
fmt.Printf("%d %d\n", takahashi, cookies[1]-takahashi)

// 