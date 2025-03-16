

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Step 1: Read the input value `n` which represents the number of elements.
    reader := bufio.NewReader(os.Stdin)
    nStr, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(nStr))

    // Step 2: Read the values of `v` (values) and store them in a list `vList`.
    vStr, _ := reader.ReadString('\n')
    vList := str2List(vStr)

    // Step 3: Read the values of `c` (costs) and store them in a list `cList`.
    cStr, _ := reader.ReadString('\n')
    cList := str2List(cStr)

    // Step 4: Initialize a variable `max` to keep track of the maximum profit.
    max := 0

    // Step 5: Iterate through the elements, calculate the profit for each element, and update `max` if the profit is positive.
    for i := 0; i < n; i++ {
        profit := vList[i] - cList[i]
        if profit > 0 {
            max += profit
        }
    }

    // Step 6: Print the maximum profit.
    fmt.Println(max)
}

// Helper method to convert a string of space-separated integers into a map with index as key and integer value as value.
func str2List(str string) map[int]int {
    vArrStr := strings.Split(str, " ")
    ret := make(map[int]int)
    for i, val := range vArrStr {
        v, _ := strconv.Atoi(val)
        ret[i] = v
    }
    return ret
}

