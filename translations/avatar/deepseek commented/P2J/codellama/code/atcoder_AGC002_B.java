
import java.util.*;
import java.io.*;
import java.math.*;

// Function to read a single line of input from stdin
static String input() {
    Scanner sc = new Scanner(System.in);
    return sc.nextLine();
}

// Function to convert a single input line to an integer
static int INT() {
    return Integer.parseInt(input());
}

// Function to read multiple integers from a single line of input
static int[] MAP() {
    return Arrays.stream(input().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// Function to read a list of integers from a single line of input
static List<Integer> LIST() {
    return Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
}

// Function to read multiple lines of input and return them as a list of tuples
static List<List<Integer>> ZIP(int n) {
    List<List<Integer>> list = new ArrayList<>();
    for (int i = 0; i < n; i++) {
        list.add(LIST());
    }
    return list;
}

// Setting the recursion limit to a higher value to avoid recursion errors
static {
    Thread.setDefaultUncaughtExceptionHandler((t, e) -> {
        if (e instanceof StackOverflowError) {
            System.out.println("Stack Overflow");
        }
    });
}

// Defining a constant for infinity
static final int INF = Integer.MAX_VALUE;

// Defining a constant for modulo operation
static final int mod = 1000000007;

// Reading the number of balls (N) and the number of operations (M)
static int N, M;

// Initializing the list of balls with pairs [white pieces, red pieces]
static List<List<Integer>> balls = new ArrayList<>();

// Special initialization for the first ball
static {
    balls.add(Arrays.asList(0, 1));
    for (int i = 1; i < N; i++) {
        balls.add(Arrays.asList(1, 0));
    }
}

// Loop to process each operation
static void process() {
    for (int i = 0; i < M; i++) {
        int x = INT();
        int y = INT();
        int w_x = balls.get(x - 1).get(0);
        int r_x = balls.get(x - 1).get(1);
        int w_y = balls.get(y - 1).get(0);
        int r_y = balls.get(y - 1).get(1);

        // Swapping the balls if possible
        if (w_x >= 1 && r_x >= 1) {
            balls.get(x - 1).set(0, w_x - 1);
            balls.get(y - 1).set(1, r_y + 1);
        } else if (w_x == 0) {
            balls.get(x - 1).set(1, r_x - 1);
            balls.get(y - 1).set(1, r_y + 1);
        } else {
            balls.get(x - 1).set(0, w_x - 1);
            balls.get(y - 1).set(0, w_y + 1);
        }
    }
}

// Counting the number of balls with at least one red or white piece
static int count() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (balls.get(i).get(1) > 0) {
            ans++;
        }
    }
    return ans;
}

// Main function
public static void main(String[] args) {
    N = INT();
    M = INT();
    process();
    System.out.println(count());
}

