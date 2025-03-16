package main
import "fmt"
func rememberTheNumber(nums []int, i int, operations string, ans *[1]int) {
    if i >= 3 {
        return
    }
    for j := 0; j < 4; j++ {
        for k := j + 1; k < 4; k++ {
            if nums[j]!= -1 && nums[k]!= -1 {
                s := nums[j]
                nums[j] = -1
                t := nums[k]
                if operations[i] == "+" {
                    nums[k] = s + t
                } else if operations[i] == "*" {
                    nums[k] = s * t
                }
                if i == 2 && nums[k] < ans[0] {
                    ans[0] = nums[k]
                }
                rememberTheNumber(nums, i+1, operations, ans)
                nums[j] = s
                nums[k] = t
    }
}
}
func main() {
    var nums [4]int
    var operations string
    var ans [1]int
    fmt.Scanf("%d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3])
    fmt.Scanf("%s", &operations)
    rememberTheNumber(nums[:], 0, operations, &ans)
    fmt.Printf("%d\n", ans[0])
}
