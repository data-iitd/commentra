package main
import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)
func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)
    fmt.Println("Enter the number of elements in the array")
    nTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    checkError(err)
    n := int(nTemp)
    fmt.Println("Enter the elements of the array")
    arrTemp := strings.Split(strings.TrimSpace(readLine(reader)), " ")
    var arr []int64
    for i := 0; i < int(n); i++ {
        arrItemTemp, err := strconv.ParseInt(arrTemp[i], 10, 64)
        checkError(err)
        arr = append(arr, arrItemTemp)
    }
    result := solve(n, arr)
    fmt.Println(result)
}
func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }
    return strings.TrimRight(string(str), "\r\n")
}
func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}
func solve(n int64, arr []int64) string {
    sort.Slice(arr, func(i, j int) bool { return arr[i] > arr[j] })
    flag := make([]bool, n)
    cur := make([]int64, 0)
    cur = append(cur, arr[0])
    flag[0] = false
    for i := int64(0); i < n; i++ {
        j := int64(0)
        jM := int64(len(cur))
        for k := int64(0); k < n; k++ {
            if flag[k] && arr[k] < cur[j] {
                cur = append(cur, arr[k])
                j += 1
                flag[k] = false
                if j == jM {
                    break
                }
            }
        } else {
            return "No"
        }
        sort.Slice(cur, func(i, j int) bool { return cur[i] > cur[j] })
    }
    return "Yes"
}
