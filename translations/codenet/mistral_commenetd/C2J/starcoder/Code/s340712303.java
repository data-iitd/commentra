
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Initialize variables
        int a, num1, num2, ans, sum = 0;
        int i, j;
        boolean[] math = new boolean[N+1];

        // Initialize math array with first element as 1
        math[0] = true;

        // Read the number of integers to be input
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of integers to be input:\n");
        num1 = sc.nextInt();

        // Read each integer and calculate its sum
        for(i=0;i<num1;i++){
            System.out.print("Enter an integer:\n");
            a = sc.nextInt();

            // Add the current integer to the sum
            sum += a;

            // Mark all the previous numbers as visited
            for(j=sum-a;j>=0;j--){
                if(math[j]==true) math[j+a] = true;
            }
        }

        // Read the number of integers to be checked
        System.out.print("Enter the number of integers to be checked:\n");
        num2 = sc.nextInt();

        // Check each integer and print the result
        for(i=0;i<num2;i++){
            System.out.print("Enter an integer to check:\n");
            ans = sc.nextInt();

            // Check if the current integer is marked as visited
            if(math[ans]==true) System.out.print("yes\n");
            else System.out.print("no\n");
        }
    }
}

