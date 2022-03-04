#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
struct patients
{
    string id;
    int A;
    char FM;
    int I;
    patients(string s, int a, char fm, int i) : id(s), A(a), FM(fm), I(i){};
};
struct cmp
{
    bool operator()(patients a, patients b)
    {
        if(a.FM == b.FM)
        {
            return a.I > b.I; // 우선순위 큐는 오른쪽이 기준이고 sort는 왼쪽이 기준임 
            // 우선순위 큐는 오른쪽이 기준이라서 이게 오름 차순
            // sort일때는 이거는 내림 차순임
        }
        else
        {
            return a.FM < b.FM;
        }
    }
};
int main()
{
    typedef pair<int, char> pii;
    vector<pair<string, pii> > all_vc;
    priority_queue<patients, vector<patients>, cmp> old;
    queue<string> child;
    queue<string> adult;
    int n, a;
    string k;
    char FM;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>k>>a>>FM;
        all_vc.push_back(make_pair(k, make_pair(a, FM)));
    }
    for(int i=0; i<n; i++)
    {
        if(all_vc[i].second.first>=61)
        {
            old.push(patients(all_vc[i].first, all_vc[i].second.first, all_vc[i].second.second, i));
        }
    }
    for(int i=0; i<n; i++)
    {
        if((all_vc[i].second.first>=16 && all_vc[i].second.first <= 60) && all_vc[i].second.second == 'F')
        {
            adult.push(all_vc[i].first);
        }
    }
    for(int i=0; i<n; i++)
    {
        if((all_vc[i].second.first>=16 && all_vc[i].second.first <= 60) && all_vc[i].second.second == 'M')
        {
            adult.push(all_vc[i].first);
        }
    }
    for(int i=0; i<n; i++)
    {
        if(all_vc[i].second.first<=15)
        {
            child.push(all_vc[i].first);
        }
    }
    while(!old.empty())
    {
        cout<<old.top().id<<endl;
        old.pop();
    }
    while(!child.empty())
    {
        cout<<child.front()<<endl;
        child.pop();
    }
    while(!adult.empty())
    {
        cout<<adult.front()<<endl;
        adult.pop();
    }
    return 0;
}