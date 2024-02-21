#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int process[100], num_of_process = 0,small_priority = 0, priority[100], i = 0, j = 0, k = 0, index = 0, temp = 0;
    double arrival_time[100],small_arrival = 0, start_time[100], end_time[100], burst_time[100], temp_burst_time[100], work_time[100],small = 0, small_burst = 0, time_req = 0, time = 0;
    cout<<"Enter the number of process: ";
    cin>>num_of_process;
    cout<<"\n";
    for(i = 1; i <= num_of_process; i++)
    {
        cout<<"Enter the process in serial "<<i<<" = ";
        cin>>process[i];
        cout<<"Enter the process "<<process[i]<<"'s arrival time = ";
        cin>>arrival_time[process[i]];
        //arrival_time2[i] = arrival_time[i];
        cout<<"Enter process "<<process[i]<<"'s burst time = ";
        cin>>burst_time[process[i]];
        work_time[process[i]] = burst_time[process[i]];
        time_req += burst_time[process[i]];
        cout<<"Enter process "<<process[i]<<"'s priority = ";
        cin>>priority[process[i]];
        cout<<"\n";
    }
    small_arrival = arrival_time[1];
    for(i = 1; i <= num_of_process; i++)
    {
        if(small_arrival > arrival_time[i])
        {
            small_arrival = arrival_time[i];
        }
    }
    cout<<"Gantt chart: \n";
    while(time_req > time)
    {
        flag:
        small_burst = 9999;
        small_priority = 9999;
        for(i = 1; i <= num_of_process; i++)
        {
            if(arrival_time[i] <= small_arrival && priority[i] < small_priority && priority[i] > 0)
            {
                small_priority = priority[i];
            }
        }
        for(i = 1; i <= num_of_process; i++)
        {
            if(small_priority == priority[i] && small_burst > burst_time[i] && burst_time[i] > 0)
            {
                small_burst = burst_time[i];
                index = i;
            }
        }
        if(burst_time[index] == work_time[index])
        {
            start_time[index] = time;
        }
        cout<<time;
        if(burst_time[index] > 0)
        {
            cout<<"(P"<<process[index]<<")";
        }
        while(burst_time[index] > 0)
        {
            time++;
            burst_time[index]--;
            if(burst_time[index] == 0)
            {
                end_time[index] = time;
            }
            cout<<"-";
            for(i = 1; i <= num_of_process; i++)
            {
                if(time == arrival_time[i])
                {
                    small_arrival = arrival_time[i];
                    temp_burst_time[k] = burst_time[index];
                    k++;
                    for(j = 0; j < k; j++)
                    {
                        if(small > temp_burst_time[j] && temp_burst_time[j] > 0)
                        {
                            small = temp_burst_time[j];
                        }
                    }
                    temp = index;
                    goto flag;
                }
            }
            small_arrival = time;
        }
    }
    cout<<time_req<<"\n";
}