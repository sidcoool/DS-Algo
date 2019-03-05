#include<iostream>
#include<list>
using namespace std;
list<int>  b;
list<list<int> > a;
int main()
{
    int x;
    cout<<"Enter the member in list"<<endl;
    cin>>x;
    cout<<"Each member have 3 data"<<endl<<"Enter data"<<endl;
    for(int i=0;i<x;i++)
    {
        cout<<"Enter data for list"<<i+1<<endl;
        for(int j=0;j<3;j++)
        {
            int data;
            cin>>data;
            b.push_back(data);
        }
        a.push_back(b);
        b.erase(b.begin(),b.end());
    }
    //cout<<"Entered list of list is:"<<endl;
    list<list<int> > :: iterator n;
    //for(n=a.begin();n!=a.end();n++)
     int no;
    n=a.begin();
    cout<<"Enter the list to printed"<<endl;
    cin>>no;
    advance(n,no-1);
        list<int> o = *n;
        list<int> :: iterator m;

        for(m=o.begin();m!=o.end();m++)
        {
            cout<<*m<<"  ";
        }
        cout<<endl;
    
    return 0;
}
