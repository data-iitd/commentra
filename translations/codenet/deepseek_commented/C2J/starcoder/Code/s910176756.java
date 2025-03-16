import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, b, c;
        char op;
        while(true){
            a = sc.nextInt();
            op = sc.next().charAt(0);
            b = sc.nextInt();
            if ( op == '+' ){
                c = a + b;
                System.out.println(c);
            } 
            else if ( op == '-' ){
                c = a - b;
                System.out.println(c);
            } 
            else if ( op == '*' ){
                c = a * b;
                System.out.println(c);
            } 
            else if ( op == '/' ){
                c = a / b;
                System.out.println(c);
            } 
            else {
                break;
            }
        }
    }
}
