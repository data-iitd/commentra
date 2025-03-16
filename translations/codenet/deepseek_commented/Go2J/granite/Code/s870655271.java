
// This is the main method where the program starts execution.
// It reads two integers N and M from the standard input.
// Depending on the values of N and M, it calculates the number of cells in the grid.
// Finally, it prints the result to the standard output.
public class s870655271{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int ans = 0;
        // If both N and M are 1, there is only one cell, so the answer is 1.
        if (N == 1 && M == 1) {
            ans += 1;
        } else if (1 < N && 1 < M) {
            // If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
            ans += (N - 2) * (M - 2);
        } else {
            // If either N or M is 1, the number of cells is (N*M) - 2.
            ans += (N * M) - 2;
        }

        System.out.println(ans);
    }
}

/*  ----------------------------------------  */

// This method returns the maximum value among the given integers.
public static int max(int... x) {
    int res = x[0];
    for (int i = 1; i < x.length; i++) {
        res = Math.max(x[i], res);
    }
    return res;
}

// This method returns the minimum value among the given integers.
public static int min(int... x) {
    int res = x[0];
    for (int i = 1; i < x.length; i++) {
        res = Math.min(x[i], res);
    }
    return res;
}

// This method returns x raised to the power of y.
public static int pow(int x, int y) { return (int) Math.pow(x, y); }

// This method returns the absolute value of x.
public static int abs(int x) { return Math.abs(x); }

// This method returns the floor value of x.
public static int floor(int x) { return Math.floor(x); }

// This class is a list of integers that can be sorted by their absolute values.
public class s870655271{
    private int value;

    public SortBy(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    @Override
    public int compareTo(SortBy o) {
        return abs(this.value) - abs(o.getValue());
    }
}

