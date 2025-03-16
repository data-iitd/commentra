import java.util.Scanner;
 
class Main {
    public static void main(String[] args){
        // Import the Scanner class to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read an integer input from the user
        int num = sc.nextInt();
        
        // Check if the number is less than 1200
        if(num<1200)
            // Print "ABC" if the condition is true
            System.out.println("ABC");
        else
            // Print "ARC" if the condition is false
            System.out.println("ARC");
    }
}