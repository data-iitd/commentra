#######
# Code
#######

// Define input variables
var n, k int
fmt.Scan(&n, &k)
// n: number of characters in the string s
// k: number of occurrences of a character we want to find

var s string
fmt.Scan(&s)
// s: string to be processed

// Initialize a list to store the count of each character
count := make([]int, 26)

// Iterate through each character in the string s
for _, c := range s {
    // Increment the count of the character in the list count
    count[c-'A']++
}

// Sort the count list in descending order
sort.Sort(sort.Reverse(sort.IntSlice(count)))

// Initialize result variable
res := 0

// Iterate through each character count in the list count
for i := 0; i < 26; i++ {
    // Check if the count of the current character is greater than or equal to k
    if count[i] >= k {
        // Calculate the result and print it
        res += k * k
        fmt.Println(res)
        // Exit the loop as we have found the required characters
        return
    }
    // Update the value of k by subtracting the count of the current character
    k -= count[i]
    // Add the square of the count of the current character to the result
    res += count[i] * count[i]
}

// Print the final result if no character is found with the required count
fmt.Println(res)

