
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

<<<<<<< HEAD
// Main function starts here
func main() {

    var N, M int
    var L []int

    // Read input from user
    fmt.Scanf("%d %d\n", &N, &M)

    // Initialize a vector of integers with size N
    L = make([]int, N)

    // Read integers from user and store them in the vector
    for i := 0; i < N; i++ {
        fmt.Scanf("%d\n", &L[i])
    }

    // Sort the vector in ascending order
    sort.Ints(L)

    // Iterator to traverse the vector
    var itr int
=======
// Function to read input from stdin
func readInput(reader *bufio.Reader) (int, int) {
    // Read input from stdin
    str, _ := reader.ReadString('\n')
    str = strings.TrimSpace(str)
    strs := strings.Split(str, " ")
    N, _ := strconv.Atoi(strs[0])
    M, _ := strconv.Atoi(strs[1])
    return N, M
}

// Function to sort the input in ascending order
func sortInput(L []int) {
    sort.Ints(L)
}

// Function to perform the required operations for M times
func performOperations(L []int, M int) {
    // Iterator to traverse the vector
    itr := 0
>>>>>>> 98c87cb78a (data updated)

    // Perform the required operations for M times
    for i := 0; i < M; i++ {
        max_L := L[len(L)-1] // Get the last element of the vector

        // If the last element is 0, break the loop
        if max_L == 0 {
            break
        }

        // Divide the last element by 2
        max_L /= 2

        // Find the position of the element greater than or equal to max_L using lower_bound
        itr = sort.Search(len(L), func(i int) bool { return L[i] >= max_L })

        // Insert max_L before the found position and remove the last element
        L = append(L[:itr], append([]int{max_L}, L[itr:]...)...)
        L = L[:len(L)-1]
    }
<<<<<<< HEAD

    // Calculate the answer and print it
    ans := int64(0)
    for _, v := range L {
        ans += int64(v)
    }
    fmt.Printf("%d\n", ans)

=======
}

// Function to calculate the answer and print it
func calculateAnswer(L []int) {
    ans := 0
    for _, v := range L {
        ans += v
    }
    fmt.Println(ans)
}

// Main function starts here
func main() {
    reader := bufio.NewReader(os.Stdin)
    N, M := readInput(reader)
    L := make([]int, N)
    for i := 0; i < N; i++ {
        str, _ := reader.ReadString('\n')
        str = strings.TrimSpace(str)
        L[i], _ = strconv.Atoi(str)
    }
    sortInput(L)
    performOperations(L, M)
    calculateAnswer(L)
>>>>>>> 98c87cb78a (data updated)
}

