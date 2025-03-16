

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter N, A, and B:")
    text, _ := reader.ReadString('\n')
    text = strings.TrimSpace(text)
    numbers := strings.Split(text, " ")
    N, _ := strconv.ParseInt(numbers[0], 10, 64)
    A, _ := strconv.ParseInt(numbers[1], 10, 64)
    B, _ := strconv.ParseInt(numbers[2], 10, 64)
    k := int64(0)

    // Check if the values of N, A, and B are within the specified ranges
    if 1 <= N && N <= int64(math.Pow(10, 18)) && 0 <= A && 0 <= B && 0 < A+B && A+B <= int64(math.Pow(10, 18)) {

        // Calculate the number of complete cycles (k) of A and B that fit into N
        if A+B <= N {
            k = N / (A + B)
            if N-k*(A+B) > A {
                fmt.Println(A*k + (N-k*(A+B)))
            } else {
                fmt.Println(A*k + (N-k*(A+B)))
            }
        }
        // If the sum of A and B is greater than N and A is less than or equal to N
        else if A+B > N && A <= N {
            fmt.Println(A)
        }
        // If none of the above conditions are met, print N
        else {
            fmt.Println(N)
        }
    }
    // 