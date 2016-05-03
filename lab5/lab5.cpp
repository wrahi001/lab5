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
	Op *dec3 = new Op(2.5);
	

	Mult *A = new Mult(op7, op4);
	Add *B = new Add(A, op3);
	Sub *C = new Sub(B, op2);
	Sqr *D = new Sqr(op7);
	Ceil *ceil_pointer = new Ceil(dec);
	Ceil *ceil2 = new Ceil(dec2);
	Ceil *ceil3 = new Ceil(dec3);
	Ceil *ceil4 = new Ceil(C);
	Floor *floor1 = new Floor(dec);
	Floor *floorp = new Floor(dec2);
	Floor *floor3 = new Floor(dec3);
	Abs *ab = new Abs(dec);
	Abs *ab2 = new Abs(dec2);
	Abs *ab3 = new Abs(dec3);

	cout << "The ceiling of 3+7*4-2 is: " << ceil4->evaluate() << endl;

	cout << "The ceiling of 3.1416 is: " << ceil_pointer->evaluate() << endl;
	cout << "The ceiling of -10.6 is: " << ceil2->evaluate() << endl;
	cout << "The ceiling of 2.5 is: " << ceil3->evaluate() << endl;
	cout << "The floor of 3.1416 is: " << floor1->evaluate() << endl;
	cout << "The floor of -10.6 is: " << floorp->evaluate() << endl;
	cout << "The floor of 2.5 is: " << floor3->evaluate() << endl;
	cout << "The abs of 3.1416 is: " << ab->evaluate() << endl;
	cout << "The abs of -10.6 is: " << ab2->evaluate() << endl;
	cout << "The abs of 2.5 is: " << ab3->evaluate() << endl;
	

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
