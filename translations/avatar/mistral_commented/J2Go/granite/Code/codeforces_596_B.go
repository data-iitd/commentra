
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Create a new Scanner object to read input from the standard input stream
    scan := bufio.NewScanner(os.Stdin)

    // Read the first integer `n` from the standard input stream and assign it to the variable `n`
    scan.Scan()
    n, _ := strconv.Atoi(scan.Text())

    // Create a new long array `arr` of size `n`
    arr := make([]int, n)

    // Use a for loop to read `n` integers from the standard input stream and assign them to the corresponding elements of the array `arr`
    for i := 0; i < n; i++ {
        scan.Scan()
        arr[i], _ = strconv.Atoi(scan.Text())
    }

    // Initialize the variable `answer` with the absolute value of the first element of the array `arr`
    answer := int(math.Abs(float64(arr[0])))

    // Use a for loop to iterate over the remaining elements of the array `arr` and calculate the absolute difference between each element and the previous one, adding the result to the variable `answer`
    for i := 1; i < n; i++ {
        answer += int(math.Abs(float64(arr[i] - arr[i-1])))
    }

    // Print the value of the variable `answer` to the standard output stream
    fmt.Println(answer)
}

