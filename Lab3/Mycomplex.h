//Кудрявцев Дмитрий Борисович 
//БИВТ142 
//Вариант 7/3
//Что храним: Комплексные числа
//Вид хранилища: Список 
//Для выполнения поставленной задачи необходимо создать операторы: 
//3 арифметических 
//операторы инкремента / декремента (префиксный и постфиксный)
//операторы << >> для ввода / вывода
//Оператор индексации
//Оператор()
//Оператор присваивания
//Оператор сравнения, 2 логических
//Побитовые операторы

#include"Myfloat.h"

using namespace System::Threading;

class complex:public myfloat {
private:

public:
	float y;//y*i
	complex();
	complex(float, float);
	complex(const complex&);
	~complex();
	complex sum(complex);//сумма двух
	complex sum(myfloat&);//сумма двух
	complex subtract(complex);//вычитание
	complex& multiply(float);//умножение на число
	complex& multiply(complex);//умножение на число
	complex& operator=(const complex&);
	complex& operator++();
	complex operator++(int);
	complex& operator--();
	complex operator--(int);
	friend bool operator>(complex&, complex&);
	bool operator==(complex&) const;
	bool operator&&(complex&) const;
	bool operator||(complex&) const;
	friend complex& operator&(const complex&, const complex&);
	friend complex& operator|(const complex&, const complex&);
	istream& operator>>(istream&);
	friend ostream& operator<<(ostream& os, const complex& cmp);
	void operator()(complex);
	virtual float gety();
	virtual void setval(myfloat*);
	virtual string printout();//вывод на экран числа
	virtual void printnum();
};

template <class T1, class T2> myfloat* sumall(T1 _f, T2 _s) {
	if (typeid(T1)==typeid(T2)) {
		T1* temp = new T1(_f.sum(_s));
		return temp;
	}
	else {
		if (typeid(T1) == typeid(complex) ) {
			T1* temp=new T1;
			temp->setval(&_f);
			temp->x+= _s.getx();
			return temp;
		}
		else {
			T2* temp=new T2;
			temp->setval(&_s);
			temp->x += _f.getx();
			return temp;
		}
	}
}

ostream& operator<<(ostream& os,const complex& cmp){
	os << cmp.x<<" "<< cmp.y<<endl;
	return os;
}

bool operator>(complex& _1, complex& _2) {
	return (sqrt(pow(_1.x,2)+pow(_1.y,2))>sqrt(_2.x*_2.x + _2.y*_2.y));
}

void complex::operator()(complex a) {
	x = a.x;
	y = a.y;
}

bool complex::operator==(complex& cmp2) const {
	return((x == cmp2.getx()) && (y == cmp2.gety()));
}

bool complex:: operator&&(complex& cmp) const {
	return(x&&cmp.x || y&&cmp.y);
}
bool complex::operator||(complex& cmp) const {
	return(x || cmp.x || y || cmp.y);
}
complex& operator&(const complex& cmp,const complex& cmp2){
	return complex((int) cmp.x &(int)cmp2.x, (int)cmp.y&(int)cmp2.y);
}
complex& operator|(const complex& cmp,const complex& cmp2){
	return complex((int)cmp.x | (int)cmp2.x, (int)cmp.y| (int)cmp2.y);
}

complex& complex::operator++() {
	x++;
	y++;
	return *this;
}

complex complex::operator++(int) {
	complex temp = *this;
	++*this;
	return temp;
}

complex& complex::operator--() {
	x--;
	y--;
	return *this;
}

complex complex::operator--(int) {
	complex temp = *this;
	--*this;
	return temp;
}

istream& complex::operator>>(istream& is) {
	is >> x >> y;
	return is;
}

complex& complex:: operator=(const complex& right) {
	if (this == &right) {
		return *this;
	}
	x = right.x;
	y = right.y;
	return *this;
}


complex::complex() {
	x = y = 0;
	type = 1;
}

complex::complex(float a, float b) {
	x = a;
	y = b;
	type = 1;
}

complex::complex(const complex& a) {
	this->x = a.x;
	this->y = a.y;
	type = 1;
}

complex::~complex() {

}

complex complex::sum(complex a) {
	complex b(a.x + x, a.y + y);
	return b;
}

complex complex::sum(myfloat& a) {
	complex b(a.getx() + x, y);
	return b;
}

complex& complex::multiply(float a) {
	this->x *= a;
	this->y *= a;
	return *this;
}

complex & complex::multiply(complex b)
{
	this->x = x*b.getx()-y*b.y;
	this->y *= x*b.y+y*b.x;
	return *this;
}

complex complex::subtract(complex a) {
	a.numul(-1);
	return sum(a);
}

string complex::printout() {//выводим число в каноническом виде a+bi
	string output = "";
	output += to_string(this->x);
	if (this->y != 0) {
		if (this->y > 0)
			output += "+";
		output += to_string(this->y);
		output += "i\n";
	}
	return output;
}

float complex::gety() {
	return y;
}

void complex::setval(myfloat* a) {
	x = a->x;
	y = a->gety();
}


void complex::printnum() {//выводим число в каноническом виде a+bi
	cout <<this->getx();
	if (this->gety() != 0) {
		if (this->gety() > 0)
			cout << "+";
		cout << this->gety();
		cout << "i\n";
	}
}

//В итоге было определено около 19ти операторов, наибольшую проблему из которых поставил оператор вывода в поток.
//Явного оператора сравнения для комплексных чисел нет, поэтому оператор сравнения сравнивает числа по модулю.
//Все остальные операторы были реализованы без особых сложностей.