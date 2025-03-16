// Take an integer 'n' as input
var n int
fmt.Scanf("%d", &n)

// Create a list 'lst' of 'n' integers taken as input
var lst []int
for i := 0; i < n; i++ {
    var x int
    fmt.Scanf("%d", &x)
    lst = append(lst, x)
}

// Sort the list 'lst' in ascending order
sort.Ints(lst)

// Reverse the sorted list 'lst'
for i := 0; i < len(lst)/2; i++ {
    lst[i], lst[len(lst)-i-1] = lst[len(lst)-i-1], lst[i]
}

// Initialize odd_digits counter 'od' to 0
var od int

// Iterate through each integer 'i' in the list 'lst'
for _, i := range lst {
    // If the integer 'i' has an odd number of bits (1 in binary representation), increment 'od' counter
    if i&1 == 1 {
        od++
    }
}

// Initialize sum and ok variables
var sum, ok int

// Iterate through each index 'i' in the range of 'n'
for i := 0; i < n; i++ {
    // If the integer at index 'i' in the list 'lst' is even, add it to the sum'sum'
    if lst[i]&1 == 0 {
        sum += lst[i]
    }
    // If the integer at index 'i' in the list 'lst' is odd and either 'ok' is True or 'od' is greater than 1, add it to the sum'sum' and toggle 'ok'
    if lst[i]&1 == 1 && (ok || od > 1) {
        sum += lst[i]
        od--
        ok =!ok
    }
}

// Print the final sum
fmt.Println(sum)

