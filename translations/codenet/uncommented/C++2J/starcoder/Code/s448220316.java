
import java.util.*;
import java.io.*;
public class Main{
	public static void main(String[] args) throws Exception{
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt(),m=cin.nextInt();
		int[] fa=new int[100005],v=new int[200005];
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			int l=cin.nextInt(),r=cin.nextInt(),vi=cin.nextInt();
			int li=get(l,fa,v),ri=get(r,fa,v);
			if(li!=ri){
				v[ri]=vi-v[r]+v[l];
				fa[ri]=li;
			}else{
				if(v[r]-v[l]!=vi){
					System.out.println("No");
					return;
				}
			}
		}
		System.out.println("Yes");
	}
	public static int get(int x,int[] fa,int[] v){
		if(x==fa[x])return x;
		int f=get(fa[x],fa,v);
		v[x]+=v[fa[x]];
		return fa[x]=f;
	}
}

