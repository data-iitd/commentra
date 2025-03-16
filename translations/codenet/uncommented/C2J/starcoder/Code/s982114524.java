import java.util.*;
public class Main{
  public static void main(String[] args){
    int i,N,x;
    x = 0;
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();
    for(i=1; i<=N; i++)
      x += i;
    System.out.println(x);
  }
}
