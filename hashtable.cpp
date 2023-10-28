#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class node {
    public:
    node* next;
    int value;
    string key;
 node (string key,int value)
 {
    this->key=key;
    this->value=value;
    next=nullptr;

    
 }
};
class hashTable
{
    private:
    static const int  SIZE =7;
    node * dataMap[SIZE];
    public:
    void PrintTable();
    void set(string key, int value);
    int Hash(string key);
    int get (string key);
    vector<string> getKeys();
    int strlen(string key)
    {
        int i=0;
        while(key[i])
        {
        i=i+1;
        }
        return i;
    }
};
vector<string> hashTable:: getKeys()
{  
    vector<string> keys;
    for (int i=0;i<SIZE;i++)
    {
        node *temp=dataMap[i];
        while(temp!=nullptr)
        {
          keys.push_back(temp->key);
          temp=temp->next;
        }
    }
    return keys;
}
int hashTable::Hash(string key)
{ int hash =0;
    for (int i=0;i<strlen(key);i++)
    {
        int asciiValue=int(key[i]);
        //cout<<"ascii:"<<asciiValue<<endl;
        hash=(hash+asciiValue*3)%SIZE;
        // cout<<"hash :"<<hash<<endl;
    }
    //cout<<"hash code :"<<hash<<endl;
    return hash;
}
void hashTable::set (string key,int value)
{
    node*newnode =new node(key,value);
int index =Hash(key);

if (dataMap[index]==nullptr)
{
dataMap[index]=newnode;
}
else{
    node*temp=dataMap[index];
    while(temp->next!=nullptr)
    {
      temp=temp->next;
    }
    temp->next=newnode;
}
}
void hashTable::PrintTable()
{
    for (int i=0;i<SIZE;i++)
    {
        cout<<i<<":"<<endl;
        if (dataMap[i])
        {
         node* temp=dataMap[i];
         while(temp)
         {
            cout<<"{"<<temp->key<<","<<temp->value<<"}"<<endl;
            temp=temp->next;
         }
        }
    }
}
int hashTable::get(string key)
{
    int index=Hash(key);
    node * temp=dataMap[index];
    while(temp!=nullptr)
    {
        if (temp->key==key)
        {
          return temp->value;
        }
        temp=temp->next; 
    }
    return 0;
}
int main()
{
    hashTable*myhash=new hashTable();
    myhash->set("eat",78);
    myhash->set("look",67);
    myhash->set("tpp",45);
    myhash->set("ate",89);
     myhash->set("har",45);
    cout<<myhash->get("kar")<<endl;
    myhash->PrintTable();
    vector<string> keys=myhash->getKeys();
    for(auto key:keys)
    {
        cout<<key<<" ";
    }
}