

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

    // Read the number of rows and columns from the input
    H, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    W, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    // Initialize a 2D char array 'A' to store the input grid
    A := make([][]byte, H)
    for i := 0; i < H; i++ {
        A[i] = readLine(reader)
    }

    // Initialize a Queue to store the cells to be processed
    queue := make([][]int, 0)

    // Read the grid and initialize the queue with the starting points of 'B'
    for i := 0; i < H; i++ {
        for j := 0; j < W; j++ {
            if A[i][j] == '#' {
                queue = append(queue, []int{i, j, 0})
            }
        }
    }

    // Initialize a 2D int array 'flag' to mark the visited cells
    flag := make([][]int, H)
    for i := 0; i < H; i++ {
        flag[i] = make([]int, W)
    }

    // Initialize variables for the answer and the directions
    ans := 0
    dx := []int{1, -1, 0, 0}
    dy := []int{0, 0, 1, -1}

    // Process the queue and find the answer
    for len(queue) > 0 {
        temp := queue[0]
        queue = queue[1:]
        y := temp[0]
        x := temp[1]
        depth := temp[2]

        // Process the neighboring cells
        for i := 0; i < 4; i++ {
            newY := y + dy[i]
            newX := x + dx[i]

            // If the cell is within the grid and hasn't been visited yet,
            // and contains a '.', mark it as visited and add it to the queue
            if 0 <= newY && newY < H && 0 <= newX && newX < W {
                if flag[newY][newX] == 0 && A[newY][newX] == '.' {
                    flag[newY][newX] = 1
                    queue = append(queue, []int{newY, newX, depth + 1})
                    ans = max(ans, depth+1)
                }
            }
        }
    }

    // Print the answer
    fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

These comments should provide a clear understanding of the code's logic and purpose. Let me know if you need any further clarification.