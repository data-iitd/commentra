#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    int n;
    scanf("%d",&n);

    rep(i,n) {
        char s[1000];
        scanf("%s",s);

        set<char*> st;
        st.insert(s);

        REP(j,1,strlen(s)){ 
            char res[1000];
            rep(k,j) {
                res[k] = s[k];
            }
            res[j] = '\0';

            char res2[1000];
            REP(k,j,strlen(s)) {
                res2[k] = s[k];
            }
            res2[j] = '\0';

            char t[1000];
            strcpy(t,res);
            reverse(t,t+j);
            char t2[1000];
            strcpy(t2,res2);
            reverse(t2,t2+j);

            st.insert(strcat(t,t2));
            st.insert(strcat(t2,t));

            st.insert(strcat(t,res2));
            st.insert(strcat(res2,t));

            st.insert(strcat(res,t2));
            st.insert(strcat(t2,res));

            st.insert(strcat(res,res2));
            st.insert(strcat(res2,res));
        }

        printf("%d\n",st.size());
    }

    return 0;
}

