package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

const MAXN = 1e5 + 10

func main() {
    // Read the number of elements (n) and the maximum value (m)
    n, m := readi2()
    // Read the number of queries (Q)
    Q := readi()

    // Read the queries into array a
    a := make([]int, Q + 1)
    for i := 1; i <= Q; i++ {
        a[i] = readi()
    }

    // Process the queries to fill array b with unique values from a
    b := make([]int, 0, m + 1)
    for j := Q; j > 0; j-- {
        if!contains(b, a[j]) { // If the value has not been seen yet
            b = append(b, a[j]) // Add it to b
        }
    }

    // Fill the remaining positions in b with the largest unused values up to m
    for j := m; j > 0; j-- {
        if!contains(b, j) { // If the value j has not been seen
            b = append(b, j) // Add it to b
        }
    }

    // Map each value in b to its index in id
    id := make([]int, m + 1)
    for i := 1; i <= m; i++ {
        id[b[i]] = i
    }

    flag := true
    cnt := make([]int, m + 1)
    cnt[0] = n

    // Process the queries in reverse order
    for i := Q; i > 0; i-- {
        t := id[a[i]] // Get the index of the current query value
        if cnt[t - 1] > 0 { // If there are available counts for the previous index
            cnt[t - 1]-- // Decrease the count for the previous index
            cnt[t]++ // Increase the count for the current index
        } else if!contains(b, t) { // If the current index has not been seen
            flag = false
            break
        }
    }

    // Find the first index l where count is non-zero
    l := 0
    for l = 0; cnt[l] == 0; l++ {
    }

    // Check if the remaining values in b are in increasing order
    for i := l + 1; i < m; i++ {
        flag = flag && b[i] < b[i + 1]
    }

    // Output the result based on the flag
    fmt.Println(bool2str(flag))
}

func readi() int {
    s, _ := bufio.NewReader(os.Stdin).ReadString('\n')
    i, _ := strconv.Atoi(strings.TrimSpace(s))
    return i
}

func readi2() (int, int) {
    s, _ := bufio.NewReader(os.Stdin).ReadString('\n')
    i, _ := strconv.Atoi(strings.TrimSpace(s))
    s, _ = bufio.NewReader(os.Stdin).ReadString('\n')
    j, _ := strconv.Atoi(strings.TrimSpace(s))
    return i, j
}

func bool2str(b bool) string {
    if b {
        return "Yes"
    }
    return "No"
}

func contains(a []int, x int) bool {
    for _, n := range a {
        if x == n {
            return true
        }
    }
    return false
}

