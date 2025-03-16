// Take two integers as input and store them in list 'l' and 'r' respectively
l, r := []int{}
for _, v := range strings.Split(fmt.Scanf("%d %d\n"), " ") {
    l = append(l, int(v))
}

// Initialize current number to 'r'
curr := r

// Initialize sum variable's' to 0
s := 0

// While 'curr' is not zero, perform the following operations
for curr!= 0 {
    // Increment the sum's' by 1
    s++
    
    // Calculate the power of 10 raised to the value of's' and store it in 'first'
    first := 10 ** s
    
    // Calculate half of 'first' and store it in'second'
    second := first / 2
    
    // Initialize 'ans' with a negative value
    ans := -1
    
    // Iterate through the list containing 'l', 'r', 'first', and'second'
    for _, v := range []int{l, r, first, second} {
        // If 'i' lies within the range of 'l' and 'r', update 'curr' and'rev'
        if v >= l && v <= r {
            curr = v
            rev := ""
            // Reverse the digits of 'curr' and store it in'rev'
            for _, k := range []rune(fmt.Sprintf("%d", curr)) {
                rev += fmt.Sprintf("%d", 9-int(k))
            
            // Update 'ans' with the maximum value of the current 'ans' and the product of 'curr' and the reversed number
            ans = max(ans, int(rev)*curr)

// Print the final answer
fmt.Printf("%d\n", ans)

