
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    var pya int
    fmt.Scan(&pya)
    var arre []string
    for pya > 0 {
        pya--
        var temp string
        fmt.Scan(&temp)
        arre = append(arre, strings.ToLower(temp))
    }
    var oString string
    fmt.Scan(&oString)
    lowString := strings.ToLower(oString)
    var letter1 string
    fmt.Scan(&letter1)
    letter2 := "a"
    if letter1 == "a" {
        letter2 = "b"
    }
    valid := make([]int, len(oString))
    setcito := make(map[int]bool)
    for _, x := range arre {
        if strings.Index(lowString, x) >= 0 {
            wat := 0
            for {
                index := strings.Index(lowString, x, wat)
                if index < 0 {
                    break
                }
                for i := index; i < index+len(x); i++ {
                    setcito[i] = true
                }
                wat = index + 1
            }
        }
    }
    oString = string(oString)
    for i, _ := range setcito {
        letter := letter1
        if lowString[i]!= letter1 {
            letter = letter2
        }
        if oString[i] >= 'a' && oString[i] <= 'z' {
            oString = oString[:i] + string(letter) + oString[i+1:]
        } else {
            oString = oString[:i] + strings.ToUpper(string(letter)) + oString[i+1:]
        }
    }
    fmt.Println(oString)
}
