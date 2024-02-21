#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int num_of_process, process[100], index = 0,schedule[100],burst_time[100], priority[100], i = 0, j = 0, k = 0, small_priority = 9999;
    double arrival_time[100], arrival_time2[100],  waiting_time[100],time = 0, small_arrival = 0,total = 0, start_time[100], end_time[100], avg_waiting_time = 0;
    
    cout<<"Enter the number of process: ";
    cin>>num_of_process;
    cout<<"\n";
    for(i = 1; i <= num_of_process; i++)
    {
        cout<<"Enter the process in serial "<<i<<" = ";
        cin>>process[i];
        cout<<"Enter the process "<<process[i]<<"'s arrival time = ";
        cin>>arrival_time[process[i]];
        arrival_time2[i] = arrival_time[i];
        cout<<"Enter process "<<process[i]<<"'s burst time = ";
        cin>>burst_time[process[i]];
        cout<<"Enter process "<<process[i]<<"'s priority = ";
        cin>>priority[process[i]];
        cout<<"\n";
    }
    int term = num_of_process;
    while(term > 0)
    {
        small_arrival = 9999;
        for(i = 1; i <= num_of_process; i++)
        {
            if(small_arrival > arrival_time[i] && arrival_time[i] > -1)
            {
                small_arrival = arrival_time[i];
            }
        }
        small_priority = 9999;
        for(i = 1; i <= num_of_process; i++)
        {
            if(small_arrival == arrival_time[i] && small_priority > priority[i] && priority[i] > 0)
            {
                small_priority = priority[i];
                index = i;
            }
        }
        priority[index] = 0;
        arrival_time[index] = -1;
        start_time[index] = time;
        time += burst_time[index];
        end_time[index] = time;
        schedule[k] = index;
        k++;
        term--;
    }
    cout<<"\nGantt chart: \n"<<0;
    for(i = 1; i <= num_of_process; i++)
    {
        cout<<"(p"<<schedule[i-1]<<")";
        for(j = 1; j <= burst_time[schedule[i-1]]; j++)
        {
            cout<<"-";
        }
        cout<<end_time[schedule[i-1]];
    }
    for(i = 1; i <= num_of_process; i++)
    {
        waiting_time[i] = start_time[i] - arrival_time2[i];
        total += waiting_time[i];
        cout<<"\nWaiting time for process"<<i<<" = "<<waiting_time[i];
    }
    avg_waiting_time = total/num_of_process;
    cout<<"\nAverage waiting time = "<<avg_waiting_time<<"\n";
}