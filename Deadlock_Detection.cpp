#include <iostream>
using namespace std;

const int MAX_PROCESSES = 20;
const int MAX_RESOURCES = 20;

int numProcesses, numResources;
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int request[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];

void input() {
    cout << "Enter the number of processes and resources: ";
    cin >> numProcesses >> numResources;

        cout << "Input Available Resource Vector:" << endl;
    for (int i = 0; i < numResources; i++) {
        cin >> available[i];
    }

    cout << "Input Current Allocation Matrix:" << endl;
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            cin >> allocation[i][j];
        }
    }

    cout << "Input Request Matrix:" << endl;
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            cin >> request[i][j];
        }
    }

}

void calculateNeedMatrix() {
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            need[i][j] = request[i][j] - allocation[i][j];
        }
    }
}

bool isSafe() {
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES] = {false};
    int safeSequence[MAX_PROCESSES];

    for (int i = 0; i < numResources; i++) {
        work[i] = available[i];
    }

    int count = 0;
    while (count < numProcesses) {
        bool found = false;
        for (int i = 0; i < numProcesses; i++) {
            if (!finish[i]) {
                bool canExecute = true;
                for (int j = 0; j < numResources; j++) {
                    if (need[i][j] > work[j]) {
                        canExecute = false;
                        break;
                    }
                }
                if (canExecute) {
                    for (int j = 0; j < numResources; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    safeSequence[count] = i;
                    count++;
                    found = true;
                }
            }
        }
        if (!found) {
            return false; // Deadlock detected
        }
    }

    cout << "System is in Safe Mode. Sequence by which Processes will be Finished: ";
    for (int i = 0; i < numProcesses; i++) {
        cout << "P" << safeSequence[i] << " ";
    }
    cout << endl;
    return true; // No deadlock
}

void display() {
    cout << "-------------OUTPUT-------------" << endl;

    cout << "Allocation Matrix:" << endl;
    for (int i = 0; i < numProcesses; i++) {
        cout << "P" << i << " ";
        for (int j = 0; j < numResources; j++) {
            cout << allocation[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Request Matrix:" << endl;
    for (int i = 0; i < numProcesses; i++) {
        cout << "P" << i << " ";
        for (int j = 0; j < numResources; j++) {
            cout << request[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Available Resource Vector:" << endl;
    for (int i = 0; i < numResources; i++) {
        cout << available[i] << " ";
    }
    cout << endl;
}

int main() {
    input();
    display();
    calculateNeedMatrix();

    if (isSafe()) {
        cout << "The system is not in deadlock." << endl;
    } else {
        cout << "System is in Deadlock." << endl;
    }

    return 0;
}