#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the frequency of each character
struct freq {
    int count;
    char ch;
};

// Function to sort the frequency list
void sort_freq(struct freq *freq_list, int size) {
    int i, j;
    struct freq temp;
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (freq_list[i].count < freq_list[j].count) {
                temp = freq_list[i];
                freq_list[i] = freq_list[j];
                freq_list[j] = temp;
            }
        }
    }
}

// Function to check the frequency of each character in the two strings
int check_freq(char *s, char *t) {
    int i, j, k, count = 0;
    struct freq *freq_list;
    freq_list = (struct freq *)malloc(sizeof(struct freq) * 26);
    for (i = 0; i < 26; i++) {
        freq_list[i].count = 0;
        freq_list[i].ch = 'a' + i;
    }
    for (i = 0; s[i] != '\0'; i++) {
        freq_list[s[i] - 'a'].count++;
    }
    for (i = 0; t[i] != '\0'; i++) {
        freq_list[t[i] - 'a'].count++;
    }
    sort_freq(freq_list, 26);
    for (i = 0; i < 26; i++) {
        if (freq_list[i].count != 0) {
            count++;
        }
    }
    if (count == 26) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char s[1000], t[1000];
    scanf("%s", s);
    scanf("%s", t);
    if (check_freq(s, t)) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
    return 0;
}

