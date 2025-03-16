// Take an integer 'n' as input
n := 0
fmt.Scan(&n)

// Create a list 'lst' of 'n' integers taken as input
lst := make([]int, n)
for i := 0; i < n; i++ {
    fmt.Scan(&lst[i])
}

// Sort the list 'lst' in ascending order
sort.Ints(lst)

// Reverse the sorted list 'lst'
for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
    lst[i], lst[j] = lst[j], lst[i]
}

// Initialize odd_digits counter 'od' to 0
od := 0

// Iterate through each integer 'i' in the list 'lst'
for _, i := range lst {
    // If the integer 'i' has an odd number of bits (1 in binary representation), increment 'od' counter
    if i&1 == 1 {
        od++
    }
}

// Initialize sum and ok variables
sum := 0
ok := false

// Iterate through each index 'i' in the range of 'n'
for i := 0; i < n; i++ {
    // If the integer at index 'i' in the list 'lst' is even, add it to the sum 'sum'
    if lst[i]%2 == 0 {
        sum += lst[i]
    }
    // If the integer at index 'i' in the list 'lst' is odd and either 'ok' is True or 'od' is greater than 1, add it to the sum 'sum' and toggle 'ok'
    else {
        if ok || od > 1 {
            sum += lst[i]
            od--
            ok = !ok
        }
    }
}

// Print the final sum
fmt.Println(sum)

