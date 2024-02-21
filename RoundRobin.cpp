#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int num_of_process,index = 0, k = 1,temp = 0, process[100], small_priority = 0, priority[100], i = 0, j = 0, time_quantum = 0;
    double arrival_time[100],time_req = 0, waiting_time[100], total = 0, avg_waiting_time = 0, small_arrival = 9999, time = 0, burst_time[100], work_time[100], start_time, end_time[100];

    cout<<"Enter the number of processes: ";
    cin>>num_of_process;
    cout<<"\n";
    temp = num_of_process;
    for(i = 1; i <= num_of_process; i++)
    {
        cout<<"Enter the process of serial"<<i<<": ";
        cin>>process[i];
        cout<<"Enter the process"<<i<<"'s arrival time: ";
        cin>>arrival_time[i];
        cout<<"Enter the process"<<i<<"'s burst time: ";
        cin>>burst_time[i];
        work_time[i] = burst_time[i];
        time_req += burst_time[i];
        cout<<"Enter the process"<<i<<"'s priority: ";
        cin>>priority[i];
    }
    cout<<"Enter the CPU Time quantum: ";
    cin>>time_quantum;
    cout<<"Gantt chart: \n";
    while(time_req > time)
    {
        small_priority = 9999;
        for(i = 1; i <= num_of_process; i++)
        {
            if(small_priority > priority[i] && priority[i] > 0 && burst_time[i] > 0)
            {
                small_priority = priority[i];
                index = i;
            }
        }
        cout<<time;
        start_time = time;
        cout<<"(p"<<process[index]<<")";
        if(burst_time[index] >= time_quantum)
        {
            time += time_quantum;
            burst_time[index] -= time_quantum;
        }
        else if(burst_time[index] < time_quantum)
        {
            time += burst_time[index];
            burst_time[index] = 0;
            priority[index] = 4;
            temp--;
            end_time[index] = time;
        }
        for(j = 1; j <= (time-start_time); j++)
        {
            cout<<"-";
        }
        for(i = 1; i <= num_of_process; i++)
        {
            priority[i]--;
            if(priority[i] == 0)
            {
                priority[i] = temp;
            }
            //cout<<"For index "<<i<<" priority = "<<priority[i]<<"\n";
        }
    }
    cout<<time_req<<"\n";
    for(i = 1; i <= num_of_process; i++)
    {
        waiting_time[i] = end_time[i] - work_time[i];
        total += waiting_time[i];
        cout<<"Waiting time for process "<<i<<" = "<<waiting_time[i]<<"\n";
    }
    avg_waiting_time = total / num_of_process;
    cout<<"Average waiting time = "<<avg_waiting_time<<"\n";
}