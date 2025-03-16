#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <sstream>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for(int i=0;i<n;i++) {
            String s = sc.next();

            Set<String> st = new HashSet<String>();
            st.add(s);

            REP(j,1,s.length()){ 
                StringBuffer sb = new StringBuffer();
                REP(k,j) {
                    sb.append(s.charAt(k));
                }
                String res = sb.toString();

                StringBuffer sb2 = new StringBuffer();
                REP(k,j,s.length()) {
                    sb2.append(s.charAt(k));
                }

                String res2 = sb2.toString();

                String t = res;
                String t2 = res2;

                st.add(t+t2);
                st.add(t2+t);

                st.add(t+res2);
                st.add(res2+t);

                st.add(res+t2);
                st.add(t2+res);

                st.add(res+res2);
                st.add(res2+res);
            }

            System.out.println(st.size());
        }
    }
}

