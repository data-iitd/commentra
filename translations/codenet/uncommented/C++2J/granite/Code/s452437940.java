
import java.util.*;
import java.io.*;
public class s452437940{
public static void main(String[] args) throws IOException {
Scanner sc = new Scanner(System.in);
long long a = sc.nextLong();
long long b = sc.nextLong();
long long x = sc.nextLong();
long long s = (b/x - a/x);
if(a%x==0)s++;
System.out.println(s);
}
}
