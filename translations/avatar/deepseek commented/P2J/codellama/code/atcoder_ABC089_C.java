
import java.util.*;
import java.io.*;
import java.math.*;

// Function to read a single line of input
public static String input() {
    return new BufferedReader(new InputStreamReader(System.in)).readLine().trim();
}

// Function to convert input to an integer
public static int INT() {
    return Integer.parseInt(input());
}

// Function to read a map of integers
public static Map<String, Integer> MAP() {
    Map<String, Integer> map = new HashMap<>();
    String[] tokens = input().split(" ");
    for (int i = 0; i < tokens.length; i += 2) {
        map.put(tokens[i], Integer.parseInt(tokens[i + 1]));
    }
    return map;
}

// Function to convert input to a list of integers
public static List<Integer> LIST() {
    return Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
}

// Function to create combinations from a list of tuples
public static List<List<Integer>> ZIP(int n) {
    List<List<Integer>> lists = new ArrayList<>();
    for (int i = 0; i < n; i++) {
        lists.add(LIST());
    }
    List<List<Integer>> result = new ArrayList<>();
    for (int i = 0; i < lists.get(0).size(); i++) {
        List<Integer> temp = new ArrayList<>();
        for (int j = 0; j < lists.size(); j++) {
            temp.add(lists.get(j).get(i));
        }
        result.add(temp);
    }
    return result;
}

// Set recursion limit to prevent recursion errors
public static void setRecursionLimit(int limit) {
    StackTraceElement[] stackTrace = Thread.currentThread().getStackTrace();
    StackTraceElement main = stackTrace[stackTrace.length - 1];
    if (main.getClassName().equals(Main.class.getName())) {
        Thread.currentThread().setStackTrace(Arrays.copyOf(stackTrace, stackTrace.length - 1));
        System.setProperty("stacktrace.limit", String.valueOf(limit));
    }
}

// Define constants
public static final int INF = Integer.MAX_VALUE;
public static final int mod = 1000000007;

// Import java.util.Arrays for faster I/O
import java.util.Arrays;

// Import java.util.stream for faster I/O
import java.util.stream.*;

// Import java.util.function for faster I/O
import java.util.function.*;

// Import java.util.regex for faster I/O
import java.util.regex.*;

// Import java.util.Map for faster I/O
import java.util.Map;

// Import java.util.HashMap for faster I/O
import java.util.HashMap;

// Import java.util.Set for faster I/O
import java.util.Set;

// Import java.util.HashSet for faster I/O
import java.util.HashSet;

// Import java.util.List for faster I/O
import java.util.List;

// Import java.util.ArrayList for faster I/O
import java.util.ArrayList;

// Import java.util.LinkedList for faster I/O
import java.util.LinkedList;

// Import java.util.Queue for faster I/O
import java.util.Queue;

// Import java.util.PriorityQueue for faster I/O
import java.util.PriorityQueue;

// Import java.util.Stack for faster I/O
import java.util.Stack;

// Import java.util.Scanner for faster I/O
import java.util.Scanner;

// Import java.util.Random for faster I/O
import java.util.Random;

// Import java.util.BitSet for faster I/O
import java.util.BitSet;

// Import java.util.Collections for faster I/O
import java.util.Collections;

// Import java.util.Comparator for faster I/O
import java.util.Comparator;

// Import java.util.function.Function for faster I/O
import java.util.function.Function;

// Import java.util.function.BiFunction for faster I/O
import java.util.function.BiFunction;

// Import java.util.function.BinaryOperator for faster I/O
import java.util.function.BinaryOperator;

// Import java.util.function.UnaryOperator for faster I/O
import java.util.function.UnaryOperator;

// Import java.util.function.Predicate for faster I/O
import java.util.function.Predicate;

// Import java.util.function.Supplier for faster I/O
import java.util.function.Supplier;

// Import java.util.stream.Collectors for faster I/O
import java.util.stream.Collectors;

// Import java.util.stream.IntStream for faster I/O
import java.util.stream.IntStream;

// Import java.util.stream.LongStream for faster I/O
import java.util.stream.LongStream;

// Import java.util.stream.DoubleStream for faster I/O
import java.util.stream.DoubleStream;

// Import java.util.stream.Stream for faster I/O
import java.util.stream.Stream;

// Import java.util.stream.Collectors for faster I/O
import java.util.stream.Collectors;

// Import java.util.stream.IntStream for faster I/O
import java.util.stream.IntStream;

// Import java.util.stream.LongStream for faster I/O
import java.util.stream.LongStream;

// Import java.util.stream.DoubleStream for faster I/O
import java.util.stream.DoubleStream;

// Import java.util.stream.Stream for faster I/O
import java.util.stream.Stream;

// Import java.util.stream.Collectors for faster I/O
import java.util.stream.Collectors;

// Import java.util.stream.IntStream for faster I/O
import java.util.stream.IntStream;

// Import java.util.stream.LongStream for faster I/O
import java.util.stream.LongStream;

