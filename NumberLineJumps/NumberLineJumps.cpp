// Level : Easy
// Exercise : NumberLineJumps.cpp
// Topic  : Algorithms
// Comment : Es una pelotudes este problema , pero por algún motivo tenia la condición en la cabeza
//			 y perdí tiempo en poder escribirla bien.No me había quedado claro que ambos
//			 canguros hacían la misma cantidad de saltos.
// Author : RaulSosa

#include<iostream>
using namespace std;

void TestValidKangaroo(void);
void TestInvalidKangaroo(void);
void TestSuiteKangaroo(void);

int main(void){
	
	TestSuiteKangaroo();
	return 0;
}

string kangaroo(int x1, int v1, int x2, int v2) {
   return ((v1!=v2) && (v1>v2) && ((x2-x1)%(v1-v2)==0)) ? "YES" : "NO" ;
}
void TestValidKangaroo(void){
	int xA= 0 , vA = 3 , xB = 4 , vB = 2;
	cout <<(kangaroo(xA,vA,xB,vB) == "YES" ? "Test valid case: PASSED " : "Test valid case: FAILED ") << endl;
}
void TestInvalidKangaroo(void){
	int xA= 0 , vA = 2 , xB = 5 , vB = 3;
	cout << (kangaroo(xA,vA,xB,vB) == "NO" ? "Test invalid case: PASSED " : "Test valid case: FAILED ") << endl;
}
void TestSuiteKangaroo(void){
	TestValidKangaroo();
	TestInvalidKangaroo();
}
