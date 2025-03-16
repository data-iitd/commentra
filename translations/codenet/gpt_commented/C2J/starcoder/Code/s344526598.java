import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        int i, j, x[] = new int[10000];

        // Initialize the array x with zeros
        for(i = 0; i < 10000; i++){
            x[i] = 0;
        }

        // Read the first input value into the array
        i = 0;
        Scanner sc = new Scanner(System.in);
        x[i] = sc.nextInt();
        
        // Continue reading input values until a zero is encountered
        while(x[i]!= 0){
            i++;
            x[i] = sc.nextInt();
        }
        
        // Print the case number and the corresponding value from the array
        for(j = 0; j < i; j++){
            System.out.printf("Case %d: %d\n", j + 1, x[j]);
        }
    }
}
