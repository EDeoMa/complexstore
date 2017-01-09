#pragma once

#include "MyForm1.h"
#include <fstream>
#include <vector>

namespace Lab3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm()
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::CheckedListBox^  checkedListBox1;
	private: System::Windows::Forms::Button^  button4;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(36, 39);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(148, 26);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 42);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"X";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 78);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Y";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(36, 75);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(148, 26);
			this->textBox2->TabIndex = 4;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(13, 14);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox1->Size = System::Drawing::Size(205, 124);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ввод";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 139);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(206, 39);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(412, 14);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(105, 77);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Сохранить в файл";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(225, 139);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(179, 39);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Редактировать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(225, 14);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(181, 109);
			this->checkedListBox1->TabIndex = 9;
			this->checkedListBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::checkedListBox1_SelectedIndexChanged);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(413, 91);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(104, 87);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Прочитать из файла";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(532, 188);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
		public:
			/*void add() {
				if (textBox1->Text == "") {
					if (textBox2->Text == "") {
						mlstp.add(new myfloat(0), 1);
					}
					else {
						mlstp.add(new complex(0, stof(msclr::interop::marshal_as<std::string>(textBox2->Text))), 1);
					}
				}
				else {
					if (textBox2->Text == "") {
						mlstp.add(new myfloat(stof(msclr::interop::marshal_as<std::string>(textBox1->Text))), 1);
					}
					else {
						mlstp.add(new complex(stof(msclr::interop::marshal_as<std::string>(textBox1->Text)), stof(msclr::interop::marshal_as<std::string>(textBox2->Text))), 1);
					}
				}
				updatechlst();
			}*/
			void updatechlst() {
				checkedListBox1->Items->Clear();
				cout << "upd";
				for (int i = 1; i <= mlstp.getsize(); i++)
				{
					checkedListBox1->Items->Add(gcnew String(mlstp.out(i)->printout().c_str()));
				}
				textBox1->Clear();
				textBox2->Clear();
			}
#pragma endregion
	private:
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			WorkerThread* wt = new WorkerThread;
			wt->Main(msclr::interop::marshal_as<std::string>(textBox1->Text), msclr::interop::marshal_as<std::string>(textBox2->Text));
			updatechlst();
		/*if (textBox1->Text == "") {
			if (textBox2->Text == "") {
				mlstp.add(new myfloat(0), 1);
			}
			else {
				mlstp.add(new complex(0, stof(msclr::interop::marshal_as<std::string>(textBox2->Text))), 1);
			}
		}
		else {
			if (textBox2->Text == "") {
				mlstp.add(new myfloat(stof(msclr::interop::marshal_as<std::string>(textBox1->Text))), 1);
			}
			else{
				mlstp.add(new complex(stof(msclr::interop::marshal_as<std::string>(textBox1->Text)), stof(msclr::interop::marshal_as<std::string>(textBox2->Text))), 1);
			}
		}
		updatechlst();*/
	}
private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	int CheckedCount = 0;
	for (int i = 0; i < checkedListBox1->Items->Count; i++)
	{
		if (checkedListBox1->GetItemChecked(i))
		{
			CheckedCount++;
			numch = i;
		}
	}
	if (CheckedCount != 1)
		button3->Enabled = false;
	else button3->Enabled=true;
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	MyForm1^ fm1=gcnew MyForm1();
	fm1->Owner = this;
	fm1->ShowDialog(); // показываем
	updatechlst();
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		ofstream fout;
		fout.open("res.txt");
		for (int i = 0; i < checkedListBox1->Items->Count; i++)
		{
			cout << i << ' ' << mlstp.out(i + 1)->type<<endl;
			fout << mlstp.out(i+1)->type << ' ' << mlstp.out(i+1)->getx() << ' ' << mlstp.out(i+1)->gety() << endl;
		}
		fout.close();
	}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	ifstream fin;
	int typ;
	float a, b;
	fin.open("res.txt");
	while (!fin.eof()){
			fin >> typ;
			if (fin.eof())
				break;
			else {
				fin >> a >> b;
				if (typ)
				{
					mlstp.add(new complex(a, b), 1);
				}
				else {
					mlstp.add(new myfloat(a), 1);
				}
			}
		}
	updatechlst();
	fin.close();
}
};
}
