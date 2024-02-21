#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int num_of_process = 0, process[100], burst_time[100], waiting_time[100], i = 0, j = 0, time = 0, total = 0;
    double  arrival_time[100],avg_waiting_time = 0;
    cout<<"Enter the number of processes: ";
    cin>>num_of_process;
    for(i = 0; i < num_of_process; i++)
    {
        cout<<"Enter the process in serial "<<i+1<<" = ";
        cin>>process[i];
        cout<<"Enter process "<<process[i]<<"'s arrival time = ";
        cin>>arrival_time[i];
        cout<<"Enter process "<<process[i]<<"'s burst time = ";
        cin>>burst_time[process[i]];
    }
    cout<<"\nProcess schedule: ";
    {
        for(i = 0; i< num_of_process; i++)
        {
            cout<<"Process"<<process[i];
            if(i != num_of_process-1)
            {
                cout<<"->";
            }
        }
    }
    cout<<"\nGantt Chart: \n"<<0;
    for(i = 0; i < num_of_process; i++)
    {
        for(j = 1; j <= burst_time[process[i]]; j++)
        {
            cout<<"-";
        }
        time += burst_time[process[i]];
        cout<<time;
    }
    cout<<"\n";
    time = 0;
    for(i = 0; i < num_of_process; i++)
    {
        waiting_time[i] = 0;
    }
    for(i = 1; i < num_of_process; i++)
    {
        time += burst_time[process[i-1]] - arrival_time[process[i]];
        waiting_time[i] += time;
    }
    for(i = 0; i < num_of_process; i++)
    {
        total += waiting_time[i];
        cout<<"Waiting time for process "<<process[i]<<"= "<<waiting_time[i]<<"\n";
    }
    avg_waiting_time = (double)total / num_of_process;
    cout<<"Average wating time = "<<avg_waiting_time<<"\n";
}