
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

    // Step 1: Reading Input
    nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    n := int32(nTemp)
    aTemp := strings.Split(readLine(reader), " ")
    var a []int32
    for i := 0; i < int(n); i++ {
        aItemTemp, err := strconv.ParseInt(aTemp[i], 10, 64)
        checkError(err)
        aItem := int32(aItemTemp)
        a = append(a, aItem)
    }

    // Step 2: Reading a String
    s := readLine(reader)

    // Step 3: Initial Sum Calculation
    sum := int64(0)

    // Step 4: First Loop
    for i := 0; i < len(s); i++ {
        char := string(s[i])
        if char == "B" {
            sum += int64(a[i])
        }
    }

    // Step 5: Main Logic
    ans := sum
    sum1 := sum

    // First nested loop to calculate the maximum possible sum by flipping characters in s
    for i := 0; i < len(s); i++ {
        char := string(s[i])
        if char == "A" {
            sum1 += int64(a[i])
        } else {
            sum1 -= int64(a[i])
        }
        if sum1 > ans {
            ans = sum1
        }
    }

    // Second nested loop to calculate the maximum possible sum by flipping characters in s from right to left
    sum1 = sum
    for i := len(s) - 1; i >= 0; i-- {
        char := string(s[i])
        if char == "A" {
            sum1 += int64(a[i])
        } else {
            sum1 -= int64(a[i])
        }
        if sum1 > ans {
            ans = sum1
        }
    }

    // Step 6: Output
    fmt.Println(ans)

    // 