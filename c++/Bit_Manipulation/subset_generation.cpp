//Subset Generation using Bitmasks
//Print all the subsets of a given array of n elements n<=20
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

/*
    Each element of set can be either chosen or not chosen so for each element we have 2 choices(to take or not take)
    hence for a set of n unique elements there are 2^n subsets that can be formed.

    Each subset can be represented by a binary representation where 1 represents element is taken and 0 represents element is not taken
    so by each integer's binary representation represents a unique subset of the original set.
    when the integer is from [0,2^n-1]
*/
//Time-Compleity => O(n*(2^n))  //n is the size of original set
vector<vector<int>> subsets_generate(vector<int>& arr) 
{
        //here n is arr.size()
    long long sz=1<<arr.size(); //sz=2^n

    vector<vector<int>> subsets(sz);
    for(long long i=0;i<sz;i++)    //iterating from 0 to 2^n-1
    {
        long long temp=1;
        //This loop check which bits are set in binary representation of i.
        for(int j=0;j<arr.size();j++,temp<<=1)
        {
            if(i & temp)    
            subsets[i].push_back(arr[j]); //for every set bit the element is pushed in the subset
        }
    }
    return subsets;
}

//Driver Code
int main()
{
    vector<int> arr={3,4,7}; //Sample input array
    vector<vector<int>> subsets=subsets_generate(arr);
    //Printing each subset in each line
    for(auto &i:subsets)
    {
        cout<<"{";
        for(auto &j:i)
        {
            cout<<j<<" ";
        }
        cout<<"}\n";
    }
}
