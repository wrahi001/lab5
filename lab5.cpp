#include <iostream>
#include <string>
#include "lab5.h"
#include <math.h>
using namespace std;

int main()
{
	double answer = 0;
	Op *op7 = new Op(7);
	Op *op4 = new Op(4);
	Op *op3 = new Op(3);
	Op *op2 = new Op(2);
	Op *dec = new Op(3.1416);
	Op *dec2 = new Op(-10.6);
	

	Mult *A = new Mult(op7, op4);
	Add *B = new Add(A, op3);
	Sub *C = new Sub(B, op2);
	Sqr *D = new Sqr(op7);
	Ceil *ceil_pointer = new Ceil(dec);
	Floor *floorp = new Floor(dec);

	cout << "the floor is " << floorp->evaluate() << endl;
	
	Abs *ab = new Abs(dec);
	Abs *ab2 = new Abs(dec2);
	cout << "Absolute value is: " << ab->evaluate() << endl;
	cout << "Absolute val of dec2 is: " << ab2->evaluate() << endl;
	/****************	
	VectorContainer *container = new VectorContainer();
	container->add_element(A);
	container->add_element(B);
	container->add_element(C);
	
	cout << "Container Before Sort: " << endl;
	container->print();

	cout << "Container After Sort: " << endl;
	container->set_sort_function(new BubbleSort());
	container->sort();
	//BubbleSort* bub = new BubbleSort();
	//bub->sort(container);
	container->print();
/*********************/	

	return 0;
}
