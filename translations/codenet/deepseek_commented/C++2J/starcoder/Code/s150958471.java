import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Declare arrays
        // Two arrays, `train` and `bus`, are declared to store the values.
        int[] train = new int[2];
        int[] bus = new int[2];

        // Input values
        // The values for `train` and `bus` are taken from the user.
        Scanner sc = new Scanner(System.in);
        for(int i=0;i<2;i++)
            train[i] = sc.nextInt();
        for(int i=0;i<2;i++)
            bus[i] = sc.nextInt();

        // Calculate the sum
        // The code then calculates the sum of the minimum values from both arrays.
        int sum = 0;
        for(int i=0;i<2;i++)
            sum += Math.min(train[i],bus[i]);

        // Output the result
        // Finally, the result is printed to the console.
        System.out.println(sum);
    }
}
