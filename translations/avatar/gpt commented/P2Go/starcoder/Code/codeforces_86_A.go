// Read the input values for l and r, which define the range
l, r := strings.Split(bufio.NewReader(os.Stdin).ReadString(), " ")

// Initialize the current value to r and a counter for the number of digits
curr := r
s := 0

// Count the number of digits in the current value (r)
for curr > 0 {
    s++
    curr /= 10
}

// Calculate the first power of ten greater than r
first := 10 ** s

// Calculate the second value as half of the first power of ten
second := first / 2

// Initialize the answer variable to store the maximum product found
ans := -1

// Iterate through the possible candidates: l, r, first, and second
for _, i := range []string{l, r, fmt.Sprintf("%d", first), fmt.Sprintf("%d", second)} {
    // Check if the candidate is within the range [l, r]
    if i >= l && i <= r {
        curr := i
        rev := ""
        
        // Create the reverse number by subtracting each digit from 9
        for _, k := range i {
            rev += fmt.Sprintf("%d", 9 - int(k))
        }
        
        // Update the answer with the maximum product of the current number and its reverse
        ans = int(rev) * int(curr)
    }
}

// Print the maximum product found
fmt.Println(ans)

