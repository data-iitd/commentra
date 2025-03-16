import java.util.*;
public class Main {
public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
int a, b, c;
char op;
a = sc.nextInt();
op = sc.next().charAt(0);
b = sc.nextInt();
while( 1 ){
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
a = sc.nextInt();
op = sc.next().charAt(0);
b = sc.nextInt();
}
}
}
