public class CardGame {
    public static void main(String[] args) {
        // Step 1: Read three integers from input.
        int[] c = new int[3];
        
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (scanner.hasNextInt()) {
            c[0] = scanner.nextInt();
            c[1] = scanner.nextInt();
            c[2] = scanner.nextInt();
            
            // Step 2: Initialize an array to keep track of the cards.
            int[] card = new int[10];
            int count = 0;
            
            // Calculate the sum of the two known cards.
            int sum = c[0] + c[1];
            
            // Step 3: Loop through the cards and mark them in the array.
            for (int i = 0; i < 3; i++) {
                card[c[i] - 1] = 1;
            }
            
            // Step 4: Check which cards can be added to the sum without exceeding 20.
            for (int i = 0; i < 10; i++) {
                if (card[i] == 0 && sum + i + 1 <= 20) {
                    count++;
                }
            }
            
            // Step 5: Determine if at least 4 such cards exist.
            if (count >= 4) {
                // Step 6: Print "YES" if such cards exist.
                System.out.println("YES");
            } else {
                // Step 7: Print "NO" otherwise.
                System.out.println("NO");
            }
        }
        
        scanner.close();
    }
}
