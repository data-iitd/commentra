// Define input variables's' and 'l'
s, l := (input()), 2019

// Initialize list'm' with initial value 1 for index 0 and zeros for other indices
m := []int{1}
for i := 1; i < l; i++ {
    m = append(m, 0)
}

// Initialize variables 'a' and 'r' with zero values
a, r := 0, 0

// Iterate through the string's' in reverse order
for i, e := range s[::-1] {
    // Calculate the current digit's power and add it to 'a'
    a += int(e) * int(math.Pow(10, float64(i)))

    // Increment the index 'a % l' in list'm'
    m[a % l] += 1

    // Update 'r' with the current sum
    r += m[a % l]
}

// Print the final result 'r'
fmt.Println(r)

