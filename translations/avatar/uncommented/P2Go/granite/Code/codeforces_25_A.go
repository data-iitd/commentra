
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
    fmt.Println("Enter the number of elements:")
    n, _ := strconv.Atoi(reader.ReadLine())
    fmt.Println("Enter the elements:")
    line, _ := reader.ReadString('\n')
    elements := strings.Split(line, " ")
    var count int
    for _, element := range elements {
        if (strconv.Itoa(int(element[0])%2)) == "1" {
            count++
        }
    }
    if count == 1 {
        for i, element := range elements {
            if (strconv.Itoa(int(element[0])%2)) == "1" {
                fmt.Println(i + 1)
                break
            }
        }
    } else {
        for i, element := range elements {
            if (strconv.Itoa(int(element[0])%2)) == "0" {
                fmt.Println(i + 1)
                break
            }
        }
    }
}
