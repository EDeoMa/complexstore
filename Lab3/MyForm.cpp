#include "MyForm.h"

using namespace Lab3;

int main() {
	/*complex a(2, 3), b(3, 4);
	myfloat c(5), d(7);
	cout << sumall(a, b)->printout() << sumall(a, c)->printout() << sumall(c, b)->printout() << sumall(c, d)->printout()<<endl;
	system("pause");*/
	signal(SIGINT, SignalHandler);
	MyForm fm;
	fm.ShowDialog();
	return 0;
}