import java.util.Scanner;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int hcell = sc.nextInt();
    int wcell = sc.nextInt();
    int hpaint = sc.nextInt();
    int wpaint = sc.nextInt();
    int nblack = (wcell*hpaint) + (hcell*wpaint) - (hpaint * wpaint);
    int nwhite = (hcell*wcell) - nblack;
    System.out.println(nwhite);
  }
}
