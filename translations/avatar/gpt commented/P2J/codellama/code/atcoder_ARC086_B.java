
import java.io.*;
import java.util.*;

// Set the recursion limit to a higher value to handle deep recursions
Thread.setStackSize(10 * 1024 * 1024);

// Function to read a line of input and strip the newline character
public static String input() {
    return new BufferedReader(new InputStreamReader(System.in)).readLine().trim();
}

// Define a modulo constant for later use
final int mod = 1000000007;

// Function to read an integer from input
public static int I() {
    return Integer.parseInt(input());
}

// Function to read a list of integers from input
public static int[] II() {
    return Arrays.stream(input().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// Function to read a list of integers and return it as a list
public static List<Integer> III() {
    return Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
}

// Function to read a specific format of input based on the number of elements
public static List<List<Integer>> Line(int N, int num) {
    // If N is less than or equal to 0, return an empty list
    if (N <= 0) {
        return new ArrayList<List<Integer>>() {{
            add(new ArrayList<>());
        }};
    }
    // If num is 1, read N integers and return them as a list
    else if (num == 1) {
        return new ArrayList<List<Integer>>() {{
            for (int i = 0; i < N; i++) {
                add(new ArrayList<Integer>() {{
                    add(I());
                }});
            }
        }};
    }
    // Otherwise, read N tuples of integers and return them as a transposed list
    else {
        List<List<Integer>> read_all = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            read_all.add(new ArrayList<Integer>() {{
                addAll(Arrays.asList(II()));
            }});
        }
        return read_all.stream().map(list -> list.stream().map(i -> i).collect(Collectors.toList())).collect(Collectors.toList());
    }
}

// Function to determine the sign of a number
public static int my_sign(int x) {
    return (x > 0) - (x < 0);
}

// Read the number of elements
int N = I();

// Read the list of integers
List<Integer> a = III();

// Initialize variables to track the maximum absolute value, its sign, and index
int max_val = 0;
int max_sign = 0;
int max_index = -1;

// Loop through the list to find the maximum absolute value and its properties
for (int i = 0; i < N; i++) {
    if (Math.abs(a.get(i)) > max_val) {
        max_val = Math.abs(a.get(i));
        max_sign = my_sign(a.get(i));
        max_index = i;
    }
}

// Check the sign of the maximum value and print results accordingly
if (max_sign == 0) {
    // If the maximum sign is zero, print 0
    System.out.println(0);
} else if (max_sign == 1) {
    // If the maximum sign is positive, print the number of operations and the operations
    System.out.println(2 * N - 1);
    for (int i = 0; i < N; i++) {
        System.out.println(max_index + 1 + " " + (i + 1));
    }
    for (int i = 0; i < N - 1; i++) {
        System.out.println((i + 1) + " " + (i + 2));
    }
} else {
    // If the maximum sign is negative, print the number of operations and the operations
    System.out.println(2 * N - 1);
    for (int i = 0; i < N; i++) {
        System.out.println(max_index + 1 + " " + (i + 1));
    }
    for (int i = 1; i < N; i++) {
        System.out.println((i + 1) + " " + i);
    }
}

