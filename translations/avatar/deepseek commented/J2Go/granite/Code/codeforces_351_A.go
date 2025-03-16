

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
    strs := strings.Split(readLine(reader), " ")

    // Step 2: Processing Input
    arr := make([]float64, 2*n)
    nonInt := int32(0)
    sumBefore := float64(0)
    sum := float64(0)

    for i := 0; i < 2*n; i++ {
        numTemp, err := strconv.ParseFloat(strs[i], 64)
        checkError(err)
        num := numTemp
        sumBefore += num
        if num!= float64(int(num)) {
            nonInt++
        }
        sum += float64(int(num))
        arr[i] = num
    }

    // Step 3: Calculating Results
    maxSum := float64(int(n)) + sum
    minSum := float64(int(math.Max(float64(0), float64(nonInt-n)))) + sum
    var ans float64

    if minSum > sumBefore {
        ans = minSum - sumBefore
    } else if maxSum < sumBefore {
        ans = sumBefore - maxSum
    } else {
        x := sumBefore - math.Floor(sumBefore)
        ans = math.Min(1-x, x)
    }

    // Step 4: Output
    fmt.Printf("%.3f", ans)

    // 