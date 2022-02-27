// 이도훈 자료구조 1번째 과제
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1500][1500] = {0,};
int main()
{
    // int n;
    // int k;
    // cin>>n;
    // int tmp = 0;
    // int x, y, w, h;
    // vector<int> X, Y, W, H;
    // vector<int> xy;
    // for(int i=0; i<n; i++){
    //     cin>>x>>y>>w>>h;
    //     X.push_back(x);
    //     Y.push_back(y);
    //     W.push_back(w);
    //     H.push_back(h);
    // }
    // cin>>k;
    // for(int i=0; i<n; i++){
    //     tmp = tmp + W[i]*H[i];
    // }
    // cout<<tmp<<endl;
    int n;
    int k;
    int cnt = 0;
    int x, y, w, h;
    
    cin>>n;
    vector<int> X, Y, W, H;
    for(int i=0; i<n; i++)
    {
        cin>>x>>y>>w>>h;
        X.push_back(x);
        Y.push_back(y);
        W.push_back(w);
        H.push_back(h);
    }
    cin>>k;
    for(int i=0; i<n; i++)
    {
        for(int j=Y[i]-H[i]/2; j<Y[i]+H[i]/2; j++)
        {
            for(int l=X[i]-W[i]/2; l<X[i]+W[i]/2; l++)
            {
                arr[j][l] = 1;
            }
        }
    }
    for(int i=0; i<1500; i++)
    {
        for(int j=0; j<1500; j++)
        {
            if(arr[i][j] == 1)
            {
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    
    return 0;
}