#include <iostream>
#include <fstream>
#include "Dijkstra.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "�������� �������� �� d-����" << endl << endl;
	cout << "������� ����� ������: ";
	int n;
	cin >> n;
	cout << endl;
	int q = 0; //������ �������
	int r = 9; //������� �������
	int m = n * n;
	GRAPH gr(n, m);
	cout << "������� ��������� �����:" << endl;
	gr.graph_generation(n, m, q, r);
	cout << endl;
	cout << "�������� �������� �� 3-����:" << endl;
	gr.LDG_DIJKSTRA_D_HEAP(0, 3);
	ofstream file_1("DIJKSTRA_D_HEAP_3.txt");
	file_1 << gr;
	cout << endl;
	cout << "�������� �������� �� 15-����:" << endl;
	gr.LDG_DIJKSTRA_D_HEAP(0, 15);
	ofstream file_2("DIJKSTRA_D_HEAP_15.txt");
	file_2 << gr;
	return 0;
}