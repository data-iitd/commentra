package main

import (
	"fmt"
	"strconv"
)

func main() {
	var t, m int
	fmt.Scan(&t, &m)

	alocuente := make([]int, m)
	var ind int = 1

	for i := 0; i < t; i++ {
		var op []string
		fmt.Scan(&op)

		if op[0] == "alloc" {
			pos := 0
			for j := 0; j < m; j++ {
				if alocuente[j] == 0 {
					pos++
					if pos == int(op[1]) {
						for k := j - int(op[1]) + 1; k <= j; k++ {
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
			if pos != int(op[1]) {
				fmt.Println("NULL")
			}
		} else if op[0] == "erase" {
			pos := 0
			if int(op[1]) == 0 || !contains(alocuente, int(op[1])) {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
			} else {
				for j := 0; j < m; j++ {
					if alocuente[j] == int(op[1]) {
						alocuente[j] = 0
					}
				}
			}
		} else if op[0] == "defragment" {
			cnt := 0
			for _, v := range alocuente {
				if v == 0 {
					cnt++
				}
			}
			newAlocuente := []int{}
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

func contains(s []int, e int) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

