#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <math.h>
using namespace std;

class Base
{
	public:
	Base(){};
	virtual double evaluate() = 0;
};
class Floor : public Base
{
	public:
		Floor(Base* sub_pointer)
		{
			node_pointer = sub_pointer;
		}
		double evaluate()
		{
			return floor(node_pointer->evaluate());
		}
	private:
		Base *node_pointer;
};
class Ceil : public Base
{
	public:
		Ceil(Base* sub_pointer)
		{
			node_pointer = sub_pointer;
		}
		double evaluate()
		{
			return ceil(node_pointer->evaluate());
		}
	private:
		Base *node_pointer;
};

class Abs : public Base {
	public:
		Abs(Base* p) {
			node_pointer = p;
		}
		double evaluate() {
			return fabs(node_pointer->evaluate());
		}
	private:
		Base *node_pointer;
};

class Op : public Base
{
	public:
		Op() {}
		Op(double input)
		{
			value = input;
		}
		double evaluate()
		{
			return value;
		}
	private:
		double value;

};

class Mult : public Base
{
	public:
		Mult() {}
		Mult(Base* input_op, Base* input2)
		{
			op1 = input_op;
			op2 = input2;
		}
		double evaluate()
		{
			return (op1->evaluate() * op2->evaluate());		
		}
	private:
		Base* op1;
		Base* op2;
		

};

class Div : public Base
{
	public:
		Div() {}
		Div(Base* input1, Base* input2)
		{
			op1 = input1;
			op2 = input2;
		}
		double evaluate()
		{
			return(op1->evaluate() / op2->evaluate());
		}
	private:
		Base* op1;
		Base* op2;
};

class Add : public Base
{
	public:
		Add() {}
		Add(Base* input1, Base* input2)
		{
			op1 = input1;
			op2 = input2;
		}
		double evaluate()
		{
			return(op1->evaluate() + op2->evaluate());
		}
	private:
		Base* op1;
		Base* op2;
};

class Sqr : public Base
{
	public:
		Sqr() {}
		Sqr(Base* input)
		{
			op1 = input;
		}
		double evaluate()
		{
			return(sqrt(op1->evaluate())) ;
		}
	private:
		Base* op1;
};


class Sub : public Base
{
	public:
		Sub() {}
		Sub(Base* input1, Base* input2)
		{
			op1 = input1;
			op2 = input2;
		}
		double evaluate()
		{
			return(op1->evaluate() - op2->evaluate());
		}
	private:
		Base* op1;
		Base* op2;
};

class Sort;
class Container
{
	protected:
		Sort* sort_function;

	public:
		Container(): sort_function(NULL){};
		Container(Sort* function) : sort_function(function){};
		void set_sort_function(Sort* sort_function){
			this->sort_function = sort_function;
		}
		virtual void add_element(Base* element) =0;
		virtual void print() = 0;
		virtual void sort() = 0;
		virtual void swap(int i, int j) = 0;
		virtual Base* at(int i) = 0;
		virtual int size() = 0;
};

class Sort {
	public:
		Sort() {}
		virtual void sort(Container* container) = 0;
};



class VectorContainer : public Container {
	protected:
		vector<Base*> baseVect;
	public:
		void add_element(Base* element){
			baseVect.push_back(element);
		}
		void print(){
			for (int i = 0; i < baseVect.size(); i++) {
				cout << baseVect.at(i)->evaluate() << ' ';
			}
			cout << endl;
		}
		void swap(int i, int j) {
			Base* temp = baseVect.at(i);
			baseVect.at(i) = baseVect.at(j);
			baseVect.at(j) = temp;
		}
		Base* at(int i) {
			return baseVect.at(i);
		}
		int size() {
			return baseVect.size();
		}
		void sort() {
			sort_function->sort(this);
		}

};

class BubbleSort : public Sort {
	public:
		BubbleSort() {}
		void sort(Container* container) {
			for (int i = 0; i < container->size(); i++) {
					for (int j = 0; j < container->size(); j++) {
						if (container->at(i)->evaluate() < container->at(j)->evaluate()) {
							container->swap(i,j);
						}
				}
			}
		}
};


class ListContainer : public Container {
	protected:
		list<Base*> baseList;
	public:
		void add_element(Base* element) {
			baseList.push_back(element);
		}
		void print() {
			list<Base*>::const_iterator itr;
			for (itr = baseList.begin(); itr != baseList.end(); ++itr) {
				cout <<( *itr)->evaluate() << endl;
			}
		}
		void sort() {};
		void swap(int i, int j) {
		}
		Base* at(int i) {
			list<Base*>::const_iterator itr = baseList.begin();
			for(int j = 0; j < i; j++){
				++itr;
			}
			return *itr;
		}
		int size() {
			return baseList.size();
		}
};
