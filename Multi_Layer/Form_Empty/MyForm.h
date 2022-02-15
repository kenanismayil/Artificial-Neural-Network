#pragma once

#include <time.h>
#include "Process.h"
#include <iostream>
#include "Perceptron.h"
#include "Delta.h"
#include "Resource.h"

namespace Form_Empty {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			Size = classCount = classLabel = 0;
			class_Size = new int[10];
			for (int i = 0; i < 10; i++)
				class_Size[i] = 0;
			w = new double[3];
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		Samples* sample;
		int Size, * class_Size;
		int isNormalized = false;
		int classCount, classLabel;
		double* w;

	private: System::Windows::Forms::Label^ label8;
	protected:
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::NumericUpDown^ etiket;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ classBox;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ initializingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ randomlyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ trainingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ binaryDiscToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ continousToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->etiket = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->classBox = (gcnew System::Windows::Forms::ComboBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->initializingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->randomlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->binaryDiscToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->continousToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->etiket))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(526, 375);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(42, 15);
			this->label8->TabIndex = 30;
			this->label8->Text = L"Label8";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(526, 343);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(41, 15);
			this->label7->TabIndex = 29;
			this->label7->Text = L"Label7";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(526, 273);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(42, 15);
			this->label5->TabIndex = 28;
			this->label5->Text = L"Label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(526, 310);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(42, 15);
			this->label6->TabIndex = 27;
			this->label6->Text = L"Label6";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(526, 234);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(42, 15);
			this->label4->TabIndex = 26;
			this->label4->Text = L"Label4";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(526, 193);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(42, 15);
			this->label3->TabIndex = 25;
			this->label3->Text = L"Label3";
			// 
			// etiket
			// 
			this->etiket->Location = System::Drawing::Point(618, 97);
			this->etiket->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->etiket->Name = L"etiket";
			this->etiket->Size = System::Drawing::Size(133, 20);
			this->etiket->TabIndex = 24;
			this->etiket->ValueChanged += gcnew System::EventHandler(this, &MyForm::etiket_ValueChanged);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(775, 50);
			this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(141, 81);
			this->button1->TabIndex = 23;
			this->button1->Text = L"Sınıf Sayısını Onayla";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox1->Location = System::Drawing::Point(527, 142);
			this->checkBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(81, 19);
			this->checkBox1->TabIndex = 22;
			this->checkBox1->Text = L"Normalize";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->Click += gcnew System::EventHandler(this, &MyForm::checkBox1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(524, 98);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 15);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Sınıf Etiketi";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(526, 61);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 15);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Sınıf Sayısı";
			// 
			// classBox
			// 
			this->classBox->FormattingEnabled = true;
			this->classBox->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"1", L"2", L"3", L"4", L"5", L"6" });
			this->classBox->Location = System::Drawing::Point(617, 61);
			this->classBox->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->classBox->Name = L"classBox";
			this->classBox->Size = System::Drawing::Size(134, 21);
			this->classBox->TabIndex = 19;
			this->classBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::classBox_SelectedIndexChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->Location = System::Drawing::Point(12, 38);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(480, 404);
			this->pictureBox1->TabIndex = 17;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint_1);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick_1);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->processToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(10, 4, 0, 4);
			this->menuStrip1->Size = System::Drawing::Size(937, 27);
			this->menuStrip1->TabIndex = 18;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->initializingToolStripMenuItem,
					this->trainingToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->processToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(59, 19);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// initializingToolStripMenuItem
			// 
			this->initializingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->randomlyToolStripMenuItem });
			this->initializingToolStripMenuItem->Name = L"initializingToolStripMenuItem";
			this->initializingToolStripMenuItem->Size = System::Drawing::Size(130, 22);
			this->initializingToolStripMenuItem->Text = L"Initializing";
			// 
			// randomlyToolStripMenuItem
			// 
			this->randomlyToolStripMenuItem->Name = L"randomlyToolStripMenuItem";
			this->randomlyToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->randomlyToolStripMenuItem->Text = L"Randomly";
			this->randomlyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::randomlyToolStripMenuItem_Click);
			// 
			// trainingToolStripMenuItem
			// 
			this->trainingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->binaryDiscToolStripMenuItem,
					this->continousToolStripMenuItem
			});
			this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			this->trainingToolStripMenuItem->Size = System::Drawing::Size(130, 22);
			this->trainingToolStripMenuItem->Text = L"Training";
			// 
			// binaryDiscToolStripMenuItem
			// 
			this->binaryDiscToolStripMenuItem->Name = L"binaryDiscToolStripMenuItem";
			this->binaryDiscToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->binaryDiscToolStripMenuItem->Text = L"Binary(Disc)";
			this->binaryDiscToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::binaryDiscToolStripMenuItem_Click_1);
			// 
			// continousToolStripMenuItem
			// 
			this->continousToolStripMenuItem->Name = L"continousToolStripMenuItem";
			this->continousToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->continousToolStripMenuItem->Text = L"Continious";
			this->continousToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::continousToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(130, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(937, 461);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->etiket);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->classBox);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->etiket))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void classBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		classCount = classBox->SelectedIndex + 1;
		w = new double[classCount * 3];
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		etiket->Maximum = classCount;
		etiket->Minimum = 1;
		delete w;
		w = new double[classCount * 3];
	}
	private: System::Void etiket_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		classLabel = (int)etiket->Value - 1;
	}
	private: System::Void pictureBox1_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		//Ana eksen dogrularinin cizilmesi

		Pen^ pen = gcnew Pen(Color::Black, 3.0f);
		int center_width, center_height;
		center_width = (int)(pictureBox1->Width / 2);
		center_height = (int)(pictureBox1->Height / 2);
		e->Graphics->DrawLine(pen, center_width, 0, center_width, pictureBox1->Height);
		e->Graphics->DrawLine(pen, 0, center_height, pictureBox1->Width, center_height);
	}
	private: System::Void pictureBox1_MouseClick_1(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		//Eksen uzerinde orneklerin cizilmesi

		Pen^ pen = gcnew Pen(Color::Black, 3.0f);
		int temp_x, temp_y;
		double x1, x2; //x1 = width, x2 = height
		temp_x = (Convert::ToInt32(e->X));
		temp_y = (Convert::ToInt32(e->Y));
		x1 = (double)(temp_x - (pictureBox1->Width >> 1));
		x2 = (double)((pictureBox1->Height >> 1) - temp_y);
		if (Size == 0) {
			Size = class_Size[classLabel] = 1;
			sample = new Samples[1];
			sample[0].x1 = x1;
			sample[0].x2 = x2;
			sample[0].id = classLabel;
		}
		else {
			Samples* temp;
			temp = sample;
			class_Size[classLabel]++;
			Size++;
			sample = new Samples[Size];
			for (int i = 0; i < Size - 1; i++) {
				sample[i].x1 = temp[i].x1;
				sample[i].x2 = temp[i].x2;
				sample[i].id = temp[i].id;
			}

			sample[Size - 1].x1 = x1;
			sample[Size - 1].x2 = x2;
			sample[Size - 1].id = classLabel;
			delete temp;

		}//else

		switch (classLabel) {
		case 0:pen = gcnew Pen(Color::Black, 3.0f); sample[Size - 1].color = 0; break;
		case 1:pen = gcnew Pen(Color::Blue, 3.0f); sample[Size - 1].color = 1;  break;
		case 2:pen = gcnew Pen(Color::Red, 3.0f); sample[Size - 1].color = 2;  break;
		case 3:pen = gcnew Pen(Color::Orange, 3.0f); sample[Size - 1].color = 3; break;
		case 4:pen = gcnew Pen(Color::Green, 3.0f); sample[Size - 1].color = 4; break;
		case 5:pen = gcnew Pen(Color::Yellow, 3.0f); sample[Size - 1].color = 5; break;
		default:pen = gcnew Pen(Color::Purple, 3.0f); sample[Size - 1].color = 6; break;
		}

		label3->Text = "x1: " + Convert::ToString(sample[Size - 1].x1) + " x2: " + Convert::ToString(sample[Size - 1].x2);
		pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
		pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
		label4->Text = "Samples Total : " + Convert::ToString(Size) + " Class(" + Convert::ToString(classLabel + 1) + ") : " + Convert::ToString(class_Size[classLabel]);
	}
	private: System::Void randomlyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		//Rastgele ayirtac dogrularinin cizdirilmesi (w1*x1 + w2*x2 + w3 = 0)

		Pen^ pen = gcnew Pen(Color::Blue, 3.0f);

		int min_x, max_x, min_y, max_y;

		srand(time(0));

		for (int label = 0; label < classCount; label++) {
			for (int i = 0; i < 3; i++)
				w[3 * label + i] = ((double)rand() / (RAND_MAX));

			label5->Text = " w[0]: " + System::Convert::ToString(w[3 * label]);
			label6->Text = " w[1]: " + System::Convert::ToString(w[3 * label + 1]);
			label7->Text = " w[2]: " + System::Convert::ToString(w[3 * label + 2]);

			min_x = (this->pictureBox1->Width) / -2;
			min_y = YPoint(min_x, &w[3 * label]);
			max_x = (this->pictureBox1->Width) / 2;
			max_y = YPoint(max_x, &w[3 * label]);

			switch (label) {
			case 0:pen = gcnew Pen(Color::Black, 3.0f); break;
			case 1:pen = gcnew Pen(Color::Blue, 3.0f); break;
			case 2:pen = gcnew Pen(Color::Red, 3.0f); break;
			case 3:pen = gcnew Pen(Color::Orange, 3.0f); break;
			case 4:pen = gcnew Pen(Color::Green, 3.0f); break;
			case 5:pen = gcnew Pen(Color::Yellow, 3.0f); break;
			default:pen = gcnew Pen(Color::Purple, 3.0f); break;
			}

			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);
		}
	}
	private: System::Void binaryDiscToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {

		//Ayrik aktivasyon fonksiyonuyla orneklerin siniflandirilmasi

		Pen^ pen = gcnew Pen(Color::Blue, 3.0f);

		int min_x, max_x, min_y, max_y;

		pictureBox1->Refresh();
		for (int i = 0; i < Size; i++) {
			int temp_x = Convert::ToInt32(sample[i].x1 + (pictureBox1->Width >> 1));
			int temp_y = Convert::ToInt32((pictureBox1->Height >> 1) - sample[i].x2);

			switch (sample[i].id) {
			case 0:pen->Color = Color::Black; break;
			case 1:pen->Color = Color::Blue; break;
			case 2:pen->Color = Color::Red; break;
			case 3:pen->Color = Color::Orange; break;
			case 4:pen->Color = Color::Green; break;
			case 5:pen->Color = Color::Yellow; break;
			default:pen->Color = Color::Purple; break;
			}

			pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
			pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
		}

		for (int category = 0; category < classCount; category++) 
		{
			Samples* temp_sample = new Samples[Size];

			for (int i = 0; i < 3; i++) {
				w[i] = ((double)rand() / (RAND_MAX));
			}
				
			for (int i = 0; i < Size; i++) 
			{
				temp_sample[i].x1 = sample[i].x1;
				temp_sample[i].x2 = sample[i].x2;

				if (sample[i].id == category) 
				{
					temp_sample[i].id = 1;
				}
				else
				{
					temp_sample[i].id = 0;
				}
			}

			for (int i = 0; i < Size; i++) 
			{
				temp_sample[i].x1 /= pictureBox1->Width;
				temp_sample[i].x2 /= pictureBox1->Width;
			}

			int cycle = 10000, is_all_done;
			int j;

			for (j = 0; j < cycle; j++) 
			{
				int* training_result = new int[Size];
				is_all_done = 1;
				for (int i = 0; i < Size; i++) 
				{
					training_result[i] = perceptron(temp_sample[i], w, 0.1);
				}
					
				for (int i = 0; i < Size; i++) 
				{
					if (training_result[i] == 0)
						is_all_done = 0;
				}
					
				if (is_all_done)
					break;
			}

			switch (category) {
			case 0:pen->Color = Color::Black; break;
			case 1:pen->Color = Color::Blue; break;
			case 2:pen->Color = Color::Red; break;
			case 3:pen->Color = Color::Orange; break;
			case 4:pen->Color = Color::Green; break;
			case 5:pen->Color = Color::Yellow; break;
			default:pen->Color = Color::Purple; break;
			}

			label5->Text = " w[0]: " + System::Convert::ToString(w[0]);
			label6->Text = " w[1]: " + System::Convert::ToString(w[1]);
			label7->Text = " w[2]: " + System::Convert::ToString(w[2]);
			label8->Text = " Tur sayisi: " + System::Convert::ToString(j);

			min_x = (this->pictureBox1->Width) / -2;
			min_y = YPoint(min_x, w, pictureBox1->Width);
			max_x = (this->pictureBox1->Width) / 2;
			max_y = YPoint(max_x, w, pictureBox1->Width);

			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);
		}
	}
	private: System::Void continousToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		//Surekli aktivasyon fonksiyonuyla orneklerin siniflandirilmasi

		if (!isNormalized) 
		{
			MessageBox::Show("Normalize yapmak lazim!");
			return;
		}

		Pen^ pen = gcnew Pen(Color::Blue, 3.0f);

		int min_x, max_x, min_y, max_y;

		pictureBox1->Refresh();
		for (int i = 0; i < Size; i++) 
		{
			int temp_x = Convert::ToInt32((pictureBox1->Width) * sample[i].x1 + (pictureBox1->Width >> 1));
			int temp_y = Convert::ToInt32((pictureBox1->Height >> 1) - pictureBox1->Width * sample[i].x2);

			switch (sample[i].id) {
			case 0:pen->Color = Color::Black; break;
			case 1:pen->Color = Color::Blue; break;
			case 2:pen->Color = Color::Red; break;
			case 3:pen->Color = Color::Orange; break;
			case 4:pen->Color = Color::Green; break;
			case 5:pen->Color = Color::Yellow; break;
			default:pen->Color = Color::Purple; break;
			}

			pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
			pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);

		}

		for (int category = 0; category < classCount; category++) 
		{
			Samples* temp_sample = new Samples[Size];

			for (int i = 0; i < 3; i++) {
				w[i] = ((double)rand() / (RAND_MAX));
			}			

			for (int i = 0; i < Size; i++) 
			{
				temp_sample[i].x1 = sample[i].x1;
				temp_sample[i].x2 = sample[i].x2;

				if (sample[i].id == category) 
				{
					temp_sample[i].id = 1;
				}
				else 
				{
					temp_sample[i].id = 0;
				}
			}

			int cycle = 10000, is_all_done;
			int j;

			for (j = 0; j < cycle; j++) 
			{
				int* training_result = new int[Size];
				is_all_done = 1;

				for (int i = 0; i < Size; i++) 
				{
					training_result[i] = delta(temp_sample[i], w, 0.1);
				}
					
				for (int i = 0; i < Size; i++) 
				{
					if (training_result[i] == 0)
						is_all_done = 0;
				}
					
				if (is_all_done)
					break;
			}

			switch (category) {
			case 0:pen->Color = Color::Black; break;
			case 1:pen->Color = Color::Blue; break;
			case 2:pen->Color = Color::Red; break;
			case 3:pen->Color = Color::Orange; break;
			case 4:pen->Color = Color::Green; break;
			case 5:pen->Color = Color::Yellow; break;
			default:pen->Color = Color::Purple; break;
			}

			label5->Text = " w[0]: " + System::Convert::ToString(w[0]);
			label6->Text = " w[1]: " + System::Convert::ToString(w[1]);
			label7->Text = " w[2]: " + System::Convert::ToString(w[2]);
			label8->Text = " Tur sayisi: " + System::Convert::ToString(j);

			min_x = (this->pictureBox1->Width) / -2;
			min_y = YPoint(min_x, w, pictureBox1->Width);
			max_x = (this->pictureBox1->Width) / 2;
			max_y = YPoint(max_x, w, pictureBox1->Width);

			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);
		}
	}
	private: System::Void checkBox1_Click(System::Object^ sender, System::EventArgs^ e) {

		if (!isNormalized) {
			for (int i = 0; i < Size; i++) {
				sample[i].x1 /= pictureBox1->Width;
				sample[i].x2 /= pictureBox1->Width;
			}
			isNormalized = 1;
		}
	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
};
}
