#include <iostream>
#include <string>
using namespace std;

struct Trie
{
	Trie *alpha[26];
	bool end;

	Trie()
	{
		for(int i=0;i<26;i++)
			alpha[i] = NULL;
		end = false;
	}
};

void TrieInsert(string name, Trie *root)
{
	for(int i=0; i<name.length(); i++)
	{
		int index = name[i] - 'a';

		if(root->alpha[index]==NULL)
			root->alpha[index] = new Trie();

		root = root->alpha[index];
	}

	root->end = true;
}

bool Search(string name, Trie *root)
{
	for(int i=0; i<name.length(); i++)
	{
		int index = name[i] - 'a';

		if(root->alpha[index]!=NULL)
			root = root->alpha[index];
		else
			return false;
	}

	return root->end;
}


bool isLast(Trie *root)
{
	for (int i = 0; i < 26; ++i)
	{
		if(root->alpha[i]!=NULL)
			return false;
	}
	return true;
}

void NEXTALL(Trie *root, string key)
{
	if(root->end)
		cout<<key<<endl;

	if(isLast(root))
		return;

	for(int i=0; i<26; i++)
	{
		if(root->alpha[i]!=NULL)
		{
			key.push_back(97 + i);
		    NEXTALL(root->alpha[i],key);
		    key.pop_back();
		}
	}
}

bool alphaSearch(string name, Trie *root)
{
	for(int i=0; i<name.length(); i++)
	{
		int index = name[i] - 'a';

		if(root->alpha[index]!=NULL)
			root = root->alpha[index];
        else
        	return false;
	}
	
		if(isLast(root) && root->end)
			cout<<name<<endl;
		else
			NEXTALL(root,name);
	
	return true;
}


int main()
{
    Trie *root = new Trie();

    string Friends[] = {"aadhar","aman","rajesh","aarjav","rajeshwar","rahul"};
       
    for(int i=0; i<6; i++)
    TrieInsert(Friends[i],root); 

    /*if(Search("aman",root))
       cout<<"Exists !"<<endl;
       else
       cout<<"Does not exists !"<<endl;  */
         
       string key;  
       cin>>key;
       cout<<endl;
       if(!alphaSearch(key,root))
       cout<<"No words by that key"<<endl;

	return 0;
}