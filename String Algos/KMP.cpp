#include <iostream>
using namespace std;

void strNum(int arr[], string str, int l)
{
    arr[0] = 0;

    int i = 0;

    for(int j=1; j<l; j++)
    {
        if(str[i] == str[j])
        {

            arr[j] = i + 1;

            i++;

        }
        else
        {
            while(i!=0 && str[i]!=str[j])
            {
                i = arr[i-1];

                if(str[i] == str[j])

                {

                    arr[j] = i + 1;

                }
            }
        }
    }
}

int main() {
    string pattern = "aabab";

    string text = "aaababaabaababaab";

    int lp = pattern.length();

    int lt = text.length();

    int arr[lp];
    for(int i=0; i<lp; i++)
    arr[i] = 0;

    strNum(arr,pattern,lp);
    cout<<"strNum array is ";
     for(int i=0; i<lp; i++)
      cout<<arr[i]<<" ";
      cout<<endl;

    int j = 0;


    for(int i=0; i<lt; i++)
    {
        if(text[i] == pattern[j])
        {
            j++;
            if(j == lp)
            {

                cout<<"Pattern found ! From index "<<i+1-lp<<" to "<<"index "<<i<<endl;
                j = 0;

            }

        }

        else
        {
            while(j!=0)
            {
                j = arr[j-1];

                if(text[i] == pattern[j])
                {
                    j++;

                    if(j == lp)
                    {

                        cout<<"Pattern found ! From index "<<i+1-lp<<" to "<<"index "<<i<<endl;
                        j = 0;
                    }
                    break;
                }
            }
        }
    }





    return 0;
}
