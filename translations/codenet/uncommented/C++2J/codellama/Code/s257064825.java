#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cmath>
using namespace std;
public class Main {
	public static void main(String[] args) {
		String str;
		int sum=0;
		cin>>str;
		for(char x:str)
		{
			sum+=(x-48);
		}
		if(sum%9==0)
		{
			System.out.println("Yes");
		}
		else
			System.out.println("No");
	}
}
