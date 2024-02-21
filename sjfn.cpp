#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num_of_process, i = 0, j = 0,k= 0, process[100], ind = 0,serial[100];
    double arrival_time[100],waiting_time[100],time =0,arrival_time2[100], burst_time[100], work_time[100];
    cin>>num_of_process;
    for(i = 1; i <= num_of_process; i++)
    {
        cin>>process[i]>>arrival_time[i]>>burst_time[i];
        arrival_time2[i] = arrival_time[i];
        work_time[i] = burst_time[i];
    }
    double start = 9999;
    for(i = 1; i <= num_of_process; i++)
    {
        if(start > arrival_time[i])
        {
            start=arrival_time[i];
        }
    }
    time += start;
    int term = num_of_process;
    while(term--)
    {
    double s_arrival = 9999;
    for(i = 1; i <= num_of_process; i++)
    {
        if(s_arrival > arrival_time[i] && arrival_time[i] > -1)
        {
            s_arrival=arrival_time[i];
        }
    }
    
    double s_burst = 9999;
    for(i = 1; i <= num_of_process; i++)
    {
        if(s_burst > burst_time[i] && arrival_time[i] == s_arrival && burst_time[i] > 0)
        {
            s_burst=burst_time[i];
            ind = i;
        }
    }
    cout<<time;
    for(k = 1; k <= burst_time[ind];k++)
    {
        cout<<"-";
    }
    if(time <= s_arrival)
    {
        waiting_time[ind] = 0;
    }
    else
    {
        waiting_time[ind] = time - arrival_time[ind];
    }
    time += burst_time[ind];
    burst_time[ind] = 0;
    arrival_time[ind] = -1;
    serial[j] = ind;
    j++;
    }
    cout<<time<<"\n";
    for(i = 0; i < j; i++){
        cout<<"p"<<serial[i];
        if(i+1 != j)
        {
            cout<<"->";
        }
    }
    cout<<"\n";
    for(i = 1; i <= num_of_process; i++)
    {
        cout<<waiting_time[i]<<" ";
    }
}