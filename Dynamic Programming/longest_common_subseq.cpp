#include <iostream>
using namespace std;
int main() {
    string str1 = "0stone";
    string str2 = "0longest";

    int m[6][8] = {0};

    for(int i=1; i<6; i++)
    {
        for(int j=1; j<8; j++)
        {
            if(str1[i] == str2[j])
            m[i][j] = 1 + m[i-1][j-1];
            else
            m[i][j] = max(m[i-1][j],m[i][j-1]);
        }
    }

    for(int i=0; i<6; i++)
    {
        for(int j=0; j<8; j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<m[5][7];
    return 0;
}
