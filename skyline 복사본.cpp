#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int X[1000000] = {0, };
int H[1000000] = {0, };
int V[1000000] = {0, };
int O[1000000] = {0, };
int main()
{
    int n;
    int x,v,h;
    int cnt=0;
    cin>>n;
    vector<int> K;
    for(int i=0; i<n; i++)
    {
        cin>>x>>v>>h;
        X[i] = x;
        V[i] = v;
        H[i] = h;
        if(cnt<x+h)
        {
            cnt = x+h;
        }
    }
    int tmp = 0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1;j<n; j++ )
        {
            if(X[i]>X[j] || (X[i]==X[j] && V[i]<V[j]))
            {
                tmp = X[i];
                X[i] = X[j];
                X[j] = tmp;
                
                tmp = V[i];
                V[i] = V[j];
                V[j] = tmp;
                
                tmp = H[i];
                H[i] = H[j];
                H[j] = tmp;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=X[i]; j<X[i]+H[i]; j++)
        {
            if(O[j]<V[i])
            {
                O[j] = V[i];
            }
            
        }
    }
    K.push_back(X[0]);
    K.push_back(V[0]);
    int cnt_2 = 1;
    for(int i=X[0]; i<cnt; i++)
    {
        if(O[i] == O[i+1])
        {
            cnt_2++;
        }
        else
        {
            K.push_back(cnt_2);
            K.push_back(O[i+1]-O[i]);
            cnt_2 = 1;
        }
    }
    for(int i=0; i<K.size(); i++)
    {
        cout<<K[i]<<" ";
    }
    cout<<endl;
    return 0;
}