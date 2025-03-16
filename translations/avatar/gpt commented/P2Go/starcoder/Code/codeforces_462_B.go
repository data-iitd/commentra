// Read two integers n and k from input
n, k := strconv.Atoi(input())

// Read the string s from input
s := input()

// Initialize a list to count occurrences of each letter (A-Z)
count := make([]int, 26)

// Count the occurrences of each character in the string
for _, c := range s {
    count[c-'A']++
}

// Sort the count list in descending order to prioritize higher counts
sort.Slice(count, func(i, j int) bool { return count[i] > count[j] })

// Initialize the result variable to accumulate the final score
res := 0

// Iterate through the sorted count list
for i := 0; i < 26; i++ {
    // If the current count is greater than or equal to k
    if count[i] >= k {
        // Add k squared to the result and print it
        res += k * k
        fmt.Println(res)
        // 