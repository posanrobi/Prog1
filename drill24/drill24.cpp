//kismertekben lehet modositani meg a drilleket (1-2 feladatot), pl. ciklusokat
#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main()
try{

	cout << "sizeof:\n";
	cout << "char\t" << sizeof(char) << endl;
	cout << "short\t" << sizeof(short) << endl;
	cout << "int\t" << sizeof(int) << endl;
	cout << "long\t" << sizeof(long) << endl;
	cout << "float\t" << sizeof(float) << endl;
	cout << "double\t" << sizeof(double) << endl;
	cout << "int*\t" << sizeof(int*) << endl;
	cout << "double*\t" << sizeof(double*) << endl;
	cout << "long*\t" << sizeof(long*) << endl;
	cout << "float*\t" << sizeof(float*) << endl;

	cout << "Matrix sizes: " << endl;
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int, 2> d(10,10);
	Matrix<int, 3> e(10,10,10);

	cout << "1D int, 10 elem\t\t" << sizeof(a) << endl;
	cout << "1D int, 100 elem\t\t" << sizeof(b) << endl;
	cout << "1D int, 10 elem\t\t" << sizeof(c) << endl;
	cout << "2D int, 10x10 elem\t\t" << sizeof(d) << endl;
	cout << "3D int, 10x10x10 elem\t\t" << sizeof(e) << endl;

	cout << "Number of elements:" << endl;
	cout << "a:\t" << a.size() << endl;
	cout << "b:\t" << b.size() << endl;
	cout << "c:\t" << c.size() << endl;
	cout << "d:\t" << d.size() << endl;
	cout << "e:\t" << e.size() << endl;

	cout << endl;
	int value;
	while(cin){
		cout << "Enter an int value: ";
		cin >> value;
		if (value < 0){
			cout << "no square root" << endl;
		}
		else {
			cout << "Square root of " << value << " is: " << sqrt(value) << endl;
		}
	}

	cin.clear(); //hibak megsemmisitese, eltarolt hibakat torli, a jovobeli i/o muveletek jol fognak miatta mukodni
	cin.ignore(); //minden mas fajta hibat ignoral, karaktert torol a bufferbol
	cout << "\nEnter 10 floats: ";
	Matrix<double> mm(10);
	double d2;
	for(int i = 0; i < mm.size(); ++i){
			cin >> d2;
			if(!cin) throw runtime_error("Error while reading from cin!");
			mm[i] = d2;
		
	}
	cout << "Matrix:\n" << mm << '\n';

	//szorzotabla
	int n;
	int m;
	cout << endl << "Multiplication table" << endl;
	cout << "Enter n: "; cin >>  n;
	cout << "Enter m: "; cin >> m;
	cout << endl;

	Matrix<int, 2> mt(n,m);
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j)
		{
			mt(i,j) = (i+1)*(j+1);
			cout << setw(4) << mt(i,j);
		}
		cout << endl;
	}

	//komplex szamokat tartalmazo matrix
	Matrix<complex<double>> mc(10);
	cout << "\nEnter 10 complex numbers (Re, Im): ";
	complex<double> comp;
	for(int i = 0; i < 10; ++i){
		cin >> comp;
		if(!cin) throw runtime_error("Problem reading complex number!");
		mc[i] = comp;
	}
	complex<double> sum; //complex<double> (= komplex) tipusu lesz a sum
	for (Index i = 0; i < mc.size(); ++i){
		sum += mc[i];
	}
	cout << "Sum: " << sum << endl;

	//2x3as vektor keszitese
	cout << "\nMatrix(2,3):" << endl;
	cout << "Enter 6 ints: ";
	Matrix<int, 2> m_two_d(2,3);
	for (int i = 0; i < 2; ++i){
		for (int j = 0; j < 3; ++j){
			//cin >> m_two_d[i][j]; //ugyanugy mukodik
			cin >> m_two_d(i,j);
			cout << setw(4) << m_two_d(i,j);
		}
		cout << endl;
	}

}catch(exception& e){
	cerr << "Exception: " << e.what() << endl;
	return 1;
}
catch(...){
	cerr << "Unknown exception" << endl;
	return 2;
}