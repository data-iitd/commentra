
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT 1000000

typedef struct {
    int val;
    int count;
} Entry;

int main() {
    // Create an instance of FastScanner to read input efficiently
    FastScanner input = new FastScanner();

    // Read the number of integers
    int n = input.nextInt();

    // Create a HashMap to store the frequency of each integer
    HashMap<int, int> map = new HashMap<int, int>();

    // Read n integers and update their counts in the hash map
    for (int i = 0; i < n; i++) {
        int val = input.nextInt();
        map.put(val, map.getOrDefault(val, 0) + 1);
    }

    // Initialize max to the smallest possible integer value
    int max = INT_MIN;

    // Iterate through the hash map to find the maximum count
    for (Map.Entry<int, int> entry : map.entrySet()) {
        int value = entry.getValue();
        max = max(max, value);
    }

    // Print the maximum count and the size of the hash map
    printf("%d %d\n", max, map.size());

    return 0;
}

// Utility class to read input efficiently
typedef struct {
    char* buffer;
    char* buffer_pos;
} FastScanner;

FastScanner new_fast_scanner() {
    FastScanner scanner;
    scanner.buffer = (char*) malloc(MAX_INPUT * sizeof(char));
    scanner.buffer_pos = scanner.buffer;
    return scanner;
}

int fast_scanner_next_int(FastScanner* scanner) {
    char* end;
    int result = strtol(scanner->buffer_pos, &end, 10);
    scanner->buffer_pos = end;
    return result;
}

void fast_scanner_next_line(FastScanner* scanner) {
    char* end;
    strtol(scanner->buffer_pos, &end, 10);
    scanner->buffer_pos = end;
}

int main() {
    // Create an instance of FastScanner to read input efficiently
    FastScanner input = new_fast_scanner();

    // Read the number of integers
    int n = fast_scanner_next_int(input);

    // Create a HashMap to store the frequency of each integer
    HashMap<int, int> map = new HashMap<int, int>();

    // Read n integers and update their counts in the hash map
    for (int i = 0; i < n; i++) {
        int val = fast_scanner_next_int(input);
        map.put(val, map.getOrDefault(val, 0) + 1);
    }

    // Initialize max to the smallest possible integer value
    int max = INT_MIN;

    // Iterate through the hash map to find the maximum count
    for (Map.Entry<int, int> entry : map.entrySet()) {
        int value = entry.getValue();
        max = max(max, value);
    }

    // Print the maximum count and the size of the hash map
    printf("%d %d\n", max, map.size());

    return 0;
}

// Utility class to read input efficiently
typedef struct {
    char* buffer;
    char* buffer_pos;
} FastScanner;

FastScanner new_fast_scanner() {
    FastScanner scanner;
    scanner.buffer = (char*) malloc(MAX_INPUT * sizeof(char));
    scanner.buffer_pos = scanner.buffer;
    return scanner;
}

int fast_scanner_next_int(FastScanner* scanner) {
    char* end;
    int result = strtol(scanner->buffer_pos, &end, 10);
    scanner->buffer_pos = end;
    return result;
}

void fast_scanner_next_line(FastScanner* scanner) {
    char* end;
    strtol(scanner->buffer_pos, &end, 10);
    scanner->buffer_pos = end;
}

int main() {
    // Create an instance of FastScanner to read input efficiently
    FastScanner input = new_fast_scanner();

    // Read the number of integers
    int n = fast_scanner_next_int(input);

    // Create a HashMap to store the frequency of each integer
    HashMap<int, int> map = new HashMap<int, int>();

    // Read n integers and update their counts in the hash map
    for (int i = 0; i < n; i++) {
        int val = fast_scanner_next_int(input);
        map.put(val, map.getOrDefault(val, 0) + 1);
    }

    // Initialize max to the smallest possible integer value
    int max = INT_MIN;

    // Iterate through the hash map to find the maximum count
    for (Map.Entry<int, int> entry : map.entrySet()) {
        int value = entry.getValue();
        max = max(max, value);
    }

    // Print the maximum count and the size of the hash map
    printf("%d %d\n", max, map.size());

    return 0;
}

// Utility class to read input efficiently
typedef struct {
    char* buffer;
    char* buffer_pos;
} FastScanner;

FastScanner new_fast_scanner() {
    FastScanner scanner;
    scanner.buffer = (char*) malloc(MAX_INPUT * sizeof(char));
    scanner.buffer_pos = scanner.buffer;
    return scanner;
}

int fast_scanner_next_int(FastScanner* scanner) {
    char* end;
    int result = strtol(scanner->buffer_pos, &end, 10);
    scanner->buffer_pos = end;
    return result;
}

void fast_scanner_next_line(FastScanner* scanner) {
    char* end;
    strtol(scanner->buffer_pos, &end, 10);
    scanner->buffer_pos = end;
}

