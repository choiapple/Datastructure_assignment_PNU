#include <iostream>
#include <vector>
using namespace std;
void swap_vec(vector<int> a, vector<int> b, int P)
{
    b.swap(a);
    a.resize(0);
    a.shrink_to_fit();
    a.reserve(P);
    for(int j=0; j<b.size(); j++)
    {
        if(b[j]!=-1)
        {
            a.push_back(b[j]);
        }
    }
}
int main()
{
    int K, N, car;
    int count = 0;
    vector<int> park;
    vector<int> tmp;
    cin>>K>>N;
    park.reserve(K);
    for(int i=0; i<N; i++)
    {
        int YN = 0;
        cin>>car;
        if(i==0 && car>0)
        {
            park.push_back(car);
        }
        else
        {
            if(car>0)
            {
                for(int j=0; j<park.size(); j++)
                {
                    if(park[j] == -1)
                    {
                        park[j] = car;
                        break;
                    }
                }
                for(int j=0; j<park.size(); j++)
                {
                    if(park[j] == car)
                    {
                        YN = 1;
                        break;
                    }
                }
                if(YN == 0)
                {
                    park.push_back(car);
                }
            }
            else if(car < 0)
            {
                for(int j=0; j<park.size(); j++)
                {
                    if(park[j] == abs(car))
                    {
                        park[j] = -1;
                        break;
                    }
                }
            }
            for(int j=0; j<park.size(); j++)
            {
                if(park[j] != -1)
                {
                    count++;
                }
            }
            if(park.capacity() == count)
            {
                swap_vec(park, tmp, park.capacity()*2);
            }
            if(park.capacity()/3 == count)
            {
                if(park.capacity()/2 >= K)
                {
                    swap_vec(park, tmp, park.capacity()/2);
                }
                else if(park.capacity()/2<K)
                {
                    swap_vec(park, tmp, K);
                }
            }
        }
        count = 0;
    }
    for(int i=0; i<park.size(); i++)
    {
        if(park[i]!=0 && park[i]!=-1)
        {
            cout<<i+1<<" "<<park[i]<<endl;
        }
    }

    return 0;
}