#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void dist(int start, int n, priority_queue<int, vector<int>, less<int> >&max, vector<vector<int> >graph);
int main()
{
    int n;
    cin>>n;
    priority_queue<int, vector<int>, less<int> > max;
    vector<vector<int> > graph(n+1);
    for(int i=0; i<n; i++)
    {
        int x, y;
        cin>>x>>y;
        while(y!=0)
        {
            graph[x].push_back(y);
            cin>>y;
        }
    }
    for(int i=1; i<=n; i++)
    {
        dist(i,n,max,graph);
    }
    cout<<max.top()<<endl;
    return 0;
}
void dist(int start, int n, priority_queue<int, vector<int>, less<int> >&max, vector<vector<int> >graph)
{
    int cnt = 0;
    deque<int> q1, q2;
    int *visit;
    visit = new int[n+1];
    for(int i=0; i<n+1; i++)
    {
        visit[i] = -1;
    }
    visit[0] = 0;
    visit[start] = 0;
    q1.push_back(start);
    while(!q1.empty())
    {
        int node = q1.front();
        q1.pop_front();
        for(int i=0; i<graph[node].size(); i++)
        {
            int next = graph[node][i];
            if(visit[next] == -1)
            {
                if(cnt > 0)
                {
                    visit[next] = visit[node] + graph[node].size();
                }
                else if(cnt == 0)
                {
                    visit[next] = visit[node] + 1;
                }
                q2.push_back(next);
            }
            else
            {
                if(visit[node] + graph[node].size() < visit[next])
                {
                    visit[next] = visit[node] + graph[node].size();
                }
            }
        }
        if(q1.empty())
        {
            q1 = q2;
            q2.clear();
            cnt++;
        }
    }
    int maximum = 0;
    for(int i=1; i<n+1; i++)
    {
        if(visit[i]>maximum)
        {
            maximum = visit[i];
        }
    }
    max.push(maximum);
}