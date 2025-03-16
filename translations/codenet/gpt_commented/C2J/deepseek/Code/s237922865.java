public class Main {
    public static void main(String[] args) {
        // Declare an integer variable to hold the number of inputs
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();

        // Initialize counters for multiples of 4 and multiples of 2
        int cnt4 = 0, cnt2 = 0;

        // Loop through each integer input
        for(int i = 0; i < n; i++) {
            int wk = scanner.nextInt();
            
            // Check if the integer is a multiple of 4
            if(wk % 4 == 0)
                cnt4++;
            // Check if the integer is a multiple of 2 (but not a multiple of 4)
            else if(wk % 2 == 0)
                cnt2++;
        }

        // Check if the total count of multiples of 4 and half the count of multiples of 2 is at least n/2
        if(cnt4 + cnt2 / 2 >= n / 2)
            // If the condition is met, print "Yes"
            System.out.println("Yes");
        else 
            // If the condition is not met, print "No"
            System.out.println("No");
    }
}
