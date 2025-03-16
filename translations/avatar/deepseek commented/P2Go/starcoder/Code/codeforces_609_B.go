
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    fmt.Println("Enter the number of elements in the list")
    n, err := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    checkError(err)

    fmt.Println("Enter the number of elements in the set")
    m, err := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    checkError(err)

    fmt.Println("Enter the elements of the list")
    list := readLine(reader)
    list = strings.Split(list, " ")
    list = strToInt(list)

    fmt.Println("Enter the elements of the set")
    set := readLine(reader)
    set = strings.Split(set, " ")
    set = strToInt(set)

    result := 0
    for i := 0; i < n; i++ {
        if list[i] == set[0] {
            count := 0
            for j := 0; j < n; j++ {
                if list[j] == set[0] {
                    count++
                }
            }
            result += count * (count - 1) / 2
        }
    }

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

func strToInt(input []string) []int {
    output := make([]int, len(input))

    for i := 0; i < len(input); i++ {
        output[i], _ = strconv.Atoi(input[i])
    }

    return output
}

