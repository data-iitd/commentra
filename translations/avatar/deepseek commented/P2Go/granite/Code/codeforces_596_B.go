

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    n := int32(nTemp)

    rTemp := strings.Split(readLine(reader), " ")

    var r []int32

    for i := 0; i < int(n); i++ {
        rItemTemp, err := strconv.ParseInt(rTemp[i], 10, 64)
        checkError(err)
        rItem := int32(rItemTemp)
        r = append(r, rItem)
    }

    ans := int32(math.Abs(float64(r[0])))

    for i := 1; i < int(n); i++ {
        ans += int32(math.Abs(float64(r[i] - r[i-1])))
    }

    fmt.Println(ans)
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

