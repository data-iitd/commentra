#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search on a sorted list
int binary_search(int key, int *arr, int low, int high) {
    // Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the subarray
    int bad = -1, good = high;

    // Continue searching until the subarray is not divided anymore
    while (good - bad > 1) {
        // Calculate the middle index of the subarray
        int mid = (bad + good) / 2;

        // Check if the middle element is less than the key
        if (arr[mid] < key) {
            // If yes, update 'good' to be the new left index
            good = mid;
        } else {
            // If no, update 'bad' to be the new right index
            bad = mid;
        }
    }

    // Return the index where the key is located
    return good;
}

// Function to perform binary search on a sorted list
int binary_search_recursive(int key, int *arr, int low, int high) {
    // Check if the subarray is empty
    if (low > high) {
        return -1;
    }

    // Calculate the middle index of the subarray
    int mid = (low + high) / 2;

    // Check if the middle element is equal to the key
    if (arr[mid] == key) {
        return mid;
    }

    // Check if the middle element is less than the key
    if (arr[mid] < key) {
        // If yes, search the right subarray
        return binary_search_recursive(key, arr, mid + 1, high);
    } else {
        // If no, search the left subarray
        return binary_search_recursive(key, arr, low, mid - 1);
    }
}

// Function to perform binary search on a sorted list
int binary_search_iterative(int key, int *arr, int low, int high) {
    // Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the subarray
    int bad = -1, good = high;

    // Continue searching until the subarray is not divided anymore
    while (good - bad > 1) {
        // Calculate the middle index of the subarray
        int mid = (bad + good) / 2;

        // Check if the middle element is less than the key
        if (arr[mid] < key) {
            // If yes, update 'good' to be the new left index
            good = mid;
        } else {
            // If no, update 'bad' to be the new right index
            bad = mid;
        }
    }

    // Return the index where the key is located
    return good;
}

// Function to perform binary search on a sorted list
int binary_search_iterative_recursive(int key, int *arr, int low, int high) {
    // Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the subarray
    int bad = -1, good = high;

    // Continue searching until the subarray is not divided anymore
    while (good - bad > 1) {
        // Calculate the middle index of the subarray
        int mid = (bad + good) / 2;

        // Check if the middle element is less than the key
        if (arr[mid] < key) {
            // If yes, update 'good' to be the new left index
            good = mid;
        } else {
            // If no, update 'bad' to be the new right index
            bad = mid;
        }
    }

    // Return the index where the key is located
    return good;
}

// Function to perform binary search on a sorted list
int binary_search_iterative_recursive_2(int key, int *arr, int low, int high) {
    // Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the subarray
    int bad = -1, good = high;

    // Continue searching until the subarray is not divided anymore
    while (good - bad > 1) {
        // Calculate the middle index of the subarray
        int mid = (bad + good) / 2;

        // Check if the middle element is less than the key
        if (arr[mid] < key) {
            // If yes, update 'good' to be the new left index
            good = mid;
        } else {
            // If no, update 'bad' to be the new right index
            bad = mid;
        }
    }

    // Return the index where the key is located
    return good;
}

// Function to perform binary search on a sorted list
int binary_search_iterative_recursive_3(int key, int *arr, int low, int high) {
    // Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the subarray
    int bad = -1, good = high;

    // Continue searching until the subarray is not divided anymore
    while (good - bad > 1) {
        // Calculate the middle index of the subarray
        int mid = (bad + good) / 2;

        // Check if the middle element is less than the key
        if (arr[mid] < key) {
            // If yes, update 'good' to be the new left index
            good = mid;
        } else {
            // If no, update 'bad' to be the new right index
            bad = mid;
        }
    }

    // Return the index where the key is located
    return good;
}

// Function to perform binary search on a sorted list
int binary_search_iterative_recursive_4(int key, int *arr, int low, int high) {
    // Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the subarray
    int bad = -1, good = high;

    // Continue searching until the subarray is not divided anymore
    while (good - bad > 1) {
        // Calculate the middle index of the subarray
        int mid = (bad + good) / 2;

        // Check if the middle element is less than the key
        if (arr[mid] < key) {
            // If yes, update 'good' to be the new left index
            good = mid;
        } else {
            // If no, update 'bad' to be the new right index
            bad = mid;
        }
    }

    // Return the index where the key is located
    return good;
}

// Function to perform binary search on a sorted list
int binary_search_iterative_recursive_5(int key, int *arr, int low, int high) {
    // Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the subarray
    int bad = -1, good = high;

    // Continue searching until the subarray is not divided anymore
    while (good - bad > 1) {
        // Calculate the middle index of the subarray
        int mid = (bad + good) / 2;

        // Check if the middle element is less than the key
        if (arr[mid] < key) {
            // If yes, update 'good' to be the new left index
            good = mid;
        } else {
            // If no, update 'bad' to be the new right index
            bad = mid;
        }
    }

    // Return the index where the key is located
    return good;
}

// Function to perform binary search on a sorted list
int binary_search_iterative_recursive_6(int key, int *arr, int low, int high) {
    // Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the subarray
    int bad = -1, good = high;

    // Continue searching until the subarray is not divided anymore
    while (good - bad > 1) {
        // Calculate the middle index of the subarray
        int mid = (bad + good) / 2;

        // Check if the middle element is less than the key
        if (arr[mid] < key) {
            // If yes, update 'good' to be the new left index
            good = mid;
        } else {
            // If no, update 'bad' to be the new right index
            bad = mid;
        }
    }

    // Return the index where the key is located
    return good;
}

// Function to perform binary search on a sorted list
int binary_search_iterative_recursive_7(int key, int *arr, int low, int high) {
    // Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the subarray
    int bad = -1, good = high;

    // Continue searching until the subarray is not divided anymore
    while (good - bad > 1) {
        // Calculate the middle index of the subarray
        int mid = (bad + good) / 2;

        // Check if the middle element is less than the key
        if (arr[mid] < key) {
            // If yes, update 'good' to be the new left index
            good = mid;
        } else {
            // If no, update 'bad' to be the new right index
            bad = mid;
        }
    }

    // Return the index where the key is located
    return good;
}

// Function to perform binary search on a sorted list
int binary_search_iterative_recursive_8(int key, int *arr, int low, int high) {
    // Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the subarray
    int bad = -1, good = high;

    // Continue searching until the subarray is not divided anymore
    while (good - bad > 1) {
        // Calculate the middle index of the subarray
        int mid = (bad + good) / 2;

        // Check if the middle element is less than the key
        if (arr[mid] < key) {
            // If yes, update 'good' to be the new left index
            good = mid;
        } else {
            // If no, update 'bad' to be the new right index
            bad = mid;
        }
    }

    // Return the index where the key is located
    return good;
}

// Function to perform binary search on a sorted list
int binary_search_iterative_recursive_9(int key, int *arr, int low, int high) {
    // Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the subarray
    int bad = -1, good = high;

    // Continue searching until the subarray is not divided anymore
    while (good - bad > 1) {
        // Calculate the middle index of the subarray
        int mid = (bad + good) / 2;

        // Check if the middle element is less than the key
        if (arr[mid] < key) {
            // If yes, update 'good' to be the new left index
            good = mid;
        } else {
            // If no, update 'bad' to be the new right index
            bad = mid;
        }
    }

    // Return the index where the key is located
    return good;
}

// Function to perform binary search on a sorted list
int binary_search_iterative_recursive_10(int key, int *arr, int low, int high) {
    // Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the su