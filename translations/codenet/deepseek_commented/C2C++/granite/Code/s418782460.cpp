
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int nHumanNumber=0;
    int nWaterLength=0;
    int nStart=0;
    int nStop=0;
    int nWaterLife=0;

    int nIndex=0;
    int i=0;
    int j=0;

    // Read the first line of input which contains the number of humans and the water length
    string sInput;
    getline(cin, sInput);
    stringstream ss(sInput);
    ss >> nHumanNumber >> nWaterLength;

    // Read the second line of input which contains the seconds when each human arrives
    vector<int> anComingSec;
    for (i=0;i<nHumanNumber;i++){
        int nTemp=0;
        ss >> nTemp;
        anComingSec.push_back(nTemp);
    }

    // Initialize the start time to the first human's arrival time
    nStart = anComingSec[0];

    // Process the data to calculate the water life
    while(nIndex<nHumanNumber){
        if (nIndex == nHumanNumber){
            break;
        } else {
            nStop=nStart+nWaterLength;
            if (anComingSec[nIndex]<nStop){
                while(nIndex<nHumanNumber && anComingSec[nIndex] < nStop){
                    if (nStop <= anComingSec[nIndex]+nWaterLength){
                        nStop = anComingSec[nIndex]+nWaterLength;
                        nIndex++;
                    }
                }
                if (nIndex == nHumanNumber){
                    nWaterLife = nWaterLife + (nStop-nStart);
                    break;
                }
            }
            nWaterLife = nWaterLife + (nStop-nStart);
            nStart=nStop;
            if (nStart<anComingSec[nIndex]){
                nStart=anComingSec[nIndex];
            }
        }
    }

    // Output the result which is the total water life
    cout << nWaterLife << endl;

    return 0;
}

