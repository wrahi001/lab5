#include <iostream>
#include <string>
#include "lab4.h"
using namespace std;

int main()
{
	Op op7(7);
	Op op4(4);
	Op op3(3);
	Op op2(2);

	Mult *A = new Mult(op7, op4);
	Add *B = new Add(A, op3);
	Sub *C = new Sub(B, op2);
	VectorContainer *container = new VectorContainer();
	container->add_element(A);
	container->add_element(B);
	container->add_element(C);
	container->print();
	return 0;
}
