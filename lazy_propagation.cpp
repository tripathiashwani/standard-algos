#include <bits/stdc++.h>
using namespace std;
class SGTree{
    vector<int>seg,lazy;
    public:
    SGTree(int n){
        seg.resize(4*n+1);
        lazy.resize(4*n+1);
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
    void update(int ind,int low,int high,int l,int r){
        // update lazy,if remaining
        if(lazy[ind]!=0){
            seg[ind]=(r-l+1)*lazy[ind];
            // if lazy has children ,propagate
            if(low!=high){
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }
        // if no overlap,return only
        // it is l r low high or low high l r
        if(r<low || high<l)return ;
        // if full overlap,then update and return 
        if(low>=high)


    }
};