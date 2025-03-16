#include <stdio.h>
#include <stdlib.h>

long long a[200000]; // Array to store the elements
int ind_a[200000]; // Array to store the indices of elements in array a

<<<<<<< HEAD
typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* used_inds = NULL; // Linked list to keep track of used indices

void insert_sorted(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    if (used_inds == NULL || used_inds->value > value) {
        new_node->next = used_inds;
        used_inds = new_node;
        return;
    }

    Node* current = used_inds;
    while (current->next != NULL && current->next->value < value) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

int lower_bound(int value) {
    Node* current = used_inds;
    int index = 0;
    while (current != NULL && current->value < value) {
        current = current->next;
        index++;
    }
    return index;
=======
typedef struct {
    int *data;
    int size;
    int capacity;
} Set;

void initSet(Set *set) {
    set->size = 0;
    set->capacity = 10;
    set->data = (int *)malloc(set->capacity * sizeof(int));
}

void insertSet(Set *set, int value) {
    if (set->size == set->capacity) {
        set->capacity *= 2;
        set->data = (int *)realloc(set->data, set->capacity * sizeof(int));
    }
    set->data[set->size++] = value;
}

int lowerBound(Set *set, int value) {
    int left = 0, right = set->size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (set->data[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    int N;
    scanf("%d", &N); // Read the number of elements
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]); // Read the elements into array a
    }
    for (int i = 0; i < N; i++) {
        ind_a[a[i] - 1] = i; // Initialize ind_a with the indices of elements in array a
    }

<<<<<<< HEAD
=======
    Set used_inds;
    initSet(&used_inds); // Initialize the set to keep track of used indices
>>>>>>> 98c87cb78a (data updated)
    long long ans = 0; // Variable to store the final answer
    for (int i = 0; i < N; i++) {
        long long left_border; // Variable to store the left boundary
        long long right_border; // Variable to store the right boundary
        long long cur_ind = ind_a[i]; // Current index of the element being processed
<<<<<<< HEAD

        int left_it_index = lower_bound(cur_ind);
        int right_it_index = lower_bound(cur_ind + 1);

        if (left_it_index == 0) {
            left_border = -1; // If left_it is the first element, set left_border to -1
        } else {
            Node* left_it = used_inds;
            for (int j = 0; j < left_it_index - 1; j++) {
                left_it = left_it->next;
            }
            left_border = left_it->value; // Set left_border to the value pointed by left_it
        }

        Node* right_it = used_inds;
        for (int j = 0; j < right_it_index; j++) {
            if (right_it != NULL) {
                right_it = right_it->next;
            }
        }
        if (right_it == NULL) {
            right_border = N; // If right_it is the end, set right_border to N
        } else {
            right_border = right_it->value; // Set right_border to the value pointed by right_it
        }

        ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1); // Calculate the contribution of the current element to the answer

        insert_sorted(cur_ind); // Insert the current index into the linked list used_inds
    }

    printf("%lld\n", ans); // Output the final answer
=======
        int left_it = lowerBound(&used_inds, cur_ind); // Get the lower bound index for cur_ind
        int right_it = lowerBound(&used_inds, cur_ind + 1); // Get the lower bound index for cur_ind + 1

        if (left_it == 0) {
            left_border = -1; // If left_it is the first element, set left_border to -1
        } else {
            left_border = used_inds.data[left_it - 1]; // Set left_border to the value before left_it
        }
        if (right_it == used_inds.size) {
            right_border = N; // If right_it is the end, set right_border to N
        } else {
            right_border = used_inds.data[right_it]; // Set right_border to the value pointed by right_it
        }
        ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1); // Calculate the contribution of the current element to the answer

        insertSet(&used_inds, cur_ind); // Insert the current index into the set used_inds
    }

    printf("%lld\n", ans); // Output the final answer
    free(used_inds.data); // Free the allocated memory for the set
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
