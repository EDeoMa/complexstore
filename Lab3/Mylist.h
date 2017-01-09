#include "Mycomplex.h"

#include <list>
#include <iterator>
#include <algorithm>

template <class T> class mylist {
private:
	list <T> mlist;//������ �� STL
public:
	mylist();
	mylist(T);
	mylist(const mylist&);
	~mylist();
	T erase(int);//�������� �������� �� ������
	T out(int);//����� �������� ������ �� �����
	void printall();
	void add(T, int);//���������� �������� � ������
	int getsize();//getter ��� ��������� ����� ������ (�.�. ��������� ���������� - private)
	void setc(T, int);
	bool checkpos(int pos);
	T operator[](int);

};

template <class T> mylist<T>::mylist() {
	mlist = list<T>();//����������� ������ �������
}

template <class T> mylist <T>::mylist(T a) {
	mlist._Construct_n(1, a);//������������� ���������
}

template <class T> mylist <T>::mylist(const mylist& a) {
	mlist.operator=(a.mlist);//����������� ������ � ������ ������
}

template <class T> mylist <T>::~mylist() {

}

template <class T> T mylist <T>::erase(int pos) {//�������� � ������� �������� � ����������� �������
	list<T>::iterator it = mlist.begin();
	advance(it, pos - 1);
	T a = *it;
	mlist.erase(it);
	return a;
}

template <class T> T mylist <T>::out(int pos) {//������� �������� � ����������� �������
	list<T>::iterator it = mlist.begin();
	advance(it, pos - 1);
	return *it;
}

template <class T> void mylist <T>::add(T addit, int pos) {//���������� �������� �� ����������� �������
	if (!checkpos(pos)) {
		list<T>::iterator it = mlist.begin();
		advance(it, pos - 1);
		mlist.insert(it, addit);
	}
	else
		if (pos == getsize() && pos>0 || pos == 0 && getsize() == 0)
			mlist.push_back(addit);
		else exit(1);
}

template <class T> void mylist <T>::printall() {
	list<T>::iterator it = mlist.begin();
	while (it != mlist.end()) {
		(**it).printnum();
		advance(it,1);
	}
}

template <class T> int mylist <T>::getsize() {//��������� ����� ������
	return(mlist.size());
}

template <class T> void mylist <T>::setc(T a, int pos) {//setter ��� ��������� �����
	list<T>::iterator it = mlist.begin();
	advance(it, pos - 1);
	(*it)->setval(*a);
}

template <class T> bool mylist <T>::checkpos(int pos) {
	if (getsize() == 0 && pos == 1)
		return 0;
	if (pos > getsize() || pos <= 0)
		return 1;
	else return 0;
}

template<class T> T mylist<T>::operator[](int i){
	list<T>::iterator it = mlist.begin();
	advance(it, i);
	return *it;
}
mylist <myfloat*> mlstp;
int numch;
