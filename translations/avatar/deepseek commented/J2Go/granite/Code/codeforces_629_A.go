

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
    fmt.Print("Enter the size of the grid: ")
    num, _ := strconv.Atoi(reader.ReadLine())
    counter := 0
    fine := 0
    arr := make([]string, num)

    // Read num strings representing the grid rows
    for i := 0; i < num; i++ {
        arr[i], _ = reader.ReadLine()
    }

    // Calculate the fine for each column
    for i := 0; i < num; i++ {
        for k := 0; k < num; k++ {
            if string(arr[k][i]) == "C" {
                counter++
            }
        }
        fine += (counter * (counter - 1)) / 2
        counter = 0
    }

    // Calculate the fine for each row
    for i := 0; i < num; i++ {
        for k := 0; k < num; k++ {
            if string(arr[i][k]) == "C" {
                counter++
            }
        }
        fine += (counter * (counter - 1)) / 2
        counter = 0
    }

    // Print the total fine
    fmt.Println("Total fine:", fine)
}

