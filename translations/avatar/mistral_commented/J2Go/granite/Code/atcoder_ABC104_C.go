
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

const (
    // Declaring a constant integer variable named INF
    INF = 100000
)

func main() {
    // Creating a Scanner object to read input from the standard input
    sc := bufio.NewScanner(os.Stdin)

    // Reading the number of test cases D from the standard input
    sc.Scan()
    D, _ := strconv.Atoi(sc.Text())

    // Reading the goal score G from the standard input
    sc.Scan()
    G, _ := strconv.ParseInt(sc.Text(), 10, 64)

    // Declaring and initializing two integer arrays p and c of size D
    p := make([]int, D)
    c := make([]int, D)

    // Reading the values of p[i] and c[i] for each test case i from the standard input
    for i := 0; i < D; i++ {
        sc.Scan()
        p[i], _ = strconv.Atoi(sc.Text())
        sc.Scan()
        c[i], _ = strconv.Atoi(sc.Text())
    }

    // Initializing a variable min to a large value
    min := INF

    // Looping through all possible combinations of bits using a binary number
    for bit := 0; bit < (1 << D); bit++ {
        // Initializing variables score and solve_num to zero
        score := 0
        solve_num := 0

        // Looping through each test case i
        for i := 0; i < D; i++ {
            // Checking if the current bit is set in the binary number
            if (bit & (1 << i))!= 0 {
                // Adding the score for the current test case i to the total score
                score += 100*(i+1)*p[i] + c[i]
                // Incrementing the number of test cases solved so far
                solve_num += p[i]
            }
        }

        // Checking if the current combination of bits can form a valid solution
        if score < G {
            // Backtracking to find the minimum number of test cases to be solved
            for i := D - 1; i >= 0; i-- {
                // If the current bit is not set in the binary number
                if (bit & (1 << i)) == 0 {
                    // Looping through each test case j that can be added to the current solution
                    for j := 0; j < p[i]-1; j++ {
                        // Adding the score for the current test case i and the current test case j to the total score
                        score += 100 * (i + 1)
                        // Incrementing the number of test cases solved so far
                        solve_num++
                        // Checking if the current combination of bits can form a valid solution
                        if score >= G {
                            // Breaking out of the inner loop as we have found a valid solution
                            break
                        }
                    }
                }
                // If we have found a valid solution, we can break out of the outer loop as well
                if score >= G {
                    break
                }
            }
        }

        // Updating the minimum number of test cases if the current combination of bits can form a valid solution with a smaller number of test cases
        if score >= G {
            min = int(math.Min(float64(min), float64(solve_num)))
        }
    }

    // Printing the minimum number of test cases required to form a valid solution
    fmt.Println(min)
}

// 