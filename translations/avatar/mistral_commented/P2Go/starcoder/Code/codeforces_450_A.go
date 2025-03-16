#######
// Code
#######

// Define the number of elements 'n' and the modulus'm' in the list 'l'
var n, m int
fmt.Scanf("%d %d", &n, &m)

// Initialize an empty list 'l2' to store the quotient of each element in 'l' divided by'm'
l2 := []int{}

// Iterate through each element 'i' in the list 'l'
for _, i := range l {
    // Check if the element 'i' is divisible by'm'. If yes, append the quotient (integer division) to 'l2'. If not, append the quotient plus one.
    if i%m == 0 {
        l2 = append(l2, i/m)
    } else {
        l2 = append(l2, int(i/m+1))
    }
}

// Find the maximum quotient in 'l2'
mx := 0
for _, i := range l2 {
    if i > mx {
        mx = i
    }
}

// Iterate through each index 'i' from 0 to 'n-1' in the list 'l2'
for i := 0; i < n; i++ {
    // Check if the quotient at index 'i' in 'l2' is equal to the maximum quotient'mx'. If yes, store the index 'i' in the variable 'ind'.
    if l2[i] == mx {
        ind = i
    }
}

// Print the index 'ind' plus one (since the indices in Go start from 0)
fmt.Printf("%d\n", ind+1)

