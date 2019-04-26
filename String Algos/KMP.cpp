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
    string pattern = "abcdabca";
    string text = "abcabcdabccaaa";
    int lp = pattern.length();
    int lt = text.length();

    int arr[lp] = {0};
    strNum(arr,pattern,lp);

    int j = 0;
    bool found = false;

    for(int i=0; i<lt; i++)
    {
        if(found)
        break;
        
        if(text[i] == pattern[j])
        {
            j++;
            if(j == lp)
            {
                cout<<"Pattern found !";
                found = true;
                break;
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
                        cout<<"Pattern found !";
                        found = true;
                    }
                    break;
                }
            }
        }
    }

    if(!found)
    {
        cout<<"Pattern Not Found !";
    }

    return 0;
}
