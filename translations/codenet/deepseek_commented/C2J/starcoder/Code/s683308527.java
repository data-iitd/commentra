import java.util.*;
public class Hoshina{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    while(n-->0){
      String s=sc.nextLine();
      while(s.indexOf("Hoshino")!=-1)s=s.substring(0,s.indexOf("Hoshino"))+"Hoshina"+s.substring(s.indexOf("Hoshino")+6);
      System.out.println(s);
    }
  }
}
