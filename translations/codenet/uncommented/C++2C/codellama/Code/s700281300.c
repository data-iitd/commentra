#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

typedef long long ll;

int main() {
    int n;
    scanf("%d",&n);

    rep(i,n) {
        char s[100000];
        scanf("%s",s);

        int st[100000];
        st[0] = s[0];
        int st_size = 1;

        REP(j,1,strlen(s)){ 
            char res[100000];
            REP(k,j) {
                res[k] = s[k];
            }
            res[j] = '\0';

            char res2[100000];
            REP(k,j,strlen(s)){ 
                res2[k-j] = s[k];
            }
            res2[strlen(s)-j] = '\0';

            char t[100000];
            strcpy(t,res);
            reverse(res);
            char t2[100000];
            strcpy(t2,res2);
            reverse(res2);

            bool found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],t) == 0 || strcmp(st[k],t2) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = t;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],t2) == 0 || strcmp(st[k],t) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = t2;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res) == 0 || strcmp(st[k],res2) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res2) == 0 || strcmp(st[k],res) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res2;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res) == 0 || strcmp(st[k],res2) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res2) == 0 || strcmp(st[k],res) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res2;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res) == 0 || strcmp(st[k],res2) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res2) == 0 || strcmp(st[k],res) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res2;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res) == 0 || strcmp(st[k],res2) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res2) == 0 || strcmp(st[k],res) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res2;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res) == 0 || strcmp(st[k],res2) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res2) == 0 || strcmp(st[k],res) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res2;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res) == 0 || strcmp(st[k],res2) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res2) == 0 || strcmp(st[k],res) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res2;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res) == 0 || strcmp(st[k],res2) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res2) == 0 || strcmp(st[k],res) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res2;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res) == 0 || strcmp(st[k],res2) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res2) == 0 || strcmp(st[k],res) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res2;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res) == 0 || strcmp(st[k],res2) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res2) == 0 || strcmp(st[k],res) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res2;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res) == 0 || strcmp(st[k],res2) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res2) == 0 || strcmp(st[k],res) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res2;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res) == 0 || strcmp(st[k],res2) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res2) == 0 || strcmp(st[k],res) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res2;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res) == 0 || strcmp(st[k],res2) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res2) == 0 || strcmp(st[k],res) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res2;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res) == 0 || strcmp(st[k],res2) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {
                if(strcmp(st[k],res2) == 0 || strcmp(st[k],res) == 0) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                st[st_size] = res2;
                st_size++;
            }

            found = false;
            REP(k,0,st_size) {