import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner input = new Scanner(System.in);
    int a,b,c;
    a = input.nextInt();
    b = input.nextInt();
    c = input.nextInt();
    if(a<b && b<c){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}
