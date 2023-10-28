#include "Dijkstra.h"
#include <fstream>

int main() {
	//TEST_1
	ofstream file_1("test_1_3.txt");
	ofstream file_2("test_1_15.txt");
	int q = 1;
	int r = 1000000;
	for (int n = 1; n <= 10001; n += 100) {
	    int m = n * n / 10;
		GRAPH g(n, m);
		g.graph_generation(n, m, q, r);
		g.LDG_DIJKSTRA_D_HEAP(0, 3);
		file_1 << n << " " << (double)g.wtime / CLOCKS_PER_SEC << endl;
		g.LDG_DIJKSTRA_D_HEAP(0, 15);
		file_2 << n << " " << (double)g.wtime / CLOCKS_PER_SEC << endl;
	}
	
	//-----------------------
	//TEST_2
	/*ofstream file_3("test_2_3.txt");
	ofstream file_4("test_2_15.txt");
	int q = 1;
	int r = 1000000;
	for (int n = 1; n <= 10001; n += 100) {
	    int m = n * n;
		GRAPH g(n, m);
		g.graph_generation(n, m, q, r);
		g.LDG_DIJKSTRA_D_HEAP(0, 3);
		file_3 << n << " " << (double)g.wtime / CLOCKS_PER_SEC << endl;
		g.LDG_DIJKSTRA_D_HEAP(0, 15);
		file_4 << n << " " << (double)g.wtime / CLOCKS_PER_SEC << endl;
	}*/

	//-----------------------
	//TEST_3 
	/*ofstream file_5("test_3_3.txt"); 
	ofstream file_6("test_3_15.txt");
	int q = 1;
	int r = 1000000;
	for (int n = 101; n <= 10001; n += 100) {
	    int m = n * 100;
		GRAPH g(n, m);
		g.graph_generation(n, m, q, r);
		g.LDG_DIJKSTRA_D_HEAP(0, 3);
		file_5 << n << " " << (double)g.wtime / CLOCKS_PER_SEC << endl;
		g.LDG_DIJKSTRA_D_HEAP(0, 15);
		file_6 << n << " " << (double)g.wtime / CLOCKS_PER_SEC << endl;
	}*/

	//-----------------------
	//TEST_4
	/*ofstream file_7("test_4_3.txt");
	ofstream file_8("test_4_15.txt");
	int q = 1;
	int r = 1000000;
	for (int n = 101; n <= 10001; n += 100) {
	    int m = n * 1000;
	    GRAPH g(n, m);
	    g.graph_generation(n, m, q, r);
	    g.LDG_DIJKSTRA_D_HEAP(0, 3);
	    file_7 << n << " " << (double)g.wtime / CLOCKS_PER_SEC << endl;
	    g.LDG_DIJKSTRA_D_HEAP(0, 15);
	    file_8 << n << " " << (double)g.wtime / CLOCKS_PER_SEC << endl;
	}*/

	//-----------------------
	//TEST_5
	/*ofstream file_9("test_5_3.txt");
	ofstream file_10("test_5_15.txt");
	int q = 1;
	int r = 1000000;
	int n = 10001;
	for (int m = 0; m <= 10000000; m += 100000) {
		GRAPH g(n, m);
		g.graph_generation(n, m, q, r);
		g.LDG_DIJKSTRA_D_HEAP(0, 3);
		file_9 << m << " " << (double)g.wtime / CLOCKS_PER_SEC << endl;
		g.LDG_DIJKSTRA_D_HEAP(0, 15);
		file_10 << m << " " << (double)g.wtime / CLOCKS_PER_SEC << endl;
	}*/

	//-----------------------
	//TEST_6
	/*ofstream file_11("test_6_3.txt");
	ofstream file_12("test_6_15.txt");
	int q = 1;
	int n = 10001;
	int i = 1;
	for (int r = 1; r <= 200; r += 1) {
		int m = n * n;
		GRAPH g(n, m);
		g.graph_generation(n, m, q, r);
		g.LDG_DIJKSTRA_D_HEAP(0, 3);
		file_11 << r << " " << (double)g.wtime / CLOCKS_PER_SEC << endl;
		g.LDG_DIJKSTRA_D_HEAP(0, 15);
		file_12 << r << " " << (double)g.wtime / CLOCKS_PER_SEC << endl;
		cout << i << endl;
		i++;
	}*/

	//-----------------------
	//TEST_7
	/*ofstream file_13("test_7_3.txt");
	ofstream file_14("test_7_15.txt");
	int q = 1;
	int n = 10001;
	for (int r = 1; r <= 200; r += 1) {
		int m = n * 1000;
		GRAPH g(n, m);
		g.graph_generation(n, m, q, r);
		g.LDG_DIJKSTRA_D_HEAP(0, 3);
		file_13 << r << " " << (double)g.wtime / CLOCKS_PER_SEC << endl;
		g.LDG_DIJKSTRA_D_HEAP(0, 15);
		file_14 << r << " " << (double)g.wtime / CLOCKS_PER_SEC << endl;
	}*/

	return 0;
}





































//#include <gtest.h>
//
//TEST(test_lib, test_1_3)
//{
//	int n = 10001;
//	for (int i = 1; i < n; i = i + 100) {
//		GRAPH g(i);
//		g.create_graph(i, 3, 1, 1000000);
//	}
//	EXPECT_EQ(8, v);
//}

