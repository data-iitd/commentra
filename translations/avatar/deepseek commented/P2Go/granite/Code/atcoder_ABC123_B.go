

package main

import (
    "bufio"
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

func main() {
    menu := make([][]int, 5)
    for i := 0; i < 5; i++ {
        reader := bufio.NewReader(os.Stdin)
        fmt.Print("Input: ")
        text, _ := reader.ReadString('\n')
        text = strings.TrimSpace(text)
        lastDigit, _ := strconv.Atoi(string(text[len(text)-1]))
        if lastDigit == 0 {
            lastDigit = 10
        }
        menu[i] = []int{lastDigit, 0}
    }
    for i := 0; i < 5; i++ {
        menu[i][1], _ = strconv.Atoi(string(menu[i][0]))
    }
    menu = twoDArraySort(menu, 1)
    ans := 0
    for i := 1; i < 5; i++ {
        ans += int(math.Ceil(float64(menu[i][1])/10)) * 10
    }
    ans += menu[0][1]
    fmt.Println("Output:", ans)
}

func twoDArraySort(twoDArray [][]int, index int) [][]int {
    for i := 0; i < len(twoDArray)-1; i++ {
        for j := 0; j < len(twoDArray)-i-1; j++ {
            if twoDArray[j][index] > twoDArray[j+1][index] {
                twoDArray[j], twoDArray[j+1] = twoDArray[j+1], twoDArray[j]
            }
        }
    }
    return twoDArray
}

