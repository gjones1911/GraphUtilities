#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;


//a node in a graph
class node
{
	public:
		//public data
		vector<int> adj;    //the adjacent list for the node
		int v;              //the nodes visited field
		node * next;
		node * prev;
		int dist;			//distance from start node
		
		
		//functions
		node();
		~node();
		int getIdx();
		void* getVal();
		void TracePath(node * sn);

		int idx;            //the index in the graph where this node resides
		void * val;        //will hold some form of informaiton
};

class graph
{
	public:
		vector <node *> Graph;
		void GInit(int num);
		int Has_cycle(node * np);
		int Component_number();
		int  PathFinder(node * sn, node * en);
		vector<int> shortest(node *sn, node en);
		void Print();
		void Reset(int zo);
		int Has_cycle(int idx);      //will till if a cycle exits
		void  component_cnt(int idx, int cn);  //counts # of connected components

};


/*Graph functions*/

/*Node functions*/

