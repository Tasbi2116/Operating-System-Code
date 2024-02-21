#include <bits/stdc++.h>
using namespace std;
int R[100][100];
int C[100][100];
int need[100][100];
int A[100];
int n, r;

void input()
{
    int i, j;
    cout << "Enter the no of Processes:: \t";
    cin >> n;
    cout << "Enter the no of Resource:: \t";
    cin >> r;
    cout << "Enter the Request Matrix:: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            cin >> R[i][j];
        }
    }
    cout << "Enter the Allocation Matrix:: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            cin >> C[i][j];
        }
    }
    cout << "Enter the Available Resources:: " << endl;
    for (j = 0; j < r; j++)
    {
        cin >> A[j];
    }
}
void show()
{
    int i, j;
    cout << "Process\t Allocation\t\tRequest\t\tAvailable\t";
    for (i = 0; i < n; i++)
    {
        cout << "\nP" << i + 1 << "\t ";
        for (j = 0; j < r; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << "\t\t";
        for (j = 0; j < r; j++)
        {
            cout << R[i][j] << " ";
        }
        cout << "\t ";
        if (i == 0)
        {
            for (j = 0; j < r; j++)
                cout << A[j] << " ";
        }
    }
}
void cal()
{
    int finish[100], temp, need[100][100], flag = 1, k, c1 = 0;
    int dead[100];
    int safe[100];
    int i, j;
    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }
    //find need matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            need[i][j] = R[i][j] - C[i][j];
        }
    }
    while (flag)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            int c = 0;
            for (j = 0; j < r; j++)
            {
                if ((finish[i] == 0) && (need[i][j] <= A[j]))
                {
                    c++;
                    if (c == r)
                    {
                        for (k = 0; k < r; k++)
                        {
                            A[k] += C[i][j];
                            finish[i] = 1;
                            flag = 1;
                        }
                        //cout<<"\nP%d",i;
                        if (finish[i] == 1)
                        {
                            i = n;
                        }
                    }
                }
            }
        }
    }
    j = 0;
    flag = 0;
    for (i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            dead[j] = i;
            j++;
            flag = 1;
        }
    }
    if (flag == 1)
    {
        cout << "\n\nSystem is in Deadlock." << endl;
        /*for (i = 0; i < n; i++)
        {
            cout << "P" << dead[i] << "\t";
        }*/
    }
    else
    {
        cout << "\nNo Deadlock Occur";
    }
}
int main()
{
    int i, j;
    cout << "********** Deadlock Detection Algorithm ************\n";
    input();
    show();
    cal();
    return 0;
}
