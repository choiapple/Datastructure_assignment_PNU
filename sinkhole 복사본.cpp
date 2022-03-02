#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    int w, k, n, wi;
    int total = 1;
    int cnt = 0;
    int all_wi = 0;
    queue<int> q;
    queue<int> empty;
    cin>>w;
    cin>>k;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>wi;
        cnt++;
        all_wi += wi;
        q.push(wi);
        if(cnt == k && all_wi <= w)
        {
            all_wi -= q.front();
            q.pop();
            cnt--;
        }
        else if(all_wi > w)
        {
            q = queue<int>();
            q.push(wi);
            total++;
            all_wi = wi;
            cnt = 1;
        }
    }
    cout<<total<<endl;
    return 0;
}