// Import java.util.stream.DoubleStream for faster I/O
import java.util.stream.DoubleStream;

// Import java.util.stream.Stream for faster I/O
import java.util.stream.Stream;

// Import java.util.stream.Collectors for faster I/O
import java.util.stream.Collectors;

// Import java.util.stream.IntStream for faster I/O
import java.util.stream.IntStream;

// Import java.util.stream.LongStream for faster I/O
import java.util.stream.LongStream;

// Import java.util.stream.DoubleStream for faster I/O
import java.util.stream.DoubleStream;

// Import java.util.stream.Stream for faster I/O
import java.util.stream.Stream;

// Import java.util.stream.Collectors for faster I/O
import java.util.stream.Collectors;

// Import java.util.stream.IntStream for faster I/O
import java.util.stream.IntStream;

// Import java.util.stream.LongStream for faster I/O
import java.util.stream.LongStream;

// Import java.util.stream.DoubleStream for faster I/O
import java.util.stream.DoubleStream;

// Import java.util.stream.Stream for faster I/O
import java.util.stream.Stream;

// Import java.util.stream.Collectors for faster I/O
import java.util.stream.Collectors;

// Import java.util.stream.IntStream for faster I/O
import java.util.stream.IntStream;

// Import java.util.stream.LongStream for faster I/O
import java.util.stream.LongStream;

// Import java.util.stream.DoubleStream for faster I/O
import java.util.stream.DoubleStream;

// Import java.util.stream.Stream for faster I/O
import java.util.stream.Stream;

// Import java.util.stream.Collectors for faster I/O
import java.util.stream.Collectors;

// Import java.util.stream.IntStream for faster I/O
import java.util.stream.IntStream;

// Import java.util.stream.LongStream for faster I/O
import java.util.stream.LongStream;

// Import java.util.stream.DoubleStream for faster I/O
import java.util.stream.DoubleStream;

// Import java.util.stream.Stream for faster I/O
import java.util.stream.Stream;

// Import java.util.stream.Collectors for faster I/O
import java.util.stream.Collectors;

// Import java.util.stream.IntStream for faster I/O
import java.util.stream.IntStream;

// Import java.util.stream.LongStream for faster I/O
import java.util.stream.LongStream;

// Import java.util.stream.DoubleStream for faster I/O
import java.util.stream.DoubleStream;

// Import java.util.stream.Stream for faster I/O
import java.util.stream.Stream;

// Import java.util.stream.Collectors for faster I/O
import java.util.stream.Collectors;

// Import java.util.stream.IntStream for faster I/O
import java.util.stream.IntStream;

// Import java.util.stream.LongStream for faster I/O
import java.util.stream.LongStream;

// Import java.util.stream.DoubleStream for faster I/O
import java.util.stream.DoubleStream;

// Import java.util.stream.Stream for faster I/O
import java.util.stream.Stream;

// Import java.util.stream.Collectors for faster I/O
import java.util.stream.Collectors;

// Import java.util.stream.IntStream for faster I/O
import java.util.stream.IntStream;

// Import java.util.stream.LongStream for faster I/O
import java.util.stream.LongStream;

// Import java.util.stream.DoubleStream for faster I/O
import java.util.stream.DoubleStream;

// Import java.util.stream.Stream for faster I/O
import java.util.stream.Stream;

// Import java.util.stream.Collectors for faster I/O
import java.util.stream.Collectors;

// Import java.util.stream.IntStream for faster I/O
import java.util.stream.IntStream;

// Import java.util.stream.LongStream for faster I/O
import java.util.stream.LongStream;

// Import java.util.stream.DoubleStream for faster I/O
import java.util.stream.DoubleStream;

// Import java.util.stream.Stream for faster I/O
import java.util.stream.Stream;

// Import java.util.stream.Collectors for faster I/O
import java.util.stream.Collectors;

// Import java.util.stream.IntStream for faster I/O
import java.util.stream.IntStream;

// Import java.util.stream.LongStream for faster I/O
import java.util.stream.LongStream;

// Import java.util.stream.DoubleStream for faster I/O
import java.util.stream.DoubleStream;

// Import java.util.stream.Stream for faster I/O
import java.util.stream.Stream;

// Import java.util.stream.Collectors for faster I/O
import java.util.stream.Collectors;

// Import java.util.stream.IntStream for faster I/O
import java.util.stream.IntStream;

// Import java.util.stream.LongStream for faster I/O
import java.util.stream.LongStream;

// Import java.util.stream.DoubleStream for faster I/O
import java.util.stream.DoubleStream;

// Import java.util.stream.Stream for faster I/O
import java.util.stream.Stream;

// Import java.util.stream.Collectors for faster I/O
import java.util.stream.Collectors;

// Import java.util.stream.IntStream for faster I/O
import java.util.stream.IntStream;

// Import java.util.stream.LongStream for faster I/O
import java.util.stream.LongStream;

// Import java.util.stream.DoubleStream for faster I/O
import java.util.stream.DoubleStream;

// Import java.util.s