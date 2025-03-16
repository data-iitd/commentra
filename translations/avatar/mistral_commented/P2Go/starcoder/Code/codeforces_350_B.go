// Take the number of test cases as input
n := int(input())

// Initialize a list 't' with 0 as the first element and followed by the given input list
t := []int{0}
for _, v := range strings.Split(input(), " ") {
    t = append(t, int(v))
}

// Initialize a list 'a' with 0 as the first element and followed by the given input list
a := []int{0}
for _, v := range strings.Split(input(), " ") {
    a = append(a, int(v))
}

// Initialize empty lists 'ans' and 'cnt'
ans, cnt := []int{}, make([]int, n+1)

// Iterate through each element in list 'a' and increment the count of its corresponding index in list 'cnt'
for i := range a {
    cnt[a[i]]++
}

// Iterate through each index from 1 to n
for i := 1; i <= n; i++ {
    // If the current index in list 't' is 1
    if t[i] == 1 {
        // Initialize an empty list 'crt' to store the current sequence
        crt := []int{i}
        // Get the current element in list 'a'
        x := a[i]
        // Continue adding elements to 'crt' as long as the corresponding index in 'cnt' has a count of 1
        for cnt[x] == 1 {
            crt = append(crt, x)
            x = a[x]
        }
        // If the length of the current sequence is greater than the length of the current answer sequence
        if len(crt) > len(ans) {
            // Update the answer sequence with the current sequence
            ans = crt[:]
        }
    }
}

// Reverse the order of elements in the answer sequence
for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
    ans[i], ans[j] = ans[j], ans[i]
}

// Print the length of the answer sequence
fmt.Println(len(ans))
// Print the answer sequence with each element separated by a space
fmt.Println(strings.Trim(strings.Join(strings.Fields(fmt.Sprint(ans)), " "), "[]"))

