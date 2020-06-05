#include<iostream>
#include<vector>

using namespace std;


void HeapAdjust(vector<int>& tab,int i,int len)
{
    int temp = tab[i];
    int parent = i;
    int child = 2*parent+1;
    while(child < len){
        if(child+1<len && tab[child+1]>tab[child])  child++;
        if(tab[child]<temp) break;

        tab[parent] = tab[child];
        parent = child;
        child = parent*2+1;
    }
    tab[parent] = temp;
    return;
}

void heapSort(vector<int>& tab){
    int len = tab.size();

    for(int i = len/2-1;i>=0;i--){
        HeapAdjust(tab,i,len);
    }

    for(int j =len-1;j>=0;j--){
        swap(tab[0],tab[j]);
        HeapAdjust(tab,0,j);
    }

    return;
}



int main()
{
     vector<int> tab = {10,9,8,7,6,5,4,3,2,1,-5};
     //ÅÅĞòÇ°
    cout<<"ÅÅĞòÇ°£º";
    for(int val:tab)
        cout<<val<<" ";
    cout<<endl;

    cout<<"¶ÑÅÅĞò£º"<<endl;
    heapSort(tab);

     //ÅÅĞòºó
    cout<<"ÅÅĞòºó£º";
    for(int val:tab)
        cout<<val<<" ";


    return 0;
}