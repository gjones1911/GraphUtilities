#include "node.h"

/*Node functions*/
node::node()
{
	adj.clear();
	val = NULL;
	v = -1;
	next = NULL;
	prev = NULL;
}

node::~node()
{

}

int node::getIdx()
{
	return idx;
}

void *  node::getVal()
{
	return val;
}

void TracePath(node * sn)
{
	node* np = sn;

	while(np->next != NULL)
	{
		printf("node: %d\n", sn->idx);
		np = np->next;
	}
}

/*Graph functions*/
void graph::Print()
{
	int i, j, k;

	if(Graph.size() == 0)
	{
		cout<<"no nodes in graph\n";
		return;
	}

	for(i = 0; i < Graph.size();i++)
	{
		cout<<"node : "<<Graph.at(i)->idx<<"\n";
		cout<<"Edges with : ";

		for(j = 0; j < Graph.at(i)->adj.size();j++)
		{
			cout<<Graph[i]->adj[j]<<" ";
		}

		cout<<"\n";
	}

	cout<<"\n";

	return;
}

void graph::Reset(int zo)
{
	int i, j, k;

	node * np;

	for(i = 0 ; i < Graph.size() ; i++)
	{
		np = Graph[i];

		np->v = -1;

		if(zo == 1)
		{
			np->adj.clear();
			np->next = NULL;
			np->prev = NULL;
			np->dist = 0;
		}
	}

	return;
}

/*This takes the index of one of the nodes in the graph
 * and will move through the graph looking for a cycle
 * (node repeated in the path) and if found will return 1, 
 * otherwise it will return -1*/
int graph::Has_cycle(int idx)
{
	int i, j, k;

	node * np;

	np = Graph[idx];

	if(np->v != -1) return 1;

	np->v = 1;

	for(i = 0; i < np->adj.size(); i++)
	{
		if( Has_cycle( np->adj[i] ) ) return 1;
	}

	return 0;
}


/*
 *This will count the number of non connected components in the graph.
  This function is used inside the function Component_number.
  A node that has not been visited has a v = -1, otherwise it is the cn
  If the given node has not been visited it will do a dfs on the node marking 
  all possible reachable nodes with the current component number(cn), in each 
  iteration of the loop the cn should be incremented.the final cn is the total 
  non connected component count.
 * */
void graph::component_cnt(int idx, int cn)
{
	node *np;

	np = Graph[idx];

	if( np->v != -1 ) return ;

	//store this node's component number as it's v field
	np->v = cn;

	for(int j = 0 ; j < Graph[idx]->adj.size() ; j++)
	{
		component_cnt(np->adj[j], cn );
	}

	return ;

}

/*Given a graph it will count the number of non connected componets*/
int graph::Component_number()
{
	int cnt = 0, i = 0;

	for(i = 0; i < Graph.size(); i++)
	{
		if(Graph[i]->v == -1)
		{
			cnt++;
			component_cnt(i,cnt);

		}
	}

	return cnt;
}


/*Will seek a path from the start node(sn) to the end node(en) 
 *if one exists and returns a 1. If there is no path a 0 is returned.
 * */
int  graph::PathFinder(node * sn, node * en)
{
	int Nidx = 0;

	//if the current node is the one sought return 1
	if( en->getIdx() == sn->getIdx() ) return 1;

	vector<int> path;

	for(int i = 0; i < sn->adj.size(); i++)
	{
		path.push_back(sn->adj[i]);

		Nidx = sn->adj[i];

		sn->next = Graph[Nidx];

		if( PathFinder(Graph[sn->adj[i]], en ) == 1) return 1;

		path.pop_back();
		sn->next = NULL;
	
	}

	return 0;
}


vector<int> graph::shortest(node *sn, node en)
{
	vector<int> sp;
	sp.clear();

	return sp;
}



