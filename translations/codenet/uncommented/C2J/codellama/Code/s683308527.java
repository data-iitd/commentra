#include<stdio.h>
#include<string.h>
public class Main{
  public static void main(String[] args){
    int n;
    String s;
    char[] c;
    Scanner sc=new Scanner(System.in);
    n=sc.nextInt();
    while(n-->0){
      s=sc.nextLine();
      while(s.indexOf("Hoshino")!=-1){
        s=s.replace("Hoshino","a");
      }
      System.out.println(s);
    }
  }
}
