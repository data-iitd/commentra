
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define helper functions
void hpop(int *heap, int *size) {
    if (*size == 0) {
        return;
    }
    int last = heap[*size - 1];
    heap[*size - 1] = heap[0];
    heap[0] = last;
    (*size)--;
    int i = 0;
    int j = 2 * i + 1;
    while (j < *size) {
        if (j + 1 < *size && heap[j] < heap[j + 1]) {
            j++;
        }
        if (heap[i] < heap[j]) {
            break;
        }
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
        i = j;
        j = 2 * i + 1;
    }
}

void hpush(int *heap, int *size, int item) {
    heap[*size] = item;
    int i = *size;
    int j = (i - 1) / 2;
    while (i > 0 && heap[i] < heap[j]) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
        i = j;
        j = (i - 1) / 2;
    }
    (*size)++;
}

// Define helper functions
int min(int a, int b) {
    return a < b ? a : b;
}

// Define helper functions
int max(int a, int b) {
    return a > b ? a : b;
}

// Define helper functions
int abs(int a) {
    return a > 0 ? a : -a;
}

// Define helper functions
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Define helper functions
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// Define helper functions
int pow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    return a * pow(a, b - 1);
}

// Define helper functions
int sqrt(int a) {
    int i = 1;
    while (i * i <= a) {
        i++;
    }
    return i - 1;
}

// Define helper functions
int is_prime(int a) {
    if (a == 1) {
        return 0;
    }
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Define helper functions
int is_palindrome(int a) {
    int rev = 0;
    int temp = a;
    while (temp > 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return rev == a;
}

// Define helper functions
int is_perfect_square(int a) {
    int i = 1;
    while (i * i <= a) {
        i++;
    }
    return i * i == a;
}

// Define helper functions
int is_fibonacci(int a) {
    int i = 1;
    int j = 2;
    while (i + j <= a) {
        if (i + j == a) {
            return 1;
        }
        int temp = i;
        i = j;
        j = temp + j;
    }
    return 0;
}

// Define helper functions
int is_lucky(int a) {
    int sum = 0;
    while (a > 0) {
        sum += a % 10;
        a /= 10;
    }
    return sum == 7;
}

// Define helper functions
int is_happy(int a) {
    int sum = 0;
    while (a > 0) {
        sum += (a % 10) * (a % 10);
        a /= 10;
    }
    return sum == 1;
}

// Define helper functions
int is_armstrong(int a) {
    int sum = 0;
    int temp = a;
    while (temp > 0) {
        sum += (temp % 10) * (temp % 10) * (temp % 10);
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_neon(int a) {
    int sum = 0;
    while (a > 0) {
        sum += a % 10;
        a /= 10;
    }
    return sum == 9;
}

// Define helper functions
int is_disarium(int a) {
    int sum = 1;
    while (a > 0) {
        sum *= a % 10;
        a /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_pandigital(int a) {
    int temp = a;
    int i = 1;
    while (temp > 0) {
        if (temp % 10 != i) {
            return 0;
        }
        temp /= 10;
        i++;
    }
    return 1;
}

// Define helper functions
int is_automorphic(int a) {
    int temp = a;
    int sum = 0;
    while (temp > 0) {
        sum = sum * 10 + temp % 10;
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_strobogrammatic(int a) {
    int temp = a;
    int sum = 0;
    while (temp > 0) {
        if (temp % 10 == 0 || temp % 10 == 1 || temp % 10 == 8) {
            sum = sum * 10 + temp % 10;
        } else if (temp % 10 == 6) {
            sum = sum * 10 + 9;
        } else if (temp % 10 == 9) {
            sum = sum * 10 + 6;
        } else {
            return 0;
        }
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_palindromic_prime(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int sum = 0;
    while (temp > 0) {
        sum = sum * 10 + temp % 10;
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_prime_palindrome(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int sum = 0;
    while (temp > 0) {
        sum = sum * 10 + temp % 10;
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_prime_strobogrammatic(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int sum = 0;
    while (temp > 0) {
        if (temp % 10 == 0 || temp % 10 == 1 || temp % 10 == 8) {
            sum = sum * 10 + temp % 10;
        } else if (temp % 10 == 6) {
            sum = sum * 10 + 9;
        } else if (temp % 10 == 9) {
            sum = sum * 10 + 6;
        } else {
            return 0;
        }
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_prime_automorphic(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int sum = 0;
    while (temp > 0) {
        sum = sum * 10 + temp % 10;
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_prime_neon(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int sum = 0;
    while (temp > 0) {
        sum = sum * 10 + temp % 10;
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_prime_disarium(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int sum = 1;
    while (temp > 0) {
        sum *= temp % 10;
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_prime_pandigital(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int i = 1;
    while (temp > 0) {
        if (temp % 10 != i) {
            return 0;
        }
        temp /= 10;
        i++;
    }
    return 1;
}

// Define helper functions
int is_prime_automorphic(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int sum = 0;
    while (temp > 0) {
        sum = sum * 10 + temp % 10;
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_prime_strobogrammatic(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int sum = 0;
    while (temp > 0) {
        if (temp % 10 == 0 || temp % 10 == 1 || temp % 10 == 8) {
            sum = sum * 10 + temp % 10;
        } else if (temp % 10 == 6) {
            sum = sum * 10 + 9;
        } else if (temp % 10 == 9) {
            sum = sum * 10 + 6;
        } else {
            return 0;
        }
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_prime_palindromic_prime(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int sum = 0;
    while (temp > 0) {
        sum = sum * 10 + temp % 10;
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_prime_prime_palindrome(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int sum = 0;
    while (temp > 0) {
        sum = sum * 10 + temp % 10;
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_prime_prime_strobogrammatic(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int sum = 0;
    while (temp > 0) {
        if (temp % 10 == 0 || temp % 10 == 1 || temp % 10 == 8) {
            sum = sum * 10 + temp % 10;
        } else if (temp % 10 == 6) {
            sum = sum * 10 + 9;
        } else if (temp % 10 == 9) {
            sum = sum * 10 + 6;
        } else {
            return 0;
        }
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_prime_prime_automorphic(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int sum = 0;
    while (temp > 0) {
        sum = sum * 10 + temp % 10;
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_prime_prime_neon(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int sum = 0;
    while (temp > 0) {
        sum = sum * 10 + temp % 10;
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_prime_prime_disarium(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int sum = 1;
    while (temp > 0) {
        sum *= temp % 10;
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_prime_prime_pandigital(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int i = 1;
    while (temp > 0) {
        if (temp % 10 != i) {
            return 0;
        }
        temp /= 10;
        i++;
    }
    return 1;
}

// Define helper functions
int is_prime_prime_automorphic(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int sum = 0;
    while (temp > 0) {
        sum = sum * 10 + temp % 10;
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_prime_prime_strobogrammatic(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int sum = 0;
    while (temp > 0) {
        if (temp % 10 == 0 || temp % 10 == 1 || temp % 10 == 8) {
            sum = sum * 10 + temp % 10;
        } else if (temp % 10 == 6) {
            sum = sum * 10 + 9;
        } else if (temp % 10 == 9) {
            sum = sum * 10 + 6;
        } else {
            return 0;
        }
        temp /= 10;
    }
    return sum == a;
}

// Define helper functions
int is_prime_prime_palindromic_prime(int a) {
    if (!is_prime(a)) {
        return 0;
    }
    int temp = a;
    int sum = 0;
    while (temp > 0) {
        sum = sum * 10 + te