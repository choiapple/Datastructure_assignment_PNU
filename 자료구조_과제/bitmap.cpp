#include <iostream>
using namespace std;
int main()
{
    long long tmp = 0;
    long long tm[64] = {0, };
    for(int i=0; i<64; i++)
    {
        cin>>tmp;
        for(int j=63; j>=0; j--)
        {
            tm[j] |= ((tmp&1)<<(63-i));
            tmp = tmp>>1;
        }
    }
    for(int i=0; i<64; i++)
    {
        cout<<tm[i]<<endl;
    }
    return 0;
}