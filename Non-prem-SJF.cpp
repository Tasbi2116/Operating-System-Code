#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    double  arrival_time[100], burst_time[100],work_time[100], waiting_time[100],avg_waiting_time = 0, time = 0, total = 0, run = 0, small_time = 0, end_time[100];
    int num_of_process = 0, process[100], i = 0, j = 0, ind[100], index = 0;
    cout<<"Enter the number of processes: ";
    cin>>num_of_process;
    for(i = 1; i <= num_of_process; i++)
    {
        cout<<"Enter the process in serial "<<i<<" = ";
        cin>>process[i];
        cout<<"Enter the process "<<process[i]<<"'s arrival time = ";
        cin>>arrival_time[process[i]];
        cout<<"Enter process "<<process[i]<<"'s burst time = ";
        cin>>burst_time[process[i]];
        cout<<"\n";
    }
    for(i = 1; i <= num_of_process; i++)
    {
        if(run < burst_time[i])
        {
            run = burst_time[i]; 
        }
    }
    double small_arrival = arrival_time[1];
    for(i = 1; i <= num_of_process; i++)
    {
        if(small_arrival > arrival_time[i])
        {
            small_arrival = arrival_time[i];
            index = i;
        }
    }
    
    for(i = 1; i <= num_of_process; i++)
    {
        if(i == 1)
        {
            time += burst_time[i];
            waiting_time[i] = 0;
            end_time[i] = time;
            ind[i] = i;
            work_time[i] = burst_time[i];
        }
        else
        {
            small_time = run;
            for(j = 2; j <= num_of_process; j++)
            {
                if(small_time > burst_time[j] && arrival_time[j] <= time)
                {
                    small_time = burst_time[j];
                    ind[i] = j;
                }
            }
            waiting_time[ind[i]] = (time*1.0) - arrival_time[ind[i]];
            time += small_time;
            end_time[ind[i]] = time;
            work_time[ind[i]] = burst_time[ind[i]];
            burst_time[ind[i]] = run;
        }
    }
    for(i = 1; i <= num_of_process; i++)
    {
        cout<<"Waiting time for process"<<i<<" = "<<waiting_time[i]<<"\n";
        total += waiting_time[i];
    }
    avg_waiting_time = (double)total/num_of_process;
    cout<<"Average waiting time = "<<avg_waiting_time<<"\n";
    cout<<"\nWorking serial: ";
    for(i = 1; i <= num_of_process; i++)
    {
        cout<<"Process "<<ind[i];
        if(i != num_of_process)
        {
            cout<<" -> ";
        }
    }
    cout<<"\n\nGantt chart: \n"<<0;
    for(i = 1; i <= num_of_process; i++)
    {
        for(j = 1; j <= work_time[ind[i]]; j++)
        {
            cout<<"-";
        }
        cout<<end_time[ind[i]];
    }
}