
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isPossible(int p,vector<int> cook,int n,int mid){

    int cnt = 0;
    for(int i=0;i<n;i++){
        //for each cook count the pratas
        int c = 0;
        int time = mid;
        int perpratas = cook[i]; // time taken to cook each pratas by ith cook
        while(time > 0){
            time = time - perpratas;
            if( time >= 0){
                c++;
                perpratas  += cook[i];
            }
        }
        cnt += c;
        if(cnt >= p)
            return true;
    }

    return false;
}

int minTime(int p,vector<int> cook,int n){
    int s = 0;
    int lazyCook = *max_element(cook.begin(),cook.end());
    int e = lazyCook * (p * (p + 1)) / 2;
    int mid = s + ((e - s) >> 1);   
    int ans=-1;

    while(s<=e){
       
        if(isPossible(p,cook,n,mid)){
            ans = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }
         mid = s + ((e - s) >> 1);
    }

    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int p;
        cin>>p;
        int n;
        cin>>n;
        vector<int> cook;
        for(int i=0;i<n;i++){
           int ele;
           cin >> ele;
           cook.push_back(ele);
        }
        cout<<minTime(p,cook,n)<<endl;
    }

    return 0;
}