public class Main {
    public static void main(String[] args) {
        // Read the values of S and W from a single line of input
        String[] input = System.in.readLine().split(" ");
        int S = Integer.parseInt(input[0]);
        int W = Integer.parseInt(input[1]);
        // Check if the value of W is greater than or equal to S
        // If true, print "unsafe"
        if (W >= S) {
            System.out.println("unsafe");
        } else {
            System.out.println("safe");
        }
    }
}
