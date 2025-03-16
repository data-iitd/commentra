
#include <stdio.h>
#include <string.h>

int main() {
    int num, counter = 0, fine = 0;
    char arr[100][100];
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%s", arr[i]);
    }
    for (int i = 0; i < num; i++) {
        for (int k = 0; k < num; k++) {
            if (arr[k][i] == 'C') {
                counter++;
            }
        }
        fine += (counter * (counter - 1)) / 2;
        counter = 0;
    }
    for (int i = 0; i < num; i++) {
        for (int k = 0; k < num; k++) {
            if (arr[i][k] == 'C') {
                counter++;
            }
        }
        fine += (counter * (counter - 1)) / 2;
        counter = 0;
    }
    printf("%d", fine);
    return 0;
}
//END-OF-CODE