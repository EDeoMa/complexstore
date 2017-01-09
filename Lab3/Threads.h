//Кудрявцев Дмитрий Борисович 
//БИВТ142 
//Вариант 7/3
//Что храним: Комплексные числа
//Вид хранилища: Список 

//Для выполнения поставленной задачи необходимо: 

//Переделать хранилище под шаблоны
//Разработать шаблонную функцию для сложения объектов классов «что храним»(разных типов)
//Использовать typedef и mutable

//Разработка потоков потребителей и производителей
//Использование механизма событий или слотов
//Использование мютексов или семафоров

#include "Mylist.h"
#include <csignal>

void SignalHandler(int sig) {
	cout << "Got signal " << sig << "\n";
}

public ref class clfunctions {
	string* textBox1;
	string* textBox2;
	Mutex^ m=gcnew Mutex();
public:
	clfunctions(string text1, string text2) {
		textBox1 = new string(text1);
		textBox2 = new string(text2);
	}
	void add(){
		if (m->WaitOne(5000)) {
			Thread::Sleep(10000);
			if (*textBox1 == "") {
				if (*textBox2 == "") {
					mlstp.add(new myfloat(0), 1);
				}
				else {
					mlstp.add(new complex(0, stof(*textBox2)), 1);
				}
			}
			else {
				if (*textBox2 == "") {
					mlstp.add(new myfloat(stof(*textBox1)), 1);
				}
				else {
					mlstp.add(new complex(stof(*textBox1), stof(*textBox2)), 1);
				}
			}
			cout << "Here";
			m->ReleaseMutex();
		}
		else cout << "Can't enter;" << endl;
	}
	void rename() {
		if (m->WaitOne(1000)) {
			if (!mlstp.out(numch)->type) {
				mlstp.out(numch)->setval(&myfloat(stof(*textBox1)));
			}
			else
				mlstp.out(numch)->setval(&complex(stof(*textBox1), stof(*textBox2)));
			m->ReleaseMutex();
		}
	}
};

class WorkerThread {
public:
	void Main(string textBox1, string textBox2) {
		clfunctions^ funcs = gcnew clfunctions(textBox1, textBox2);
		Thread^ working = gcnew Thread(gcnew ThreadStart(funcs, &clfunctions::add));
		working->Start();
		//raise(SIGINT);
	}
};

class ConsumeThread {
public:
	void Main(string textBox1, string textBox2) {
		clfunctions^ funcs = gcnew clfunctions(textBox1, textBox2);
		Thread^ consume = gcnew Thread(gcnew ThreadStart(funcs, &clfunctions::rename));
		consume->Start();
	}
};


//В итоге хранилище было переписано под шаблоны, в том числе все функции нового шаблонного класса стали шаблонными.
//Отдельно была определена функция сложения двух классов - родительского и производного, которая возвращает указатель на
//базовый тип.

//Были реализованы 2 потока - потребитель (изменение числа) и производитель (добавление числа в контейнер).
//Для более наглядной демонстрации один поток засыпает на 10 сек., после чего выводит в консоль "Here" - поток завершился.