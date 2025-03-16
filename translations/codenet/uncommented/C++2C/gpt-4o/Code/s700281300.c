#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

typedef long long ll;

<<<<<<< HEAD
typedef struct Node {
    char *str;
    struct Node *next;
} Node;

typedef struct Set {
    Node *head;
} Set;

void initSet(Set *set) {
    set->head = NULL;
}

bool insertSet(Set *set, const char *s) {
    Node *current = set->head;
    while (current != NULL) {
        if (strcmp(current->str, s) == 0) {
            return false; // already exists
        }
        current = current->next;
    }
    
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->str = strdup(s);
    newNode->next = set->head;
    set->head = newNode;
    return true;
}

int sizeSet(Set *set) {
    int count = 0;
    Node *current = set->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void freeSet(Set *set) {
    Node *current = set->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp->str);
        free(temp);
    }
=======
typedef struct {
    char **data;
    int size;
    int capacity;
} Set;

void initSet(Set *set) {
    set->size = 0;
    set->capacity = 10;
    set->data = (char **)malloc(set->capacity * sizeof(char *));
}

void insertSet(Set *set, const char *str) {
    // Check for duplicates
    for (int i = 0; i < set->size; i++) {
        if (strcmp(set->data[i], str) == 0) {
            return; // Already exists
        }
    }
    // If not found, insert
    if (set->size == set->capacity) {
        set->capacity *= 2;
        set->data = (char **)realloc(set->data, set->capacity * sizeof(char *));
    }
    set->data[set->size] = strdup(str);
    set->size++;
}

void freeSet(Set *set) {
    for (int i = 0; i < set->size; i++) {
        free(set->data[i]);
    }
    free(set->data);
>>>>>>> 98c87cb78a (data updated)
}

void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    rep(i, n) {
<<<<<<< HEAD
        char s[1001];
=======
        char s[100]; // Assuming max length of string is 100
>>>>>>> 98c87cb78a (data updated)
        scanf("%s", s);

        Set st;
        initSet(&st);
        insertSet(&st, s);

        int len = strlen(s);
        REP(j, 1, len) {
<<<<<<< HEAD
            char res[1001] = {0};
            strncpy(res, s, j);
            res[j] = '\0';

            char res2[1001] = {0};
            strncpy(res2, s + j, len - j);
            res2[len - j] = '\0';

            char t[1001];
            strcpy(t, res);
            reverseString(res);
            char t2[1001];
            strcpy(t2, res2);
            reverseString(res2);

            insertSet(&st, strcat(t, t2));
            insertSet(&st, strcat(t2, t));

            insertSet(&st, strcat(t, res2));
            insertSet(&st, strcat(res2, t));

            insertSet(&st, strcat(res, t2));
            insertSet(&st, strcat(t2, res));

            insertSet(&st, strcat(res, res2));
            insertSet(&st, strcat(res2, res));
        }

        printf("%d\n", sizeSet(&st));
=======
            char res[100], res2[100];
            strncpy(res, s, j);
            res[j] = '\0';
            strncpy(res2, s + j, len - j);
            res2[len - j] = '\0';

            char t[100], t2[100];
            strcpy(t, res);
            reverseString(t);
            strcpy(t2, res2);
            reverseString(t2);

            char temp[200]; // To hold concatenated results

            // Insert combinations
            sprintf(temp, "%s%s", t, t2);
            insertSet(&st, temp);
            sprintf(temp, "%s%s", t2, t);
            insertSet(&st, temp);

            sprintf(temp, "%s%s", t, res2);
            insertSet(&st, temp);
            sprintf(temp, "%s%s", res2, t);
            insertSet(&st, temp);

            sprintf(temp, "%s%s", res, t2);
            insertSet(&st, temp);
            sprintf(temp, "%s%s", t2, res);
            insertSet(&st, temp);

            sprintf(temp, "%s%s", res, res2);
            insertSet(&st, temp);
            sprintf(temp, "%s%s", res2, res);
            insertSet(&st, temp);
        }

        printf("%d\n", st.size);
>>>>>>> 98c87cb78a (data updated)
        freeSet(&st);
    }

    return 0;
}

// <END-OF-CODE>
