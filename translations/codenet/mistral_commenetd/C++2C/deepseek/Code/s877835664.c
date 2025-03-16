#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

// Include necessary headers for the program

typedef long long ll;
typedef struct {
    ll *data;
    int size;
} vll;
typedef struct {
    int *data;
    int size;
} sll;

// Define aliases for common data types and containers

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

// Define helper functions for gcd and lcm

typedef struct {
    ll key;
    int value;
} Pair;

typedef struct {
    Pair *data;
    int size;
    int capacity;
} Map;

void mapInit(Map *map, int capacity) {
    map->data = (Pair *)malloc(capacity * sizeof(Pair));
    map->size = 0;
    map->capacity = capacity;
}

void mapInsert(Map *map, ll key, int value) {
    if (map->size >= map->capacity) {
        map->capacity *= 2;
        map->data = (Pair *)realloc(map->data, map->capacity * sizeof(Pair));
    }
    map->data[map->size].key = key;
    map->data[map->size].value = value;
    map->size++;
}

int mapGet(Map *map, ll key) {
    for (int i = 0; i < map->size; i++) {
        if (map->data[i].key == key) {
            return map->data[i].value;
        }
    }
    return -1; // Not found
}

// Define a simple map implementation

bool isPrimeNumber(ll num) {
    if (num <= 2) return true;
    else if (num % 2 == 0) return false;

    double sqrtNum = sqrt(num);
    // Check if the number is prime by checking divisibility up to its square root

    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

// Function to check if a number is prime

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    // Extended Euclidean Algorithm to find modular multiplicative inverse

    while (b) {
        ll t = a / b;
        a -= t * b;
        ll temp = a; a = b; b = temp;
        u -= t * v;
        temp = u; u = v; v = temp;
    }
    u %= m;
    // Make the result positive and less than 'm'

    if (u < 0) u += m;
    return u;
}

// Function to find modular multiplicative inverse

#define rep(i, s, e) for (ll i = s; i < e; i++)
#define repeq(i, s, e) for (ll i = s; i <= e; i++)

// Macros for for loops

int main() {
    ll N, K;
    // Declare variables for input

    scanf("%lld %lld", &N, &K);
    // Read input for 'N' and 'K'

    vll A;
    A.data = (ll *)malloc((N + 1) * sizeof(ll));
    A.size = N + 1;
    // Initialize an array 'A' of size 'N+1'

    rep(i, 1, N + 1) {
        scanf("%lld", &A.data[i]);
        // Read input for each element of the array 'A'
    }

    ll cur = 1;
    // Initialize a variable 'cur' to keep track of the current position in the array

    int *dic = (int *)malloc((N + 1) * sizeof(int));
    memset(dic, -1, (N + 1) * sizeof(int));
    // Initialize an array 'dic' of size 'N+1' to store the distance from the start for each position

    bool flg = false;
    // Initialize a boolean variable 'flg' to check if we need to reverse the direction of traversal

    rep(i, 1, K + 1) {
        if (dic[cur] < 0 || flg) {
            dic[cur] = i;
            // If the distance from the start for the current position is not yet determined or we need to reverse the direction, update the distance

            cur = A.data[cur];
            // Move to the next position
        } else if (!flg) {
            ll tmp = K - (dic[cur] - 1);
            tmp %= i - dic[cur];
            // Calculate the number of steps we need to take to reach the position 'i' from the current position

            i = K - tmp;
            // Update 'i' to the position we need to reach

            flg = true;
        }
    }

    printf("%lld\n", cur);
    // Print the final answer, which is the position of the last visited node

    free(A.data);
    free(dic);
    // Free allocated memory

    return 0;
}
// Main function to solve the problem