int main() {
    // Create an instance of FastScanner to read input efficiently
    FastScanner input = new_fast_scanner();

    // Read the number of integers
    int n = fast_scanner_next_int(input);

    // Create a HashMap to store the frequency of each integer
    HashMap<int, int> map = new HashMap<int, int>();

    // Read n integers and update their counts in the hash map
    for (int i = 0; i < n; i++) {
        int val = fast_scanner_next_int(input);
        map.put(val, map.getOrDefault(val, 0) + 1);
    }

    // Initialize max to the smallest possible integer value
    int max = INT_MIN;

    // Iterate through the hash map to find the maximum count
    for (Map.Entry<int, int> entry : map.entrySet()) {
        int value = entry.getValue();
        max = max(max, value);
    }

    // Print the maximum count and the size of the hash map
    printf("%d %d\n", max, map.size());

    return 0;
}

// Utility class to read input efficiently
typedef struct {
    char* buffer;
    char* buffer_pos;
} FastScanner;

FastScanner new_fast_scanner() {
    FastScanner scanner;
    scanner.buffer = (char*) malloc(MAX_INPUT * sizeof(char));
    scanner.buffer_pos = scanner.buffer;
    return scanner;
}

int fast_scanner_next_int(FastScanner* scanner) {
    char* end;
    int result = strtol(scanner->buffer_pos, &end, 10);
    scanner->buffer_pos = end;
    return result;
}

void fast_scanner_next_line(FastScanner* scanner) {
    char* end;
    strtol(scanner->buffer_pos, &end, 10);
    scanner->buffer_pos = end;
}

int main() {
    // Create an instance of FastScanner to read input efficiently
    FastScanner input = new_fast_scanner();

    // Read the number of integers
    int n = fast_scanner_next_int(input);

    // Create a HashMap to store the frequency of each integer
    HashMap<int, int> map = new HashMap<int, int>();

    // Read n integers and update their counts in the hash map
    for (int i = 0; i < n; i++) {
        int val = fast_scanner_next_int(input);
        map.put(val, map.getOrDefault(val, 0) + 1);
    }

    // Initialize max to the smallest possible integer value
    int max = INT_MIN;

    // Iterate through the hash map to find the maximum count
    for (Map.Entry<int, int> entry : map.entrySet()) {
        int value = entry.getValue();
        max = max(max, value);
    }

    // Print the maximum count and the size of the hash map
    printf("%d %d\n", max, map.size());

    return 0;
}

// Utility class to read input efficiently
typedef struct {
    char* buffer;
    char* buffer_pos;
} FastScanner;

FastScanner new_fast_scanner() {
    FastScanner scanner;
    scanner.buffer = (char*) malloc(MAX_INPUT * sizeof(char));
    scanner.buffer_pos = scanner.buffer;
    return scanner;
}

int fast_scanner_next_int(FastScanner* scanner) {
    char* end;
    int result = strtol(scanner->buffer_pos, &end, 10);
    scanner->buffer_pos = end;
    return result;
}

void fast_scanner_next_line(FastScanner* scanner) {
    char* end;
    strtol(scanner->buffer_pos, &end, 10);
    scanner->buffer_pos = end;
}

int main() {
    // Create an instance of FastScanner to read input efficiently
    FastScanner input = new_fast_scanner();

    // Read the number of integers
    int n = fast_scanner_next_int(input);

    // Create a HashMap to store the frequency of each integer
    HashMap<int, int> map = new HashMap<int, int>();

    // Read n integers and update their counts in the hash map
    for (int i = 0; i < n; i++) {
        int val = fast_scanner_next_int(input);
        map.put(val, map.getOrDefault(val, 0) + 1);
    }

    // Initialize max to the smallest possible integer value
    int max = INT_MIN;

    // Iterate through the hash map to find the maximum count
    for (Map.Entry<int, int> entry : map.entrySet()) {
        int value = entry.getValue();
        max = max(max, value);
    }

    // Print the maximum count and the size of the hash map
    printf("%d %d\n", max, map.size());

    return 0;
}

// Utility class to read input efficiently
typedef struct {
    char* buffer;
    char* buffer_pos;
} FastScanner;

FastScanner new_fast_scanner() {
    FastScanner scanner;
    scanner.buffer = (char*) malloc(MAX_INPUT * sizeof(char));
    scanner.buffer_pos = scanner.buffer;
    return scanner;
}

int fast_scanner_next_int(FastScanner* scanner) {
    char* end;
    int result = strtol(scanner->buffer_pos, &end, 10);
    scanner->buffer_pos = end;
    return result;
}

void fast_scanner_next_line(FastScanner* scanner) {
    char* end;
    strtol(scanner->buffer_pos, &end, 10);
    scanner->buffer_pos = end;
}

int main() {
    // Create an instance of FastScanner to read input efficiently
    FastScanner input = new_fast_scanner();

    // Read the number of integers
    int n = fast_scanner_next_int(input);

    // Create a HashMap to store the frequency of each integer
    HashMap<int, int> map = new HashMap<int, int>();

    // Read n integers and update their counts in the hash map
    for (int i = 0; i < n; i++) {
        int val = fast_scanner_next_int(input);
        map.put(val, map.getOrDefault(val, 0) + 1);
    }

    // Initialize max to the smallest possible integer value
    int max = INT_MIN;

    // Iterate through 