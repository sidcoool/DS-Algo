#include<bits/stdc++.h>
using namespace std;
int coin[]={1,2,5,10,20,50,100,500,1000};
int n=sizeof(coin)/sizeof(coin[0]);
void findMin(int x)
{
    vector<int> ans;
    for(int i=n-1;i>=0;i--)
    {
        while(x>=coin[i])
        {
             x = x - coin[i];
            ans.push_back(coin[i]);
        }
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

}
int main()
{
    int x=93;
    findMin(x);
    return 0;
}
