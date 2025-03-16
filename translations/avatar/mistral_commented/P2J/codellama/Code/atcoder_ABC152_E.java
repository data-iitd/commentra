
// Importing the java.util.Scanner class to read the input.
import java.util.Scanner;

// Defining a function lcm to calculate the least common multiple of two numbers a and b.
public static long lcm(long a, long b) {
    // Calculating the greatest common divisor of a and b using the Euclidean algorithm.
    long g = gcd(a, b);
    // Returning the product of a and b divided by their greatest common divisor.
    return a * b / g;
}

// Defining a function gcd to calculate the greatest common divisor of two numbers a and b.
public static long gcd(long a, long b) {
    // If b is 0, return a.
    if (b == 0) {
        return a;
    }
    // If a is 0, return b.
    if (a == 0) {
        return b;
    }
    // If a is negative, return the absolute value of the gcd of a and b.
    if (a < 0) {
        return gcd(-a, b);
    }
    // If b is negative, return the absolute value of the gcd of a and b.
    if (b < 0) {
        return gcd(a, -b);
    }
    // If a is greater than b, return the gcd of a and b - a.
    if (a > b) {
        return gcd(a, b - a);
    }
    // If b is greater than a, return the gcd of a and b - b.
    if (b > a) {
        return gcd(a, b - b);
    }
    // If a and b are equal, return a.
    if (a == b) {
        return a;
    }
    // If a and b are not equal, return the gcd of a and b - 1.
    return gcd(a, b - 1);
}

// Defining a function pow to calculate the power of a number a to an integer b.
public static long pow(long a, long b) {
    // If b is 0, return 1.
    if (b == 0) {
        return 1;
    }
    // If b is negative, return the reciprocal of the power of a to the absolute value of b.
    if (b < 0) {
        return 1 / pow(a, -b);
    }
    // If b is greater than 0, return the product of a and the power of a to b - 1.
    if (b > 0) {
        return a * pow(a, b - 1);
    }
    // If b is equal to 0, return a.
    if (b == 0) {
        return a;
    }
    // If b is not equal to 0, return the power of a to b - 1.
    return pow(a, b - 1);
}

// Defining a function mod to calculate the modulus of a number a to an integer b.
public static long mod(long a, long b) {
    // If b is 0, return 0.
    if (b == 0) {
        return 0;
    }
    // If b is negative, return the modulus of a to the absolute value of b.
    if (b < 0) {
        return mod(a, -b);
    }
    // If b is greater than 0, return the modulus of a to b - 1.
    if (b > 0) {
        return mod(a, b - 1);
    }
    // If b is equal to 0, return a.
    if (b == 0) {
        return a;
    }
    // If b is not equal to 0, return the modulus of a to b - 1.
    return mod(a, b - 1);
}

// Defining a function sum to calculate the sum of a list of integers.
public static long sum(long[] A) {
    // If the list A is empty, return 0.
    if (A.length == 0) {
        return 0;
    }
    // If the list A is not empty, return the sum of the first element of A and the sum of the remaining elements of A.
    return A[0] + sum(Arrays.copyOfRange(A, 1, A.length));
}

// Defining a function product to calculate the product of a list of integers.
public static long product(long[] A) {
    // If the list A is empty, return 1.
    if (A.length == 0) {
        return 1;
    }
    // If the list A is not empty, return the product of the first element of A and the product of the remaining elements of A.
    return A[0] * product(Arrays.copyOfRange(A, 1, A.length));
}

// Defining a function main to calculate the final answer.
public static void main(String[] args) {
    // Reading the input N and storing the list A of N integers.
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long[] A = new long[N];
    for (int i = 0; i < N; i++) {
        A[i] = sc.nextLong();
    }

    // Initializing the variable _lcm to 1.
    long _lcm = 1;

    // Iterating through each number a in the list A and updating the value of _lcm using the lcm function.
    for (long a : A) {
        // Update the value of _lcm using the lcm function.
        _lcm = lcm(_lcm, a);
    }

    // Calculating the answer ans using the formula _lcm * sum ( [ pow ( s , MOD - 2 , MOD ) for s in A ] ) % MOD.
    long ans = _lcm * sum(A) % MOD;

    // Printing the final answer.
    System.out.println(ans);
}

// End of code.
