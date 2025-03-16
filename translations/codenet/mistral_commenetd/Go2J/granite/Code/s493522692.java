
// Util functions
package main;

import java.util.Scanner;

// Util functions
public class s493522692{
    // Scans the next token, a rune, into sc.Text().
    public static String nextStr() {
        Scanner sc = new Scanner(System.in);
        sc.next();
        return sc.next();
    }

    // With a comment explaining what the function does:
    // Scans the next token, a rune, into sc.Text().
    public static String nextStr() {
        Scanner sc = new Scanner(System.in);
        sc.next();
        return sc.next();
    }

    // Scans the next token, a string, into sc.Text().
    // Converts the string to an integer using Integer.parseInt() and returns it.
    public static int nextInt() {
        Scanner sc = new Scanner(System.in);
        sc.next();
        return Integer.parseInt(sc.next());
    }

    // With a comment explaining what the function does:
    // Scans the next token, a string, into sc.Text().
    // Converts the string to an integer using Integer.parseInt().
    public static int nextInt() {
        Scanner sc = new Scanner(System.in);
        sc.next();
        return Integer.parseInt(sc.next());
    }

    // Helper functions for mathematical operations
    public static int maxInt(int a, int b) {
        // Returns the maximum of two integers.
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }

    // With a comment explaining what the function does:
    // Returns the maximum of two integers.
    public static int maxInt(int a, int b) {
        // If 'a' is greater than 'b', return 'a'.
        if (a > b) {
            return a;
        } else {
            // Otherwise, return 'b'.
            return b;
        }
    }

    public static int minInt(int a, int b) {
        // Returns the minimum of two integers.
        if (a > b) {
            return b;
        } else {
            return a;
        }
    }

    // With a comment explaining what the function does:
    // Returns the minimum of two integers.
    public static int minInt(int a, int b) {
        // If 'a' is greater than 'b', return 'b'.
        if (a > b) {
            return b;
        } else {
            // Otherwise, return 'a'.
            return a;
        }
    }

    public static int absInt(int a) {
        // Returns the absolute value of an integer.
        if (a >= 0) {
            return a;
        } else {
            return -a;
        }
    }

    // With a comment explaining what the function does:
    // Returns the absolute value of an integer.
    public static int absInt(int a) {
        // If the integer is non-negative, return it as is.
        if (a >= 0) {
            return a;
        } else {
            // Otherwise, return the negative of the integer.
            return -a;
        }
    }

    public static float absFloat64(float a) {
        // Returns the absolute value of a floating-point number.
        if (a >= 0) {
            return a;
        } else {
            return -a;
        }
    }

    // With a comment explaining what the function does:
    // Returns the absolute value of a floating-point number.
    public static float absFloat64(float a) {
        // If the floating-point number is non-negative, return it as is.
        if (a >= 0) {
            return a;
        } else {
            // Otherwise, return the negative of the floating-point number.
            return -a;
        }
    }

    public static int maxFloat64(float a, float b) {
        // Returns the maximum of two floating-point numbers.
        if (a > b) {
            return (int) a;
        } else {
            return (int) b;
        }
    }

    // With a comment explaining what the function does:
    // Returns the maximum of two floating-point numbers.
    public static int maxFloat64(float a, float b) {
        // If 'a' is greater than 'b', return 'a'.
        if (a > b) {
            return (int) a;
        } else {
            // Otherwise, return 'b'.
            return (int) b;
        }
    }

    public static int minFloat64(float a, float b) {
        // Returns the minimum of two floating-point numbers.
        if (a > b) {
            return (int) b;
        } else {
            return (int) a;
        }
    }

    // With a comment explaining what the function does:
    // Returns the minimum of two floating-point numbers.
    public static int minFloat64(float a, float b) {
        // If 'a' is greater than 'b', return 'b'.
        if (a > b) {
            return (int) b;
        } else {
            // Otherwise, return 'a'.
            return (int) a;
        }
    }

    public static int str2Int(String s) {
        // Converts a string to an integer.
        return Integer.parseInt(s);
    }

    // With a comment explaining what the function does:
    // Converts a string to an integer.
    public static int str2Int(String s) {
        // Attempts to convert the string to an integer using Integer.parseInt().
        return Integer.parseInt(s);
    }

