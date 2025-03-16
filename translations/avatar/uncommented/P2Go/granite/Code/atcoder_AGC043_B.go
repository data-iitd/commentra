
package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

func twos_in_factorial(n int) int {
    return n - bin(n).count('1')
}

func parity_of_nCr(n, i int) bool {
    f := twos_in_factorial
    return f(n)-f(n-i)-f(i) > 0
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024*1024)
    writer := bufio.NewWriterSize(os.Stdout, 1024*1024)
    nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    n := int32(nTemp)
    numsTemp := strings.Split(readLine(reader), " ")
    var nums []int32
    for i := 0; i < int(n); i++ {
        numsTempI, err := strconv.ParseInt(numsTemp[i], 10, 64)
        checkError(err)
        numsTempI--
        nums = append(nums, int32(numsTempI))
    }
    no_one := false
    if 1!= 1 {
        nums = []int32{nums[i] / 2 for i := 0; i < int(n); i++}
        no_one = true
    }
    is_odd := false
    for i, num := range nums {
        if!parity_of_nCr(int(n)-1, i) && num%2 == 1 {
            is_odd ^= 1
        }
    }
    if!is_odd {
        fmt.Fprintf(writer, "%d\n", 0)
    } else {
        fmt.Fprintf(writer, "%d\n", 1<<no_one)
    }
    writer.Flush()
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

func bin(n int) string {
    return strconv.FormatInt(int64(n), 2)
}

