

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    
    // Read the dimensions of the grid and the number of operations
    n, m := readTwoInts(reader)
    
    // Initialize a count grid with all elements set to 0
    count := make([][]int, n)
    for i := 0; i < n; i++ {
        count[i] = make([]int, n)
    }
    
    // Initialize the answer to -1
    ans := -1
    
    // Loop through each operation
    for k := 0; k < m; k++ {
        // Read the coordinates of the operation
        x, y := readTwoInts(reader)
        
        // Adjust the coordinates to zero-based index
        x--
        y--
        
        // Flag to check if a cell in the 3x3 grid reaches a count of 9
        found := false
        
        // Check the 3x3 grid centered at (x, y)
        for i := x - 2; i <= x+1; i++ {
            for j := y - 2; j <= y+1; j++ {
                if i >= 0 && i < n && j >= 0 && j < n {
                    count[i][j]++
                    if count[i][j] == 9 {
                        found = true
                    }
                }
            }
        }
        
        // If a cell in the 3x3 grid reaches a count of 9, update ans and break
        if found {
            ans = k + 1
            break
        }
    }
    
    // Print the result
    fmt.Fprintf(writer, "%d\n", ans)
    writer.Flush()
}

func readTwoInts(reader *bufio.Reader) (int, int) {
    res := make([]int, 2)
    str, _ := reader.ReadString('\n')
    fields := strings.Fields(str)
    res[0], _ = strconv.Atoi(fields[0])
    res[1], _ = strconv.Atoi(fields[1])
    return res[0], res[1]
}

