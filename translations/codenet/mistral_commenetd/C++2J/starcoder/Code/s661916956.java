
import java.util.*;

public class Main {
 public static void main(String[] args) {
 Scanner sc = new Scanner(System.in);
 int a = sc.nextInt();
 int b = sc.nextInt();
 int c = sc.nextInt();

 // Check if a is greater than b and swap if necessary
 if (a > b) {
 int temp = a;
 a = b;
 b = temp;
 }

 // Check if b is greater than c and swap if necessary
 if (b > c) {
 int temp = b;
 b = c;
 c = temp;
 }

 // Check if a is greater than b again and swap if necessary
 if (a > b) {
 int temp = a;
 a = b;
 b = temp;
 }

 // Print the sorted values of a, b, and c
 System.out.println(a + " " + b + " " + c);
 }
}
