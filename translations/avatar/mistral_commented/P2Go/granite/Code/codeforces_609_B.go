
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read number of elements 'n' and size'm' of the list 'lst'
    reader := bufio.NewReader(os.Stdin)
    nStr, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(nStr))
    mStr, _ := reader.ReadString('\n')
    m, _ := strconv.Atoi(strings.TrimSpace(mStr))

    // Initialize an empty dictionary 'l' to store the frequency of each element
    lst := make([]int, n)
    l := make(map[int]int)

    // Iterate through each element in the list 'lst'
    for i := 0; i < n; i++ {
        lstStr, _ := reader.ReadString('\n')
        lst[i], _ = strconv.Atoi(strings.TrimSpace(lstStr))

        // If the current element is not already present in the dictionary 'l'
        if _, ok := l[lst[i]];!ok {
            // Add the current element to the dictionary 'l' with a frequency of 1
            l[lst[i]] = 1
        } else {
            // Increment the frequency of the current element in the dictionary 'l'
            l[lst[i]] += 1
        }
    }

    // Initialize result variable'res' to 0
    res := 0

    // Iterate through each element in the list 'lst'
    for i := 0; i < n; i++ {
        // If the frequency of the current element in the dictionary 'l' is greater than 1
        if l[lst[i]] > 1 {
            // Calculate the number of elements that have a smaller frequency than the current element
            // and add it to the result variable'res'
            res += n - i - l[lst[i]]
            // Decrease the frequency of the current element in the dictionary 'l' by 1
            l[lst[i]] -= 1
        } else {
            // Calculate the number of elements that have not been processed yet and add it to the result variable'res'
            res += n - i - 1
        }
    }

    // Print the final result
    fmt.Println(res)
}
