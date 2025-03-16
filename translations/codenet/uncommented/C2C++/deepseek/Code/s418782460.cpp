#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_STRING = 30;
const int MAX_LINE = 2000000;
const int MAX_HUMAN = 200000;

string sLongInputLine = "";
int anComingSec[MAX_HUMAN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string sInput = "";
    string* psWord = nullptr;
    string* psInput = nullptr;

    int nHumanNumber = 0;
    int nNextHumanIndex = 0;
    int nWaterLength = 0;
    int nWaterLife = 0;
    int nStart = 0;
    int nStop = 0;

    int nIndex = 0;
    int i = 0;
    int j = 0;

    // read line 1
    getline(cin, sInput);
    psInput = &sInput;
    psWord = strtok((char*)psInput->c_str(), " ");
    nHumanNumber = stoi(*psWord);
    psWord = strtok(nullptr, " ");
    nWaterLength = stoi(*psWord);

    getline(cin, sLongInputLine);
    psInput = &sLongInputLine;
    psWord = strtok((char*)psInput->c_str(), " ");
    for (i = 0; i < nHumanNumber; i++) {
        anComingSec[i] = stoi(*psWord);
        psWord = strtok(nullptr, " ");
    }

    nStart = anComingSec[0];

    while (nNextHumanIndex < nHumanNumber) {
        if (nNextHumanIndex == nHumanNumber) {
            break;
        } else {
            nStop = nStart + nWaterLength;
            if (anComingSec[nNextHumanIndex] < nStop) {
                while (nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop) {
                    if (nStop <= anComingSec[nNextHumanIndex] + nWaterLength) {
                        nStop = anComingSec[nNextHumanIndex] + nWaterLength;
                        nNextHumanIndex++;
                    }
                }
                if (nNextHumanIndex == nHumanNumber) {
                    nWaterLife = nWaterLife + (nStop - nStart);
                    break;
                }
            }
            nWaterLife = nWaterLife + (nStop - nStart);
            nStart = nStop;
            if (nStart < anComingSec[nNextHumanIndex]) {
                nStart = anComingSec[nNextHumanIndex];
            }
        }
    }
    cout << nWaterLife << '\n';

    return 0;
}
