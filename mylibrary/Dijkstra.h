#pragma 
#include <iostream>

using namespace std;

class D_Heap {
public:
	int currentSize;
	int d;
	int n;
	int* key;
	int* name; 
	int* index;
public:
	D_Heap(int _n, int _d = 2);
	int minchild(int i);
	int first_child(int i);
	int last_child(int i);
	int father(int i);
	bool isEmpty();
	bool isFull();
	int get_min();
	void down(int i);
	void up(int i); 
	void delete_min();
	void form_queue();
	void insert(int x, int ind);
	void decrease_weight(int w, int ind);
	~D_Heap();
};

class GRAPH {
public:
	int n;
	int m;
	int** arr;
	int* dist;
	int* upp;
	clock_t wtime;
	bool* vizited;
public:
	GRAPH(int _n, int _m);
	void graph_generation(int n, int m, int q, int r);
	void  LDG_DIJKSTRA_D_HEAP(int s, int d);
	friend ostream& operator<<(ostream& out, GRAPH& g);
	~GRAPH();
};