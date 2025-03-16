import java.util.Scanner; // Importing the Scanner class for input operations

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input
        
        while(true){ // Starting an infinite loop
            int a = sc.nextInt(); // Reading the first integer input
            String op = sc.next(); // Reading the operation input
            int b = sc.nextInt(); // Reading the second integer input
            
            if(op.equals("?")) break; // If the operation is "?", break the loop
            if(op.equals("+")) System.out.println(a+b); // If the operation is "+", print the sum
            if(op.equals("-")) System.out.println(a-b); // If the operation is "-", print the difference
            if(op.equals("*")) System.out.println(a*b); // If the operation is "*", print the product
            if(op.equals("/")) System.out.println(a/b); // If the operation is "/", print the quotient
        }
    }
}
