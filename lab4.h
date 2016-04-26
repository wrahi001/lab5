#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

class Base
{
	public:
	Base(){};
	virtual double evaluate() = 0;
};
class Op : public Base
{
	public:
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
		Mult(Op input_op, Op input2)
		{
			op1 = input_op;
			op2 = input2;
		}
		double evaluate()
		{
			return (op1.evaluate() * op2.evaluate());		
		}
	private:
		Op op1;
		Op op2;
		

};

class Div : public Base
{
	public:
		Div(Op input1, Op input2)
		{
			op1 = input1;
			op2 = input2;
		}
		double evaluate()
		{
			return(op1.evaluate() / op2.evaluate());
		}
	private:
		Op op1;
		Op op2;
};

class Add : public Base
{
	public:
		Add(Mult input1, Op input2)
		{
			op1 = input1;
			op2 = input2;
		}
		double evaluate()
		{
			return(op1.evaluate() + op2.evaluate());
		}
	private:
		Mult op1;
		Op op2;
};

class Sqr : public Base
{
	public:
		Sqr(Op input)
		{
			op1 = input;
		}
		double evaluate()
		{
			return(op1.evaluate()*op1.evaluate()) ;
		}
	private:
		Op op1;
};


class Sub : public Base
{
	public:
		Sub(Add input1, Op input2)
		{
			op1 = input1;
			op2 = input2;
		}
		double evaluate()
		{
			return(op1.evaluate() - op2.evaluate());
		}
	private:
		Add op1;
		Op op2;
};

class Sort;
class Container
{
	protected:
		Sort* sort_function;

	public:
		Container(): sort_function(NULL){};
		Container(Sort* function) : sort_function(function){};
		void set_sort_function(Sort* sort_function){/*
			delete sort_function;
			if (sort_function == VectorContainer) {
				sort_function = new VectorContainer();
			}
			else if (sort_function == ListContainer) {
				sort_function = new ListContainer();}*/}
		virtual void add_element(Base* element) =0;
		virtual void print() = 0;
		virtual void sort() = 0;
		virtual void swap(int i, int j) = 0;
		virtual Base* at(int i) = 0;
		virtual int size() = 0;
};

class Sort {
	public:
		Sort();
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
				cout << baseVect.at(i)->evaluate();
			}
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
		void sort() {}

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
			list<Base*>::const_iterator itr;
			for(int j = 0; j < i; j++){
				++itr;
			}
			return *itr;
		}
		int size() {
			return baseList.size();
		}
};
