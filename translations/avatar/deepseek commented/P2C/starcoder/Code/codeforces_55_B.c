#include <stdio.h>
#include <stdlib.h>

int main() {
    int nums[4];
    char operations[3];
    int ans = 10000000000000000000000000;
    
    scanf("%d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3]);
    scanf("%c %c %c", &operations[0], &operations[1], &operations[2]);
    
    rememberTheNumber(nums, operations, 0, ans);
    
    printf("%d\n", ans);
    
    return 0;
}

void rememberTheNumber(int nums[], char operations[], int i, int ans) {
    if (i >= 3) {
        return;
    }
    
    for (int j = 0; j < 4; j++) {
        for (int k = j + 1; k < 4; k++) {
            if (nums[j]!= -1 && nums[k]!= -1) {
                int s = nums[j];
                nums[j] = -1;
                int t = nums[k];
                
                if (operations[i] == '+') {
                    nums[k] = s + t;
                } else if (operations[i] == '*') {
                    nums[k] = s * t;
                }
                
                if (i == 2 && nums[k] < ans) {
                    ans = nums[k];
                }
                
                rememberTheNumber(nums, operations, i + 1, ans);
                
                nums[j] = s;
                nums[k] = t;
            }
        }
    }
}

