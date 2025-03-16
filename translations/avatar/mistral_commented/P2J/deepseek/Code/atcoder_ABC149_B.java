public class CookieDistribution {
    public static void main(String[] args) {
        // Read input and store it in an array
        int[] cookies = Arrays.stream(System.console().readLine().split(" "))
                             .mapToInt(Integer::parseInt)
                             .toArray();

        // Calculate the difference between the number of cookies given to the first and second child
        int leftOver = cookies[0] - cookies[2];

        // Set the 'takahashi' variable to the maximum value between 0 and the 'leftOver' variable
        int takahashi = Math.max(0, leftOver);

        // Print the result using string concatenation
        System.out.println(takahashi + " " +
                           (leftOver > 0 ? cookies[1] : Math.max(0, cookies[1] - Math.abs(leftOver))));
    }
}
