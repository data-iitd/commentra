
import java.util.Scanner;

public class s255858499{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();

        if (a * b % 2!= 0) {
            System.out.println("Odd");
        } else {
            System.out.println("Even");
        }
    }
}

