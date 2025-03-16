public class task4 {
    public static void main(String[] args) {
        // Take input from the user and split it into three variables A, B, and n
        String[] input = new Scanner(System.in).nextLine().split(" ");
        int A = Integer.parseInt(input[0]);
        int B = Integer.parseInt(input[1]);
        int n = Integer.parseInt(input[2]);

        // Iterate through a range of possible values for X from -1000 to 1000
        for (int X = -1000; X <= 1000; X++) {
            // Check if the equation A * (X ** n) equals B
            if (A * (int) Math.pow(X, n) == B) {
                // If a solution is found, return the value of X
                System.out.println(X);
                return;
            }
        }
        // If no solution is found in the range, return a message indicating no solution
        System.out.println("No solution");
    }
}
