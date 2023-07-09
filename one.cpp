#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n ,x;
        cin>>n>>x;
        vector<int>arr;
        for(int i=0;i<n;i++){
            int y;
            cin>>y;
            arr.push_back(y);
        }
        int q;
        cin>>q;
        vector<pair<int,int>>queries;
        for(int i=0;i<q;i++){
            int k,val;
            cin>>k>>val;
            queries.push_back({k,val});
        }
        vector<int>res;
        long long totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=arr[i];
        }
        int i=0;
        while(i<q){
            pair<int,int>qry=queries[i];
            int k=qry.first;
            int val=qry.second;
            long long new_sum=totalsum-arr[k]+val;
            int op=new_sum/x;
            if(new_sum==0)res.push_back(0);
           else if(new_sum<=x)res.push_back(1);
           else if(new_sum%x==0)res.push_back(new_sum/x);
           else res.push_back(new_sum/k+1);
           i++;
        }

        // return res;
        for(int i=0;i<q;i++)cout<<res[i];
    }
}