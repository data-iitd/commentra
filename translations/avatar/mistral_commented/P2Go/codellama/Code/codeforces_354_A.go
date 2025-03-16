#######
# Code
#######

// Define input variables
var n, L, R, QL, QR int
// Read input as a list of integers
var W []int

// Initialize empty list to store sum of elements
var sum_el []int

// Calculate sum of elements from 1 to n
for i := 1; i <= n; i++ {
    // Add current element and previous sum to get sum of current element
    sum_el = append(sum_el, W[i-1] + sum_el[i-1])
}

// Calculate answer
answer := QR * (n - 1) + sum_el[n] * R

// Iterate through all elements to find minimum energy
for i := 1; i <= n; i++ {
    // Calculate energy for current index
    energy := L * sum_el[i] + R * (sum_el[n] - sum_el[i])
    
    // Check if current index is greater than its mirror index
    if i > (n - i) {
        // If true, add energy of segments between current index and its mirror index
        energy += (i - (n - i) - 1) * QL

    // Check if mirror index is greater than current index
    } else if (n - i) > i {
        // If true, add energy of segments between mirror index and current index
        energy += ( (n - i) - i - 1) * QR
    }

    // Update answer if current energy is less than previous answer
    if energy < answer {
        answer = energy
    }
}

// Print the answer
fmt.Println(answer)


