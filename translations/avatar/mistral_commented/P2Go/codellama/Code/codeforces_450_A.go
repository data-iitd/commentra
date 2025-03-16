#######
# Code
#######

// Define the number of elements 'n' and the modulus 'm' in the list 'l'
n, m := 0, 0
fmt.Scan(&n, &m)

// Initialize an empty list 'l2' to store the quotient of each element in 'l' divided by 'm'
l2 := make([]int, 0)

// Iterate through each element 'i' in the list 'l'
for i := 0; i < n; i++ {
    // Check if the element 'i' is divisible by 'm'. If yes, append the quotient (integer division) to 'l2'. If not, append the quotient plus one.
    if l[i]%m == 0 {
        l2 = append(l2, l[i]/m)
    } else {
        l2 = append(l2, int(l[i]/m+1))
    }
}

// Find the maximum quotient in 'l2'
mx := 0
for i := 0; i < len(l2); i++ {
    if l2[i] > mx {
        mx = l2[i]
    }
}

// Iterate through each index 'i' from 0 to 'n-1' in the list 'l2'
for i := 0; i < n; i++ {
    // Check if the quotient at index 'i' in 'l2' is equal to the maximum quotient 'mx'. If yes, store the index 'i' in the variable 'ind'.
    if l2[i] == mx {
        ind = i
    }
}

// Print the index 'ind' plus one (since the indices in Go start from 0)
fmt.Println(ind + 1)


