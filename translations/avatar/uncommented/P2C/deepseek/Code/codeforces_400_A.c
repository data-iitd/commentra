#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    for (int case_num = 0; case_num < num_cases; case_num++) {
        char input[13];
        scanf("%s", input);
        
        int s[12];
        for (int i = 0; i < 12; i++) {
            if (input[i] == 'O') {
                s[i] = 0;
            } else {
                s[i] = 1;
            }
        }
        
        int tot[100][2];
        int count = 0;
        
        for (int i = 1; i <= 12; i++) {
            if (12 % i == 0) {
                int rows = 12 / i;
                int cols = i;
                int grid[rows][cols];
                for (int j = 0; j < rows; j++) {
                    for (int k = 0; k < cols; k++) {
                        grid[j][k] = s[j * cols + k];
                    }
                }
                
                int found = 0;
                for (int j = 0; j < cols; j++) {
                    int sum = 0;
                    for (int k = 0; k < rows; k++) {
                        sum += grid[k][j];
                    }
                    if (sum == rows) {
                        found = 1;
                        break;
                    }
                }
                
                if (found) {
                    tot[count][0] = rows;
                    tot[count][1] = cols;
                    count++;
                }
            }
        }
        
        printf("%d", count);
        for (int i = 0; i < count; i++) {
            printf(" %dx%d", tot[i][0], tot[i][1]);
        }
        printf("\n");
    }
    
    return 0;
}

