
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the elements of the list
struct list {
    int data;
    struct list *next;
};

// Function to sort the list in ascending order
void sort ( struct list *head ) {
    struct list *current = head;
    struct list *min = head;
    struct list *temp = head;

    while ( current != NULL ) {
        min = current;
        temp = current->next;

        while ( temp != NULL ) {
            if ( temp->data < min->data ) {
                min = temp;
            }

            temp = temp->next;
        }

        if ( min != current ) {
            current->data = min->data;
            min->data = current->data;
        }

        current = current->next;
    }
}

// Function to find the number of distinct elements in the list
int distinct ( struct list *head ) {
    struct list *current = head;
    int count = 1;

    while ( current != NULL ) {
        if ( current->data >= count ) {
            count++;
        }

        current = current->next;
    }

    return count;
}

// Main function
int main ( ) {
    // Reading the number of elements in the list from the input
    int n;
    scanf ( "%d", &n );

    // Creating an array of size 'n' to store the elements
    struct list *list = ( struct list * ) malloc ( n * sizeof ( struct list ) );

    // Reading 'n' elements from the input and adding them to the array
    for ( int i = 0; i < n; i++ ) {
        scanf ( "%d", &list[i].data );
        list[i].next = NULL;
    }

    // Sorting the array in ascending order
    sort ( list );

    // Finding the number of distinct elements in the array
    int c = distinct ( list );

    // Writing the result to the output
    printf ( "%d\n", c );

    // Freeing the memory allocated for the array
    free ( list );

    return 0;
}

