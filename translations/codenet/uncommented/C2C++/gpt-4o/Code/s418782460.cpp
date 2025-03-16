#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#define MAX_STRING 30
#define MAX_LINE 2000000
#define MAX_HUMAN 200000

std::string sLongInputLine(MAX_LINE + 1, '\0');
std::vector<int> anComingSec;

int main() {
    std::string sInput;
    int nHumanNumber = 0;
    int nNextHumanIndex = 0;
    int nWaterLength = 0;
    int nWaterLife = 0;
    int nStart = 0;
    int nStop = 0;

    // read line 1
    std::getline(std::cin, sInput);
    std::istringstream iss(sInput);
    iss >> nHumanNumber >> nWaterLength;

    std::getline(std::cin, sLongInputLine);
    std::istringstream issLong(sLongInputLine);
    anComingSec.resize(nHumanNumber);
    for (int i = 0; i < nHumanNumber; i++) {
        issLong >> anComingSec[i];
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
                    nWaterLife += (nStop - nStart);
                    break;
                }
            }
            nWaterLife += (nStop - nStart);
            nStart = nStop;
            if (nStart < anComingSec[nNextHumanIndex]) {
                nStart = anComingSec[nNextHumanIndex];
            }
        }
    }
    std::cout << nWaterLife << std::endl;

    return 0;
}

// <END-OF-CODE>
