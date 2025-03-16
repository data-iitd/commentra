public class Main {
    public static void main(String[] args) {
        // Get user input as a list of strings, split by space character, and convert each to an integer
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int a = Integer.parseInt(input[0]);
        int b = Integer.parseInt(input[1]);

        // Find the minimum value between 'a' and 'b'
        int minValue = Math.min(a, b);

        // Find the maximum value between 'a' and 'b'
        int maxValue = Math.max(a, b);

        // Print the minimum value and the average of the difference between minimum and maximum values
        System.out.println(minValue + " " + (maxValue - minValue) / 2);
    }
}
