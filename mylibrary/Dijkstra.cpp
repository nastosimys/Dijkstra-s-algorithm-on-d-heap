#include <iostream>
#include "Dijkstra.h"

using namespace std;

D_Heap :: D_Heap(int _n, int _d) {
	currentSize = 0;
	n = _n;
	d = _d;
	key = new int[n];
	name = new int[n];
	index = new int[n];
}

int D_Heap :: minchild(int i) {
	int kf, kl, min_key, minchild;
	kf = first_child(i);
	if (kf == 0)
		return i;
	else {
		kl = last_child(i);
		min_key = key[kf];
		minchild = kf;
		for (int j = kf + 1; j < kl + 1; j++) {
			if (key[j] < min_key) {
				min_key = key[j];
				minchild = j;
			}
		}
	}
	return minchild;
}

int D_Heap :: first_child(int i) {
	int k = i * d + 1;
	if (k >= currentSize)
		return 0;
	else return k;
}
 
int D_Heap :: last_child(int i) {
	int k = first_child(i);
	if (k == 0)
		return 0;
	else return min(k + d - 1, currentSize - 1);
}

int D_Heap :: father(int i) {
	return (i - 1) / d;
}

bool D_Heap :: isEmpty() {
	if (currentSize == 0)
		return true;
	return false;
}

bool D_Heap :: isFull() {
	if (currentSize == n)
		return true;
	return false;
}

int D_Heap :: get_min() {
	return key[0];
}

void D_Heap :: down(int i) {
	int key0 = key[i];
	int ind0 = name[i];  
	int c = minchild(i);
	while ((c != i) && (key0 > key[c])) {
		key[i] = key[c];
		name[i] = name[c];   
		index[name[i]] = i;  
		i = c;
		c = minchild(i);
	}
	key[i] = key0; 
	name[i] = ind0; 
	index[name[i]] = i; 
}

void D_Heap :: up(int i) {
	int key0 = key[i];
	int ind0 = name[i]; 
	int p = father(i);
	while ((i != 0) && (key[p] > key0)) {
		key[i] = key[p];
		name[i] = name[p];  
		index[name[i]] = i; 
		i = p;
		p = father(i);
	}
	key[i] = key0;
	name[i] = ind0; 

	index[name[i]] = i; 
}

void D_Heap :: delete_min() {
	int key0 = key[0];
	int ind0 = name[0]; 
	key[0] = key[currentSize - 1];
	name[0] = name[currentSize - 1]; 
	key[currentSize - 1] = key0;
	name[currentSize - 1] = ind0; 
	currentSize--;
	if (currentSize > 1)
		down(0);
}

void D_Heap :: form_queue() {
	for (int i = n; i >= 0; i--) {
		down(i);
	}
}

void D_Heap::insert(int x, int ind) { 
	if (isFull()) {
		cout << "Heap is full!" << endl;
		return;
	}
	int i = currentSize;
	key[i] = x;
	name[i] = ind;
	up(i);
	currentSize++;
}

void D_Heap :: decrease_weight(int w, int ind) {
	int t = index[ind];
	key[t] = w;
	up(t);
}

D_Heap :: ~D_Heap() {
	delete[] key;
	delete[] name;
	delete[] index;
}

GRAPH :: GRAPH(int _n, int _m) {
	n = _n;
	m = _m;
	arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
	dist = new int[n];
	upp = new int[n];
	wtime = 0;
	vizited = new bool[n];
}

GRAPH :: ~GRAPH() {
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
	delete[] dist;
	delete[] upp;
	delete[] vizited;
}

void GRAPH :: LDG_DIJKSTRA_D_HEAP(int s, int d) {
	wtime = clock();
	int current= 0;
	D_Heap h(n, d);
	for (int i = 0; i < n; i++) {
		upp[i] = 0;
		dist[i] = INT_MAX;
		vizited[i] = false;
	}
	dist[s] = 0;
	h.insert(0, s);
	while (!h.isEmpty()) {
		current = h.name[0];
		h.delete_min();
		for (int i = 0; i < n; i++) {
			int length = arr[current][i];
			int t = dist[current];
			int p = dist[i];
			if (dist[current] != INT_MAX && dist[i] > dist[current] + length && length > 0) {
				dist[i] = dist[current] + length;
				int r = dist[i];
				if (vizited[i] == true) {
					h.decrease_weight(r, i);
				}
				else {
					h.insert(r, i);
					vizited[i] = true;
				}
				upp[i] = current;
			}
		}
	}
	wtime = clock() - wtime;
	for (int i = 0; i < n; i++) {
		if (dist[i] == INT_MAX) {
			cout << "0 -> " << i << " = " << "infinity" << "  last: " << upp[i] << endl;
		}
		else {
			cout << "0 -> " << i << " = " << dist[i] << "  last: " << upp[i] << endl;
		}
	}
	/*cout << "n: " << n << "  " << "time: " << (double)wtime / CLOCKS_PER_SEC << endl;*/
	cout << "time: " << (double)wtime / CLOCKS_PER_SEC << endl;
}

ostream& operator<<(ostream& out, GRAPH& g) {
	/*for (int i = 0; i < g.n; i++) {
		out << "0 -> " << i << " = " << g.dist[i] << "  last: " << g.upp[i] << endl;
	}
	out << endl;
	out << "n: " << g.n << "  " << "time: " << (float)g.wtime / CLOCKS_PER_SEC << endl;*/
	out << (double)g.wtime / CLOCKS_PER_SEC << endl;
	return out;
}

void GRAPH :: graph_generation(int n, int m, int q, int r) {
	srand(time(NULL));
	int weight = 0;
	int edge = 0;
	int size = n * (n - 1) / 2;
	double p = (double)m / size;           //0.5;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			weight = rand() % (r - q + 1) + q;
			if (weight < p * RAND_MAX && edge <= m) {
				arr[i][j] = weight;
				arr[j][i] = weight;
				edge++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}