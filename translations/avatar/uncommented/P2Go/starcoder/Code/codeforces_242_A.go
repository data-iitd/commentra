package main
import "fmt"
func main() {
	var x, y, a, b int
	fmt.Scanf("%d %d %d %d", &x, &y, &a, &b)
	games := make([][]int, 0)
	for i := a; i <= x; i++ {
		if i <= b {
			continue
		}
		for j := b; j <= y; j++ {
			if i > j {
				games = append(games, []int{i, j})
			}
		}
	}
	fmt.Println(len(games))
	for _, game := range games {
		fmt.Printf("%d %d\n", game[0], game[1])
	}
}
