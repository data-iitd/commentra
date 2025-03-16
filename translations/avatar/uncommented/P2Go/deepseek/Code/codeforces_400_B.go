package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, m int
	fmt.Scan(&n, &m)

	var grid [100][100]string
	for i := 0; i < n; i++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		for j := 0; j < m; j++ {
			grid[i][j] = string(line[j])
		}
	}

	var differences []int
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == "S" {
				for k := 0; k < n; k++ {
					for l := 0; l < m; l++ {
						if grid[k][l] == "G" {
							diff := j - l
							if diff < 0 {
								differences = append(differences, diff)
							}
							break
						}
					}
				}
			}
		}
	}

	if len(differences) > 0 {
		fmt.Println(-1)
	} else {
		fmt.Println(len(differences))
	}
}

