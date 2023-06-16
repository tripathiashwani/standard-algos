#include <bits/stdc++.h>
using namespace std;
class SGTree
{
    public:
    vector<int> seg;

public:
    SGTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void build(int ind, int low, int high, int arr[])
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1]+seg[2 * ind + 2];
        return;
    }
    int query(int ind, int low, int high, int l, int r)
    {
        // no overlap
        if (low > r || high < l)
            return 0;

        // complete overlap
        if (low >= l && high <= r)
            return seg[ind];

        // partial overlap
        int mid = (low + high) / 2;
        int left=query(2*ind+1,low,mid,l,r);
        int right=query(2*ind+2,mid+1,high,l,r);
        return left+right;
    }
    void update(int ind,int low,int high,int i,int val){
        if(low==high){
            seg[ind]=seg[ind]+val;
            return ;
        }
        int mid=(low+high)/2;
        if(i<=mid)update(ind*2+1,low,mid,i,val);
        else update(ind*2+2,mid+1,high,i,val);
        seg[ind]=seg[2*ind+1]+seg[ind*2+2];
    }
};

int main(){
    int n=5;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int arr[n]={2,3,-1,1,7};
    SGTree sg(n);
    sg.build(0,0,n-1,arr);
    int q;
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;
        int ind,val;
        cin>>ind>>val;
        ind =2,val=1;
        cout<<"before update"<<endl;
        for(int i=0;i<4*n;i++)cout<<sg.seg[i]<<" ";
       

        sg.update(0,0,n-1,ind,val);
          cout<<"after update"<<endl;
        for(int i=0;i<4*n;i++)cout<<sg.seg[i]<<" ";
        cout<<sg.query(0,0,n-1,l ,r)<<endl;
    }
    return 0;
}
