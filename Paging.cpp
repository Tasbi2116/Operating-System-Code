#include <bits\stdc++.h>
using namespace std;
struct Ptable
{
    int Pnumber;
    int Fnumber;
};

struct Page
{
    int index;
    int process;
};

struct frame
{
    int index;
    int process;
};

int main()
{

    int logicalSize, pageSize, pageNumber, physicalSize, frameNumber;
    cout << "Enter the Logical Size of the Memory:: ";
    cin >> logicalSize;

    cout << "Enter the Physical Size of the Memory:: ";
    cin >> physicalSize;

    cout << "Enter the Page Size:: ";
    cin >> pageSize;

    pageNumber = logicalSize / pageSize;
    frameNumber = physicalSize / pageSize;
    
    struct Page P[logicalSize];
    struct frame F[physicalSize];


    for(int i=0; i<physicalSize; i++)
    {
        F[i].index = i;
        F[i].process = -9999;
    }
    
    
    for (int j = 0; j < logicalSize; j++)
    {
        P[j].index = j;
        P[j].process = j+1;
        
    }

    cout << endl;

    struct Ptable PT[pageNumber];

    cout << endl
         << "****************Enter Page Number and Frame Number for Page Table****************" << endl;
    cout << endl
         << "Enter Frame Number -1 for No Frame With Respect to Page" << endl;

    for (int i = 0; i < pageNumber; i++)
    {
        cout << "Page Number:: ";
        cin >> PT[i].Pnumber;
        cout << "Frame Number:: ";
        cin >> PT[i].Fnumber;
        int f = PT[i].Fnumber;

        if(f > (frameNumber-1))
        {
            cout << "Not Enough Physical Space." << endl;
            PT[i].Fnumber = -1;
        }
        cout << endl;
    }


    for(int i=0; i<pageNumber; i++)
    {
        if(PT[i].Fnumber != -1)
        {
            int f = PT[i].Fnumber;
            int j = (pageSize * f);
            int n = j + pageSize;
            int p = i * pageSize;

            for(j; j < n; j++)
            {
                F[j].process = P[p++].process;
            }
        } 
    }

    cout << endl
         << "****************Logical Memory****************" << endl;

    cout << "\tADDRESS\t\t\t"
         << "INSTRUCTION";
    cout << endl;

    int cnt = pageSize;
    for (int i = 0; i < logicalSize; i++)
    {
        if (i == cnt)
        {
            cout << "-----------------------------------------" << endl;
            cnt = cnt + pageSize;
        }
        cout << "\t" << P[i].index << "\t\t\t" << P[i].process << endl;
    }

    cout << endl
         << "****************Page Table****************" << endl;
    cout << "\tPAGE\t\t\t"
         << "FRAME";
    cout << endl;
    for (int i = 0; i < pageNumber; i++)
    {

        cout << "\t" << PT[i].Pnumber << "\t\t\t";
        if(PT[i].Fnumber == -1) 
        {
            cout << "Not Loaded";
        }
        else
        {
            cout << PT[i].Fnumber;
        }
            
        cout << endl;
    }

    cout << endl << "****************Physical Memory****************" << endl;
    cout << "\tADDRESS\t\t\t"
         << "INSTRUCTION";
    cout << endl;

    cnt = pageSize;
    for (int i = 0; i < physicalSize; i++)
    {
        if (i == cnt)
        {
            cout << "-----------------------------------------" << endl;
            cnt = cnt + pageSize;
        }
        cout << "\t" << F[i].index << "\t\t\t";
        if(F[i].process == -9999)
        {
            cout << " " << endl;
        }
        else
        {
             cout << F[i].process << endl;
        }
    }

    cout << endl;
    int p;
    cout << "Enter the Instruction to Find Out it's Physical Address:: ";
    cin >> p;
    cout << endl;

    int index, flag = 0;
    for (int i = 0; i < logicalSize; i++)
    {
        
        if (P[i].process == p)
        {
            index = P[i].index;
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        int pNo = index / pageSize;
        int offset = index % pageSize;
        int fNo, cnt = 0;

        for (int i = 0; i < pageNumber; i++)
        {
            if ((pNo == PT[i].Pnumber) && (PT[i].Fnumber != -1))
            {
                fNo = PT[i].Fnumber;
                cnt = 1;
                break;
            }
            
        }

        if (cnt == 1)
        {
            int pLoc = (fNo * pageSize) + offset;

            cout << "\nThe Physical Address of \'" << p << "\' is " << pLoc << endl << endl;
        }

        else
        {
            cout << "The Page Where the Process is, not Loaded to the Physical Memory.." << endl << endl;
            return 0;
        }
    }
    else
    {
        cout << endl
             << "Invalid Reference..." << endl << endl;
    }
}
