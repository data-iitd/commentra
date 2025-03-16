
import java.util.Scanner;

public class s552669377{
public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int min = 1000000;
int max = -1000000;
long sum = 0;

for (int i = 0; i < n; i++) {
int tmp = sc.nextInt();
if (min > tmp) {
min = tmp;
}
if (max < tmp) {
max = tmp;
}
sum += tmp;
}

System.out.println(min + " " + max + " " + sum);
}
}

