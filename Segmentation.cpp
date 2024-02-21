#include <bits/stdc++.h>

using namespace std;

std::vector<pair<int,int>>sagment ;
vector<pair<int,pair<int,int>>>baseTable;

int n;

bool comp(pair<int,pair<int,int>>p1,pair<int,pair<int,int>>p2){
    return p1.second.first<p2.second.first;
}

void InputBaseTable(){
    cout<<"Enter n: ";
    cin>>n;
    cout<<"enter segment number,base_address,limit : "<<endl;
    for(int i=0;i<n;i++){
        int x, limit,base_address;
        cout<<"Enter segment number: ";
        cin>>x;
        cout<<"Enter base address: ";
        cin>>base_address;
        cout<<"Enter limit: ";
        cin>>limit;
        baseTable.push_back({x,{base_address,limit}});
    }
    
    cout<<"Segment Table: "<<endl;
    cout<<endl;
    for(auto it:baseTable){
        cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
    }
    
    sort(baseTable.begin(),baseTable.end(),comp);
    
    cout<<endl;
    cout<<endl;
    
    
    cout<<"Physical address: "<<endl;
    cout<<endl;
    
    for(auto it:baseTable){
        cout<<"segment number  "<<it.first<<"   base address  "<<it.second.first<<"  upto :  "<<it.second.first+it.second.second<<endl;
    }
    
    
}

void calculation(int sid,int offset){
    cout<<endl;
    if(baseTable[sid].second.second>=offset) {
        cout<<"The answer is: ";
        cout<<baseTable[sid].second.first+offset<<endl;
    }
    else{
        cout<<"invalid input.."<<endl;
    }
}

int main()
{
    
    int sid,offset;
    cout<<"Enter segment number: ";
    cin>>sid;
    cout<<"Enter offset number: ";
    cin>>offset;
    
    
    InputBaseTable();
    calculation(sid,offset);

    return 0;
}