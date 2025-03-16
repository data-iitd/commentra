
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Creating a BufferedReader object to read input from the standard input stream
    br := bufio.NewReader(os.Stdin)
    // Creating a StringBuilder object to store the output string
    sb := strings.Builder{}

    // Reading the number of test cases
    n, _ := strconv.Atoi(br.ReadString('\n'))

    // Reading the elements of the array
    st := strings.Split(br.ReadString('\n'), " ")
    arr := make([]float64, 2*n)
    non_int := 0 // Initializing variables
    sum_before := 0.0
    sum := 0.0

    // Iterating through the array elements and performing the required operations
    for i := 0; i < 2*n; i++ {
        num, _ := strconv.ParseFloat(st[i], 64)
        sum_before += num
        if num != float64(int(num)) {
            non_int++
        }
        sum += float64(int(num))
        arr[i] = num
    }

    // Calculating the maximum and minimum sums
    max_sum := math.Min(float64(n), float64(non_int)) + sum
    min_sum := math.Max(0, float64(non_int-n)) + sum

    // Calculating the answer based on the given conditions
    var ans float64
    if min_sum > sum_before {
        ans = min_sum - sum_before
    } else if max_sum < sum_before {
        ans = sum_before - max_sum
    } else {
        x := sum_before - math.Floor(sum_before)
        ans = math.Min(1-x, x)
    }

    // Printing the answer
    fmt.Printf("%.3f", ans)
}

