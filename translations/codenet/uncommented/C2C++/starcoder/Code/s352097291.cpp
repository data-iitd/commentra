#include <iostream>
#include <string>
using namespace std;
int main(){
    string c,ans;
    cin>>c;
    for(int i=0;c[i]!='\0';i++){
        if(c[i]!='B')
            ans+=c[i];
        else
            ans.pop_back();
    }
    cout<<ans<<endl;
}
