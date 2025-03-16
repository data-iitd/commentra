public class Main {
    public static void main(String[] args) {
        // Take three integers as input from the user and store them in variables t, s, and q respectively
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        int s = scanner.nextInt();
        int q = scanner.nextInt();

        // Initialize an answer counter variable ans to 0
        int ans = 0;

        // Loop while the value of s is less than t
        while (s < t) {
            // Multiply the value of s by q and update the value of s
            s *= q;
            
            // Increment the answer counter variable ans by 1
            ans++;
        }

        // Print the final answer
        System.out.println(ans);
    }
}
