#include <iostream>
#include <string>

using namespace std;

typedef int myint;

class myfloat {
protected:

public:
	mutable float x;
	myint type;
	myfloat();
	myfloat(float);
	myfloat(const myfloat&);
	~myfloat();
	myfloat sum(myfloat);//сумма двух
	myfloat subtract(myfloat);//вычитание
	myfloat& numul(float);//умножение на число 
	float getx();
	virtual float gety() { return 0; };
	virtual void setval(myfloat*) const;
	virtual string printout();//вывод на экран числа
	myfloat& operator=(const myfloat&);
	virtual void printnum();
};


myfloat::myfloat() {
	x = 0;
	type = 0;
}

myfloat::myfloat(float _x) {
	this->x = _x;
	type = 0;
}

myfloat::myfloat(const myfloat& t) {
	this->x = t.x;
	type = 0;
}

myfloat::~myfloat(){

}

float myfloat::getx() {
	return x;
}

myfloat myfloat::sum(myfloat a) {
	myfloat b(a.x + x);
	return b;
}

myfloat& myfloat::numul(float a) {
	this->x *= a;
	return *this;
}

myfloat myfloat::subtract(myfloat a) {
	a.numul(-1);
	return sum(a);
}

string myfloat::printout() {//выводим число в каноническом виде a+bi
	return to_string(this->x);
}

void myfloat::setval(myfloat* a) const {
	x = a->x;
}

myfloat& myfloat:: operator=(const myfloat& right) {
	if (this == &right) {
		return *this;
	}
	x = right.x;
	return *this;
}

void myfloat::printnum() {//выводим число в каноническом виде a+bi
	cout << this->getx()<<endl;
}