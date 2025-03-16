// Initialize an empty list to store valid numbers
l := []int{}
// Set a limit for the generated numbers
limit := 10000000000

// Recursive function to generate numbers composed of 4s and 7s
func gen(number, four, seven int) {
    // Base case: if the generated number exceeds the limit, stop recursion
    if (number > limit) {
        return
    }
    // If the number is positive and the count of 4s equals the count of 7s, add it to the list
    if (number > 0 && four == seven) {
        l = append(l, number)
    }
    // Recursively generate the next number by adding a 4
    gen(number * 10 + 4, four + 1, seven)
    // Recursively generate the next number by adding a 7
    gen(number * 10 + 7, four, seven + 1)
}

// Main function to execute the number generation and find the answer
func main() {
    // Start the generation process with initial values
    gen(0, 0, 0)
    // Sort the list of generated numbers
    sort.Ints(l)
    // Read an integer input from the user
    n := int(input())
    ans := 0
    // Iterate through the sorted list to find the smallest number greater than or equal to n
    for _, val := range l {
        if (val >= n) {
            ans = val
            break
        }
    }
    // Print the result
    fmt.Println(ans)
}

// Call the main function to run the program
func main() {

}

