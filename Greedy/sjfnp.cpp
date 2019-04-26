#include<bits/stdc++.h>
using namespace std;
struct process
{
    int pid;
    int bt;
};
bool comparison(process a, process b)
{
     return (a.bt < b.bt);
}
void findwt(process proc[],int n,int wt[])
{
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+proc[i-1].bt;
    }
}
void findtat(process proc[],int n,int tat[],int wt[])
{
    for(int i=0;i<n;i++)
    {
        tat[i]=wt[i]+proc[i].bt;
    }
}
void table(process proc[],int n)
{
    int wt[n],tat[n],totalwt=0,totaltat=0;
    findwt(proc,n,wt);
    findtat(proc,n,tat,wt);
    cout << "\nProcesses "<< " Burst time "
         << " Waiting time " << " Turn around time\n";
        for(int i=0;i<n;i++)
        {
            totalwt+=wt[i];
            totaltat+=tat[i];
            cout<<"   "<<proc[i].pid<<"   "<<proc[i].bt<<"   "<<wt[i]<<"   "<<tat[i]<<endl;
        }

}
int main()
{
    process proc[]={{1, 6}, {2, 8}, {3, 7}, {4, 3}};
    int n=sizeof(proc)/sizeof(proc[0]);
    sort(proc,proc+n,comparison);
    for(int i=0;i<n;i++)
    {
        cout<<proc[i].pid<<" ";
    }
    table(proc,n);
    return 0;
}
