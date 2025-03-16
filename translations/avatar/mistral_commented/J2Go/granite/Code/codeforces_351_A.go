

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
    var n int
    fmt.Fscanf(reader, "%d\n", &n)
    var non_int int
    var sum_before, sum float64
    var arr [2 * n]float64
    str := readLine(reader)
    tokens := strings.Split(str, " ")
    for i := 0; i < 2*n; i++ {
        num, _ := strconv.ParseFloat(tokens[i], 64)
        sum_before += num
        if num!= float64(int(num)) {
            non_int++
        }
        sum += float64(int(num))
        arr[i] = num
    }
    max_sum := float64(int(n)) + sum
    min_sum := float64(int(math.Max(0, float64(non_int-n)))) + sum
    var ans float64
    if min_sum > sum_before {
        ans = min_sum - sum_before
    } else if max_sum < sum_before {
        ans = sum_before - max_sum
    } else {
        x := sum_before - float64(int(sum_before))
        ans = math.Min(1-x, x)
    }
    fmt.Printf("%.3f\n", ans)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), " \r\n")
    }
    return ""
}

These comments should provide a clear understanding of the logical blocks in the given Go code.