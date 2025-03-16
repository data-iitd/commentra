
import java.util.*;
import java.io.*;
class s683308527{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    while(n-->0){
      String s=sc.nextLine();
      while(s.indexOf("Hoshino")>=0)
        s=s.substring(0,s.indexOf("Hoshino"))+"a"+s.substring(s.indexOf("Hoshino")+7);
      System.out.println(s);
    }
  }
}
//END-OF-CODE