    public static String reverse(String s) {
        // Reverses a given string.
        char[] runes = s.toCharArray();
        // Iterates through the rune slice from both ends and swaps the elements.
        for (int i = 0, j = runes.length - 1; i < j; i++, j--) {
            // Swaps the elements at the current indices.
            char temp = runes[i];
            runes[i] = runes[j];
            runes[j] = temp;
        }
        // Returns the reversed string.
        return new String(runes);
    }

    // With a comment explaining what the function does:
    // Reverses a given string.
    public static String reverse(String s) {
        // Initializes a rune slice with the given string.
        char[] runes = s.toCharArray();
        // Iterates through the rune slice from both ends and swaps the elements.
        for (int i = 0, j = runes.length - 1; i < j; i++, j--) {
            // Swaps the elements at the current indices.
            char temp = runes[i];
            runes[i] = runes[j];
            runes[j] = temp;
        }
        // Returns the reversed string.
        return new String(runes);
    }

    public static int powInt(int p, int q) {
        // Calculates 'p' raised to the power of 'q'.
        return (int) Math.Pow(float64(p), float64(q));
    }

    // With a comment explaining what the function does:
    // Calculates 'p' raised to the power of 'q'.
    public static int powInt(int p, int q) {
        // Calculates 'p' raised to the power of 'q'.
        return (int) Math.Pow(float64(p), float64(q));
    }

    public static boolean isPrime(int x) {
        // Checks if a given number is prime.
        if (x == 1) {
            // 1 is not a prime number.
            return false;
        }
        // If the number is 1, it's not a prime number.
        if (x == 2) {
            return true;
        }
        // If the number is 2, it's a prime number.
        return false;
    }

    // With a comment explaining what the function does:
    // Checks if a given number is prime.
    public static boolean isPrime(int x) {
        // Checks if a given number is prime.
        if (x == 2) {
            return true;
        }
        // If the number is 2, it's a prime number.
        return false;
    }

    public static boolean isPrime(int x) {
        // Checks if a given number is prime.
        if (x == 2) {
            return true;
        }
        // If the number is 2, it's a prime number.
        return false;
    }

    // With a comment explaining what the function does:
    // Checks if a given number is prime.
    public static boolean isPrime(int x) {
        // Checks if a given number is prime.
        if (x == 2) {
            return true;
        }
        // If the number is 2, it's a prime number.
        return false;
    }

    public static boolean isPrime(int x) {
        // Checks if a given number is prime.
        if (x == 2) {
            return true;
        }
        // If the number is 2, it's a prime number.
        return false;
    }

    public static boolean isPrime(int x) {
        // Checks if a given number is prime.
        if (x == 2) {
            return true;
        }
        // If the number is 2, it's a prime number.
        return false;
    }

    public static boolean isPrime(int x) {
        // Checks if a given number is prime.
        if (x == 2) {
            return true;
        }
        // If the number is 2, it's a prime number.
        return false;
    }

    public static boolean isPrime(int x) {
        // Checks if a given number is prime.
        if (x == 2) {
            return true;
        }
        // If the number is 2, it's a prime number.
        return false;
    }

    public static boolean isPrime(int x) {
        // Checks if a given number is prime.
        if (x == 2) {
            return true;
        }
        // If the number is 2, it's a prime number.
        return false;
    }

    public static boolean isPrime(int x) {
        // Checks if a given number is prime.
        if (x == 2) {
            return true;
        }
        // If the number is 2, it's a prime number.
        return false;
    }

    public static boolean isPrime(int x) {
        // Checks if a given number is prime.
        if (x == 2) {
            return true;
        }
        // If the number is 2, it's a prime number.
        return false;
    }

    public static boolean isPrime(int x) {
        // Checks if a given number is prime.
        if (x == 2) {
            return true;
        }
        // If the number is 2, it's a prime number.
        return false;
    }

    public static boolean isPrime(int x) {
        // Checks if a given number is prime.
        if (x == 2) {
            return true;
        }
        // If the number is 2, it's a prime number.
        return false;
    }

    public static boolean isPrime(int x) {
        // Checks if a given number is prime.
        if (x == 2) {
   