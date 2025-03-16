// Function to find the number of digits in a given number
func main() {
    // Read the number of test cases from the standard input
    N := int(input())

    // Initialize variables
    i := 1
    ans := 0

    // Calculate the answer using a while loop
    for {
        if 10 ** i > N {
            break
        }
        ans += (10 ** i - 10 ** (i - 1))
        i += 2
    }

    // Add the remaining digits of the number N to the answer
    ans += max(0, N - 10 ** (i - 1) + 1)

    // Print the answer
    fmt.Println(ans)
}

