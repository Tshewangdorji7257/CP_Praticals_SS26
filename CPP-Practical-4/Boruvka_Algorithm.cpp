#include <iostream>
using namespace std;

struct Edge {
    int src, dest, weight;
};

int find(int parent[], int i) {
    if(parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    parent[x] = y;
}

int main() {

    int V,E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Edge edges[E];

    cout << "Enter edges (src dest weight):\n";
    for(int i=0;i<E;i++)
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;

    int parent[V];

    for(int i=0;i<V;i++)
        parent[i]=i;

    int numTrees = V;
    int MSTweight = 0;

    while(numTrees>1) {

        int cheapest[V];

        for(int i=0;i<V;i++)
            cheapest[i]=-1;

        for(int i=0;i<E;i++) {

            int set1=find(parent,edges[i].src);
            int set2=find(parent,edges[i].dest);

            if(set1==set2) continue;

            if(cheapest[set1]==-1 || edges[cheapest[set1]].weight>edges[i].weight)
                cheapest[set1]=i;

            if(cheapest[set2]==-1 || edges[cheapest[set2]].weight>edges[i].weight)
                cheapest[set2]=i;
        }

        for(int i=0;i<V;i++) {

            if(cheapest[i]!=-1) {

                int set1=find(parent,edges[cheapest[i]].src);
                int set2=find(parent,edges[cheapest[i]].dest);

                if(set1==set2) continue;

                cout<<"Edge "<<edges[cheapest[i]].src<<" - "<<edges[cheapest[i]].dest<<" weight "<<edges[cheapest[i]].weight<<endl;

                MSTweight+=edges[cheapest[i]].weight;

                Union(parent,set1,set2);

                numTrees--;
            }
        }
    }

    cout<<"Total MST Weight = "<<MSTweight<<endl;
}
