
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
    fmt.Print("Enter the number of items: ")
    n, _ := strconv.Atoi(reader.ReadLine())
    inputArray := make([][]int, n)
    for i := 0; i < n; i++ {
        fmt.Print("Enter the values for item ", i+1, " (S R H C): ")
        input := reader.ReadLine()
        values := strings.Split(string(input), " ")
        S, _ := strconv.Atoi(values[0])
        R, _ := strconv.Atoi(values[1])
        H, _ := strconv.Atoi(values[2])
        C, _ := strconv.Atoi(values[3])
        inputArray[i] = []int{S, R, H, C}
    }
    outdated := make([][]int, 0)
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if inputArray[i][0] < inputArray[j][0] && inputArray[i][1] < inputArray[j][1] && inputArray[i][2] < inputArray[j][2] {
                outdated = append(outdated, inputArray[i])
            }
        }
    }
    outdatedSet := make(map[string]bool)
    for _, item := range outdated {
        outdatedSet[fmt.Sprintf("%d %d %d", item[0], item[1], item[2])] = true
    }
    minimumCost := 100000
    inputNumber := 0
    for i := 0; i < n; i++ {
        currentItem := inputArray[i]
        cost := currentItem[3]
        if!outdatedSet[fmt.Sprintf("%d %d %d", currentItem[0], currentItem[1], currentItem[2])] && cost < minimumCost {
            minimumCost = cost
            inputNumber = i + 1
        }
    }
    fmt.Println("The input number with the minimum cost is:", inputNumber)
}
