
import java.util.Scanner;

public class s910176756{
public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
int a = sc.nextInt();
char op = sc.next().charAt(0);
int b = sc.nextInt();
while (true) {
if (op == '+') {
int c = a + b;
System.out.println(c);
} else if (op == '-') {
int c = a - b;
System.out.println(c);
} else if (op == '*') {
int c = a * b;
System.out.println(c);
} else if (op == '/') {
int c = a / b;
System.out.println(c);
} else {
break;
}
a = sc.nextInt();
op = sc.next().charAt(0);
b = sc.nextInt();
}
}
}
