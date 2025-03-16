
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Define the number of items in the input array
    n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[2:])

    // Initialize an empty list to store the input data
    input_array := make([][]int, n)

    // Read n items from the standard input and append them to the input_array
    for i := 0; i < n; i++ {
        line := bufio.NewReader(os.Stdin).ReadLine()
        data := strings.Split(string(line), " ")
        S, _ := strconv.Atoi(data[0])
        R, _ := strconv.Atoi(data[1])
        H, _ := strconv.Atoi(data[2])
        C, _ := strconv.Atoi(data[3])
        input_array[i] = []int{S, R, H, C}
    }

    // Initialize an empty list to store the outdated items
    outdated := make([][]int, 0)

    // Check for outdated items in the input array
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            // Check if the current item is older and smaller than the next one
            if input_array[i][0] < input_array[j][0] &&
                input_array[i][1] < input_array[j][1] &&
                input_array[i][2] < input_array[j][2] {
                // Append the current item to the outdated list
                outdated = append(outdated, input_array[i])
            }
        }
    }

    // Convert the outdated list to a set to remove duplicates
    outdated_set := make(map[string]bool)
    for _, item := range outdated {
        outdated_set[fmt.Sprintf("%v", item)] = true
    }

    // Initialize minimum_cost and input_number to large initial values
    minimum_cost := 100000
    input_number := 0

    // Find the item with the minimum cost that is not outdated
    for i := 0; i < n; i++ {
        current_item := input_array[i]
        cost := current_item[3]
        // Check if the current item is not outdated and has a smaller cost than minimum_cost
        if!outdated_set[fmt.Sprintf("%v", current_item)] && cost < minimum_cost {
            // Update minimum_cost and input_number
            minimum_cost = current_item[3]
            input_number = i + 1
        }
    }

    // Print the index of the item with the minimum cost that is not outdated
    fmt.Println(input_number)
}
