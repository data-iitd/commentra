
// Import necessary libraries
import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.util.TreeMap;
import java.util.Map.Entry;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.function.Supplier;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;
import java.util.stream.StreamSupport;

// Function to read a line of input and strip whitespace
public static String input() {
    return scanner.nextLine().trim();
}

// Function to read an integer from input
public static int INT() {
    return Integer.parseInt(input());
}

// Function to read a list of integers from input
public static List<Integer> MAP() {
    return Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
}

// Function to read a list of integers and return it as a list
public static List<Integer> LIST() {
    return Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
}

// Function to read multiple lists of integers and return them as zipped tuples
public static List<List<Integer>> ZIP(int n) {
    List<List<Integer>> lists = new ArrayList<>();
    for (int i = 0; i < n; i++) {
        lists.add(MAP());
    }
    return lists;
}

// Set the recursion limit to a high value to allow deep recursion
Thread.setDefaultUncaughtExceptionHandler((t, e) -> {
    if (e instanceof StackOverflowError) {
        System.out.println("Stack Overflow");
    }
});

// Define constants for infinity and modulo
final int INF = Integer.MAX_VALUE;
final int mod = 1000000007;

// Read the number of balls (N) and the number of operations (M)
int N = INT();
int M = INT();

// Initialize a list to represent the state of each ball (weight and radius)
List<List<Integer>> balls = new ArrayList<>();
for (int i = 0; i < N; i++) {
    balls.add(new ArrayList<>(Arrays.asList(1, 0)));
}
balls.get(0).set(1, 1);  // Set the first ball's state

// Process each operation
for (int i = 0; i < M; i++) {
    int x = INT();
    int y = INT();
    int w_x = balls.get(x - 1).get(0);  // Get the state of ball x
    int r_x = balls.get(x - 1).get(1);
    int w_y = balls.get(y - 1).get(0);  // Get the state of ball y
    int r_y = balls.get(y - 1).get(1);
    
    // Update the states of the balls based on their weights and radii
    if (w_x >= 1 && r_x >= 1) {
        balls.get(x - 1).set(0, w_x - 1);  // Decrease weight of ball x
        balls.get(y - 1).set(1, r_y + 1);  // Increase radius of ball y
    } else if (w_x == 0) {
        balls.get(x - 1).set(1, r_x - 1);  // Decrease radius of ball x
        balls.get(y - 1).set(1, r_y + 1);  // Increase radius of ball y
    } else {
        balls.get(x - 1).set(0, w_x - 1);  // Decrease weight of ball x
        balls.get(y - 1).set(0, w_y + 1);  // Increase weight of ball y
    }
}

// Calculate the number of balls with a non-zero radius
int ans = 0;
for (int i = 0; i < N; i++) {
    if (balls.get(i).get(1) != 0) {  // Check if the radius of the ball is non-zero
        ans++;  // Increment the count of balls with non-zero radius
    }
}

// Print the final count of balls with non-zero radius
System.out.println(ans);

