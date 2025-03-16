#include <iostream>
using namespace std;
int main()
{
    int input[4];
    for(int i=0;i<4;i++)
        cin>>input[i];
    int position[4][2];
    position[0][0]=input[0];
    position[0][1]=input[1];
    position[1][0]=input[2];
    position[1][1]=input[3];
    position[2][0]=position[0][0]-position[1][0];
    position[2][1]=position[0][1]-position[1][1];
    position[3][0]=position[1][0]-position[2][0];
    position[3][1]=position[1][1]-position[2][1];
    if(position[0][0]==position[3][0] && position[0][1]==position[3][1])
        cout<<"OK"<<endl;
    else
        cout<<"NOK"<<endl;
    for(int i=0;i<4;i++)
        cout<<position[i][0]<<" "<<position[i][1]<<endl;
    return 0;
}
