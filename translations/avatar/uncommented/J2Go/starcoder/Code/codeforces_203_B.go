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
	fmt.Println("Enter the size of the board")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	boardSize := strings.Split(input, " ")
	boardSize[0], _ = strconv.Atoi(boardSize[0])
	boardSize[1], _ = strconv.Atoi(boardSize[1])
	fmt.Println("Enter the number of black tiles")
	input, _ = reader.ReadString('\n')
	input = strings.TrimSpace(input)
	blackTiles := strings.Split(input, " ")
	blackTiles[0], _ = strconv.Atoi(blackTiles[0])
	blackTiles[1], _ = strconv.Atoi(blackTiles[1])
	black := make([][]int, boardSize[0]+2)
	for i := range black {
		black[i] = make([]int, boardSize[0]+2)
	}
	for i := 0; i < blackTiles[0]; i++ {
		fmt.Println("Enter the coordinates of the black tile")
		input, _ = reader.ReadString('\n')
		input = strings.TrimSpace(input)
		coordinates := strings.Split(input, " ")
		coordinates[0], _ = strconv.Atoi(coordinates[0])
		coordinates[1], _ = strconv.Atoi(coordinates[1])
		black[coordinates[0]+1][coordinates[1]+1] = 9
	}
	for i := 1; i <= boardSize[0]; i++ {
		for j := 1; j <= boardSize[0]; j++ {
			black[i][j] = black[i-1][j] + black[i+1][j] + black[i][j-1] + black[i][j+1] + black[i][j]
		}
	}
	for i := 1; i <= boardSize[0]; i++ {
		for j := 1; j <= boardSize[0]; j++ {
			if black[i][j] == 9 {
				fmt.Println(blackTiles[1])
				return
			}
		}
	}
	fmt.Println("-1")
}

