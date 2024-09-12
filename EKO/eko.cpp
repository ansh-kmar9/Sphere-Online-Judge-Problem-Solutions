#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool possibleSolution(vector<long long int> arr , long long int m , long long int mid){
    long long collectedWoods = 0;
    for(long long int i = 0 ; i < arr.size() ; i++){
        if(arr[i] > mid){
            collectedWoods += arr[i] - mid;
        }
    }
    return collectedWoods >= m;
}


long long int minimumHeightBlade(vector<long long int> arr , long long int m){
    long long int s = 0;
    long long int maxEle = *max_element(arr.begin() , arr.end());
    long long int e = maxEle;
    long long int mid = s + ((e - s) >> 1);
    long long int ans = -1;
    while(s <= e){
        if(possibleSolution(arr,m,mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        // update mid
        mid = s + ((e - s) >> 1);
    }
    return ans;
}


int main()
{
    long long int n;
    long long int m;
    vector<long long int> arr;
    cin >> n >> m;
    while(n--){
        long long int ele;
        cin >> ele;
        arr.push_back(ele);
    }
    long long int ans = minimumHeightBlade(arr,m);
    cout << ans;
    
    return 0;
}