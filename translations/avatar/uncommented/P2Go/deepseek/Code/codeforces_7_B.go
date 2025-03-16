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
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	t, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])
	alocuente := make([]int, m)
	ind := 1

	for i := 0; i < t; i++ {
		input, _ := reader.ReadString('\n')
		op := strings.Split(strings.TrimSpace(input), " ")
		if op[0] == "alloc" {
			pos := 0
			for j := 0; j < m; j++ {
				if alocuente[j] == 0 {
					pos++
					if pos == int(op[1]) {
						for k := 0; k < int(op[1]); k++ {
							alocuente[j-int(op[1])+1+k] = ind
						}
						fmt.Println(ind)
						ind++
						break
					}
				} else {
					pos = 0
				}
			}
			if pos != int(op[1]) {
				fmt.Println("NULL")
			}
		} else if op[0] == "erase" {
			pos, _ := strconv.Atoi(op[1])
			if pos == 0 || !contains(alocuente, pos) {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
			} else {
				for j := 0; j < m; j++ {
					if alocuente[j] == pos {
						alocuente[j] = 0
					}
				}
			}
		} else if op[0] == "defragment" {
			nonZero := []int{}
			for j := 0; j < m; j++ {
				if alocuente[j] != 0 {
					nonZero = append(nonZero, alocuente[j])
				}
			}
			copy(alocuente, nonZero)
			for j := len(nonZero); j < m; j++ {
				alocuente[j] = 0
			}
		}
	}
}

func contains(arr []int, val int) bool {
	for _, v := range arr {
		if v == val {
			return true
		}
	}
	return false
}
