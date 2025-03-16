public class ChocolateCalculator {
    public static void main(String[] args) {
        int N, D, X;
        int numOfChocolate;
        int counter;
        int days;
        int[] A = new int[101];
        
        // Reading input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        N = scanner.nextInt();
        D = scanner.nextInt();
        X = scanner.nextInt();
        
        // Reading values into array A
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        
        // Calculating the number of chocolates
        numOfChocolate = 0;
        for (int i = 0; i < N; i++) {
            days = 0;
            counter = 0;
            for (int j = 0;; j++) {
                days = j * A[i] + 1;
                if (days <= D) {
                    counter++;
                } else {
                    break;
                }
            }
            numOfChocolate += counter;
        }
        
        // Adding extra chocolates
        numOfChocolate += X;
        
        // Output the result
        System.out.println(numOfChocolate);
    }
}
