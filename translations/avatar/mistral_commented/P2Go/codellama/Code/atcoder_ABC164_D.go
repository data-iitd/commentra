// Define input variables 's' and 'l'
var s, l string
fmt.Scan(&s, &l)

// Initialize list 'm' with initial value 1 for index 0 and zeros for other indices
m := make([]int, l)
m[0] = 1

// Initialize variables 'a' and 'r' with zero values
var a, r int

// Iterate through the string 's' in reverse order
for i := len(s) - 1; i >= 0; i-- {
    // Calculate the current digit's power and add it to 'a'
    a += int(s[i] - '0') * int(math.Pow(10, float64(i), float64(l)))
    
    // Increment the index 'a % l' in list 'm'
    m[a % l]++

    // Update 'r' with the current sum
    r += m[a % l]
}

// Print the final result 'r'
fmt.Println(r)

