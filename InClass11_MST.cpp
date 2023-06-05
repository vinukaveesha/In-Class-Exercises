#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define V 6
#define INF INT_MAX


void primsMst(int G[V][V],int source){
    vector<bool> selected(V,false);
    selected[source] = true;

    int x; //row number
    int y; // column number

    cout<<"Pole "<< " : " << "Distance"<<endl;
    int count = 0;
    while(count<V-1){
        int min = INF;
        x=0;
        y=0;
        for (int i=0;i<V;i++){
            if(selected[i]){
                for(int j=0;j<V;j++){
                    if(!selected[j]&& G[i][j]){
                        if(min>G[i][j]){
                            min = G[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }

        }
        cout<<x<<" - "<<y<<" : "<<G[x][y];
        cout<<endl;
        selected[y]=true;
        count++;
    }
}


int main(){

    int adjMat[6][6]= {
    {0,3,0,0,0,1},
    {3,0,2,1,10,0},
    {0,2,0,3,0,5},
    {0,1,3,0,5,0},
    {0,10,0,5,0,4},
    {1,0,5,0,4,0}
    };

    primsMst(adjMat,0);

    return 0;
}

