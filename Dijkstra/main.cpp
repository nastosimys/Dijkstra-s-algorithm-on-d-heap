#include <iostream>
#include <fstream>
#include "Dijkstra.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Алгоритм Дейкстры на d-куче" << endl << endl;
	cout << "Введите число вершин: ";
	int n;
	cin >> n;
	cout << endl;
	int q = 0; //нижняя граница
	int r = 9; //верхняя граница
	int m = n * n;
	GRAPH gr(n, m);
	cout << "Матрица смежности графа:" << endl;
	gr.graph_generation(n, m, q, r);
	cout << endl;
	cout << "Алгоритм Дейкстры на 3-куче:" << endl;
	gr.LDG_DIJKSTRA_D_HEAP(0, 3);
	ofstream file_1("DIJKSTRA_D_HEAP_3.txt");
	file_1 << gr;
	cout << endl;
	cout << "Алгоритм Дейкстры на 15-куче:" << endl;
	gr.LDG_DIJKSTRA_D_HEAP(0, 15);
	ofstream file_2("DIJKSTRA_D_HEAP_15.txt");
	file_2 << gr;
	return 0;
}