package main
 
import (
    "fmt"
    "os"
    "bufio"
    "strings"
    "strconv"
)
 
func main() {
    reader := bufio.NewReader(os.Stdin)
    var input string
    fmt.Print("Enter the numbers separated by space: ")
    input, _ = reader.ReadString('\n')
    input = strings.Replace(input, "\n", "", -1)
    input = strings.Replace(input, "\r", "", -1)
    input = strings.Replace(input, " ", "", -1)
    var numbers []int
    for _, value := range input {
        num, _ := strconv.Atoi(string(value))
        numbers = append(numbers, num)
    }
    sort(numbers)
    fmt.Println(numbers)
}
 
func sort(numbers []int) {
    for i := 0; i < len(numbers); i++ {
        if i!= 0 {
            j := i - 1
            for j >= 0 && numbers[j] > numbers[i] {
                numbers[j+1] = numbers[j]
                j--
            }
            numbers[j+1] = numbers[i]
        }
        fmt.Println(numbers)
    }
}

