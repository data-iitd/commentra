package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var t, m int
	fmt.Scan(&t, &m)
	alocuente := make([]int, m)
	ind := 1

	for i := 0; i < t; i++ {
		var input string
		fmt.Scan(&input)
		op := strings.Fields(input)

		if op[0] == "alloc" {
			pos := 0
			size, _ := strconv.Atoi(op[1])
			for j := 0; j < m; j++ {
				if alocuente[j] == 0 {
					pos++
					if pos == size {
						for k := j - size + 1; k <= j; k++ {
							alocuente[k] = ind
						}
						fmt.Println(ind)
						ind++
						break
					}
				} else {
					pos = 0
				}
			}
			if pos < size {
				fmt.Println("NULL")
			}
		}

		if op[0] == "erase" {
			arg, _ := strconv.Atoi(op[1])
			if arg <= 0 || !contains(alocuente, arg) {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
			} else {
				for j := 0; j < m; j++ {
					if alocuente[j] == arg {
						alocuente[j] = 0
					}
				}
			}
		}

		if op[0] == "defragment" {
			cnt := 0
			for _, v := range alocuente {
				if v == 0 {
					cnt++
				}
			}
			newAlocuente := make([]int, 0, m)
			for _, v := range alocuente {
				if v != 0 {
					newAlocuente = append(newAlocuente, v)
				}
			}
			for j := 0; j < cnt; j++ {
				newAlocuente = append(newAlocuente, 0)
			}
			alocuente = newAlocuente
		}
	}
}

func contains(slice []int, item int) bool {
	for _, v := range slice {
		if v == item {
			return true
		}
	}
	return false
}

// <END-OF-CODE>
