#include <bits/stdc++.h>
using namespace std;

int choice, stringLength, numPages;
char referenceString[1000];

void Input()
{
    cout << "Enter the number of pages: ";
    cin >> numPages;
    cout << "Enter the reference string without any space: ";
    cin >> referenceString;
    stringLength = strlen(referenceString);
}

void OptimalAlgorithm()
{
    int temp[10], pageFound, emptySlot, replacePage, i, j, k, position, max, pageFaults = 0;

    char memory[numPages] = {'#'};
    int referenceStringLength = strlen(referenceString);

    for (i = 0; i < referenceStringLength; i++)
    {
        pageFound = emptySlot = 0;

        for (j = 0; j < numPages; j++)
        {
            if (memory[j] == referenceString[i])
            {
                pageFound = emptySlot = 1;
                break;
            }
        }
        if (pageFound == 0)
        {
            for (j = 0; j < numPages; j++)
            {
                if (memory[j] == '#')
                {
                    pageFaults++;
                    memory[j] = referenceString[i];
                    emptySlot = 1;
                    break;
                }
            }
        }
        if (emptySlot == 0)
        {
            int pageNotReferenced = 0;

            for (j = 0; j < numPages; j++)
            {
                temp[j] = -1;

                for (k = i + 1; k < referenceStringLength; k++)
                {
                    if (memory[j] == referenceString[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }

            for (j = 0; j < numPages; j++)
            {
                if (temp[j] == -1)
                {
                    position = j;
                    pageNotReferenced = 1;
                    break;
                }
            }

            if (pageNotReferenced == 0)
            {
                max = temp[0];
                position = 0;

                for (j = 1; j < numPages; j++)
                {
                    if (temp[j] > max)
                    {
                        max = temp[j];
                        position = j;
                    }
                }
            }
            memory[position] = referenceString[i];
            pageFaults++;
        }

        cout << endl;

        for (j = 0; j < numPages; j++)
        {
            cout << memory[j] << "\t";
        }
    }

    cout << endl
         << endl
         << "The number of Page Faults using Optimal Algorithm is: " << pageFaults << endl;
    cout << "The number of Page Hits using Optimal Algorithm is: " << referenceStringLength - pageFaults << endl;
}

void FIFOAlgorithm()
{
    int count = 0, k, pageFaults = 0;

    char memory[numPages];
    for (int i = 0; i < numPages; i++)
    {
        memory[i] = '#';
    }

    for (int i = 0; i < stringLength; i++)
    {
        for (k = 0; k < numPages; k++)
        {
            if (memory[k] == referenceString[i])
            {
                break;
            }
        }
        if (k == numPages)
        {
            memory[count++] = referenceString[i];
            pageFaults++;
        }
        for (int j = 0; j < numPages; j++)
        {
            cout << "\t" << memory[j];
        }
        if (k == numPages)
        {
            cout << "\t PF No. " << pageFaults;
        }
        cout << endl;

        if (count == numPages)
        {
            count = 0;
        }
    }

    cout << endl
         << endl
         << "The number of Page Faults using FIFO is: " << pageFaults << endl;
    cout << "The number of Page Hits using FIFO is: " << stringLength - pageFaults << endl;
}

void LRUAlgorithm()
{
    int count[numPages] = {0}, pageFaults = 0, i, j, next = 0, mini;
    bool flag[stringLength];
    char memory[numPages];

    for (i = 0; i < numPages; i++)
    {
        memory[i] = '#';
    }

    for (i = 0; i < stringLength; i++)
    {
        for (j = 0; j < numPages; j++)
        {
            if (memory[j] == referenceString[i])
            {
                flag[i] = true;
                count[j] = next;
                next++;
            }
        }
        if (flag[i] == false)
        {
            if (i < numPages)
            {
                memory[i] = referenceString[i];
                count[i] = next;
                next++;
            }
            else
            {
                mini = 0;
                for (j = 1; j < numPages; j++)
                {
                    if (count[mini] > count[j])
                    {
                        mini = j;
                    }
                }
                memory[mini] = referenceString[i];
                count[mini] = next;
                next++;
            }
            pageFaults++;
        }

        for (j = 0; j < numPages; j++)
        {
            cout << memory[j] << "\t";
        }

        if (!flag[i])
        {
            cout << "PF No. " << pageFaults;
        }
        cout << endl;
    }

    cout << endl
         << endl
         << "The number of Page Faults using LRU is: " << pageFaults << endl;
    cout << "The number of Page Hits using LRU is: " << stringLength - pageFaults << endl;
}

int main()
{

    cout << "******PAGE_REPLACEMENT_ALGORITHM******" << endl;
    Input();
    cout << endl << endl << "Optimal Page Replacement Algorithm.." << endl;
    OptimalAlgorithm();
    cout << endl << endl << "FIFO Page Replacement Algorithm.." << endl;
    FIFOAlgorithm();
    cout << endl << endl << "LRU Page Replacement Algorithm.." << endl;
    LRUAlgorithm();
}
