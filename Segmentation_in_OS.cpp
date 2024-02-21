#include <iostream>
#include <algorithm>
using namespace std;

struct SegmentInfo {
    int segmentNumber;
    int baseAddress = -1;
    int limitSize = -1;
};

bool compareByBaseAddress(SegmentInfo s1, SegmentInfo s2) {
    return s1.baseAddress < s2.baseAddress;
}

bool compareBySegmentNumber(SegmentInfo s1, SegmentInfo s2) {
    return s1.segmentNumber < s2.segmentNumber;
}

int main() {
    int totalSegments, requestedSegmentNumber, offset, physicalMemorySize;

    cout << "Enter the Physical Memory Size: ";
    cin >> physicalMemorySize;

    cout << "Enter the Number of Segments: ";
    cin >> totalSegments;
    struct SegmentInfo segmentTable[totalSegments];

    cout << "----------------Enter the Base Addresses and Limits for the Segments----------------" << endl;
    for (int i = 0; i < totalSegments; i++) {
        int baseAddress, limitSize;
        cout << endl << "Enter Base Address for Segment " << i << ": ";
        cin >> baseAddress;
        cout << "Enter Limit Size for Segment " << i << ": ";
        cin >> limitSize;

        if (baseAddress <= physicalMemorySize && (baseAddress + limitSize) <= physicalMemorySize) {
            segmentTable[i].segmentNumber = i;
            segmentTable[i].baseAddress = baseAddress;
            segmentTable[i].limitSize = limitSize;
        }
        else {
            cout << "Base Address/Limit exceeds the Physical Memory Size." << endl;
        }
    }

    cout << endl << endl << "--------------SEGMENT TABLE--------------" << endl;
    cout << "\tSEGMENT NO.\tBASE ADDRESS\t\tLIMIT SIZE" << endl;

    for (int i = 0; i < totalSegments; i++) {
        if (segmentTable[i].baseAddress != -1 && segmentTable[i].limitSize != -1) {
            cout << "\t" << segmentTable[i].segmentNumber << "\t\t" << segmentTable[i].baseAddress << "\t\t\t" << segmentTable[i].limitSize << endl;
        }
        else {
            cout << "\t" << segmentTable[i].segmentNumber << "\t\tPROCESS NOT ALLOCATED" << endl;
        }
    }

    sort(segmentTable, segmentTable + totalSegments, compareByBaseAddress);

    cout << endl << "----------------Physical Memory----------------" << endl;

    for (int i = 0; i < totalSegments; i++) {
        if (segmentTable[i].baseAddress != -1 && segmentTable[i].limitSize != -1) {
            cout << "\t-----------" << endl;
            cout << segmentTable[i].baseAddress << "\t|          |" << endl;
            cout << "\t|Segment " << segmentTable[i].segmentNumber << " |" << endl;
            cout << segmentTable[i].baseAddress + segmentTable[i].limitSize << "\t|          |" << endl;
        }
    }
    cout << "\t-----------" << endl;

    sort(segmentTable, segmentTable + totalSegments, compareBySegmentNumber);

    cout << endl << "Enter the Segment Number for logical address: ";
    cin >> requestedSegmentNumber;
    cout << endl << "Enter the Offset Value for logical address: ";
    cin >> offset;
    if (offset < 0){
        cout << "Invalid Offset Number" << endl;
        cout << "Logical Address can't be calculate." <<endl;
    }
    else{
            if (requestedSegmentNumber >= 0 && requestedSegmentNumber < totalSegments) {
        int result;
        result = segmentTable[requestedSegmentNumber].baseAddress + offset; // logical address
        if (result <= (segmentTable[requestedSegmentNumber].baseAddress + segmentTable[requestedSegmentNumber].limitSize)) {
            cout << endl << "Physical Address of the Instruction: " << result << endl;
        }
        else {
            cout << endl << "Offset value exceeds the limit..." << endl;
        }
    }
    else {
        cout << endl << "Invalid Segment Number..." << endl;
        }

    }
/*
    if (requestedSegmentNumber >= 0 && requestedSegmentNumber < totalSegments) {
        int result;
        result = segmentTable[requestedSegmentNumber].baseAddress + offset; // logical address
        if (result <= (segmentTable[requestedSegmentNumber].baseAddress + segmentTable[requestedSegmentNumber].limitSize)) {
            cout << endl << "Physical Address of the Instruction: " << result << endl;
        }
        else {
            cout << endl << "Offset value exceeds the limit..." << endl;
        }
    }
    else {
        cout << endl << "Invalid Segment Number..." << endl;
    } */

    return 0;
}


/*int S = 0;
    for (int i = 0; i < physicalSize; i++)
    {
        if (ST[S].base == i)
        {
            if (ST[S].base != -1)
            {
                int p = ST[S].limit / 2;
                cout << "\t" << i << "\t\t        " << endl;
                for (i; i < ST[S].base + ST[S].limit; i++)
                {
                    if (p == i)
                    {
                        cout << "\t\t\tSegment" << S << endl;
                    }
                    else
                    {
                        cout << "\t\t\t"
                             << "********" << endl;
                    }
                }
                cout << "\t" << i << "\t\t        " << endl;
                S++;
            }
            else
            {
                S++;
            }
        }
        else
        {
            cout << "\t\t\t"
                 << "NOT ALLOCATED" << endl;
        }
    }*/