//TEST(test_lib, test_1_15)
//{
//	int n = 10001;
//	GRAPH g(n);
//	double v = m.calc(2, 2, 1);
//	EXPECT_EQ(0.5, v);
//}

//TEST(test_lib, monom_with_positive_and_negative_degrees_at_the_point)
//{
//	Monom m(2, -1, 1, 1);
//	double v = m.calc(2, 2, 1);
//	EXPECT_EQ(2, v);
//}
//
//TEST(test_lib, the_monoms_are_equal) {
//	Monom m1(2, 1, 2, 1), m2(2, 1, 2, 1);
//	EXPECT_EQ(m1, m2);
//}
//
//TEST(test_lib, the_monoms_are_not_equal) {
//	Monom m1(2, 1, 2, 1), m2(1, 0, 0, 1);
//	EXPECT_NE(m1, m2);
//}
//
//TEST(test_lib, can_multiply_monom_and_number)
//{
//	Monom m1(4, 1, 4, 1), m3(20, 1, 4, 1);
//	Monom m2 = m1 * 5;
////	EXPECT_EQ(m3.calc(1, 1, 1), m2.calc(1, 1, 1));
//	EXPECT_EQ(m3, m2);
//}
//
//TEST(test_lib, can_multiply_monoms)
//{
//	Monom m1(2, 0, 0, 1), m2(4, 1, 4, 1), m4(8, 1, 4, 2);
//	Monom m3 = m1 * m2;
////	EXPECT_EQ(m4.calc(1, 1, 1), m3.calc(1, 1, 1));
//	EXPECT_EQ(m4, m3);
//}

 
 
//TEST(test_lib, polinom_at_the_point)
//{
//	Polinom p;
//	string polinom = "2x^1y^1z^0+3x^2y^0z^0-1";
//	istringstream p_in(polinom);
//	p_in >> p;
//	EXPECT_EQ(19, p.calc(2, 2, 5));
//}
//
//TEST(test_lib, the_polynoms_are_equal) {
//	Polinom p1, p2;
//	Monom m(2, 1, 2, 1), m1(1, 0, 0, 1);
//	p1.add(m);
//	p1.add(m1);
//	p1.add(1);
//	p2.add(m);
//	p2.add(1);
//	p2.add(m1);
//	EXPECT_EQ(p1, p2);
//}
//
//TEST(test_lib, the_polynoms_are_not_equal) {
//	Polinom p1, p2;
//	Monom m(2, 1, 2, 1), m1(1, 0, 0, 1);
//	p1.add(m);
//	p1.add(m1);
//	p1.add(2);
//	p2.add(m);
//	p2.add(1);
//	p2.add(m1);
//	EXPECT_NE(p1, p2);
//}
//
//TEST(test_lib, can_add_polinoms)
//{
//	Polinom p1, p2, p3, p4;
//	string polinom1 = "2x^1y^2z^1-1";
//	istringstream p_in1(polinom1);
//	p_in1 >> p1;
//	string polinom2 = "2x^1y^2z^1+3";
//	istringstream p_in2(polinom2);
//	p_in2 >> p2;
//	string polinom3 = "4x^1y^2z^1+2";
//	istringstream p_in3(polinom3);
//	p_in3 >> p3;
//	p4 = p1 + p2;
////	EXPECT_EQ(p3.calc(1,1,1), p4.calc(1,1,1));
//	EXPECT_EQ(p3, p4);
//}
//
//TEST(test_lib, can_subtract_polinoms)
//{
//	Polinom p1, p2, p3, p4;
//	string polinom1 = "2x^1y^2z^1-3";
//	istringstream p_in1(polinom1);
//	p_in1 >> p1;
//	string polinom2 = "2x^1y^2z^1+3";
//	istringstream p_in2(polinom2);
//	p_in2 >> p2;
//	string polinom3 = "-6";
//	istringstream p_in3(polinom3);
//	p_in3 >> p3;
//	p4 = p1 - p2;
////	EXPECT_EQ(p3.calc(1, 1, 1), p4.calc(1, 1, 1));
//	EXPECT_EQ(p3, p4);
//}
//
//TEST(test_lib, can_multiply_polinoms)
//{
//	Polinom p1, p2, p3, p4;
//	string polinom1 = "2x^1y^2z^1-3";
//	istringstream p_in1(polinom1);
//	p_in1 >> p1;
//	string polinom2 = "2x^1y^2z^1+3";
//	istringstream p_in2(polinom2);
//	p_in2 >> p2;
//	string polinom3 = "-9+4x^2y^4z^2";
//	istringstream p_in3(polinom3);
//	p_in3 >> p3;
//	p4 = p1 * p2;
////	EXPECT_EQ(p3.calc(1, 2, 1), p4.calc(1, 2, 1));
//	EXPECT_EQ(p3, p4);
//}
//
//TEST(test_lib, can_get_size_polinom)
//{
//	Polinom p;
//	string polinom = "2x^1y^2z^1-3";
//	istringstream p_in(polinom);
//	p_in >> p;
//	EXPECT_EQ(2, p.size());
//}
//
//TEST(test_lib, can_create_copied_polinom)
//{
//	Polinom p;
//	string polinom = "2x^1y^2z^1-3";
//	istringstream p_in(polinom);
//	p_in >> p;
//	ASSERT_NO_THROW(Polinom p1(p));
//}