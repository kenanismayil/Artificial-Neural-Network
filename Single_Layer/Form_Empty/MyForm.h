#pragma once

#include "Resource.h"
#include <time.h>
#include "Process.h"
#include <iostream>
#include "Perceptron.h"
#include "Delta.h"

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
			//
			//TODO: Add the constructor code here
			//
			//Baslangicta Size,Size1,Size2   0 degerine setlenir.
			Size = Size1 = Size2 = 0;
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
	private: System::Windows::Forms::CheckBox^ checkBox3;
	protected:
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckBox^ check_Class2;
	private: System::Windows::Forms::CheckBox^ check_Class1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ initialToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ randomToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ trainingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ binaryToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ continuousToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;


	private:
		Samples* sample;
		int Size, Size1, Size2;
		bool is_normalized = false;
		double* w;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->check_Class2 = (gcnew System::Windows::Forms::CheckBox());
			this->check_Class1 = (gcnew System::Windows::Forms::CheckBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->initialToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->randomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->binaryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->continuousToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(723, 61);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(72, 17);
			this->checkBox3->TabIndex = 21;
			this->checkBox3->Text = L"Normalize";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox3_CheckedChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(602, 307);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 20;
			this->label6->Text = L"label6";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(602, 274);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 19;
			this->label5->Text = L"label5";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(602, 243);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 18;
			this->label4->Text = L"label4";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(602, 207);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 17;
			this->label3->Text = L"label3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(602, 173);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 16;
			this->label2->Text = L"label2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(602, 133);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 15;
			this->label1->Text = L"label1";
			// 
			// check_Class2
			// 
			this->check_Class2->AutoSize = true;
			this->check_Class2->Location = System::Drawing::Point(605, 86);
			this->check_Class2->Name = L"check_Class2";
			this->check_Class2->Size = System::Drawing::Size(56, 17);
			this->check_Class2->TabIndex = 14;
			this->check_Class2->Text = L"class2";
			this->check_Class2->UseVisualStyleBackColor = true;
			// 
			// check_Class1
			// 
			this->check_Class1->AutoSize = true;
			this->check_Class1->Checked = true;
			this->check_Class1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->check_Class1->Location = System::Drawing::Point(605, 40);
			this->check_Class1->Name = L"check_Class1";
			this->check_Class1->Size = System::Drawing::Size(56, 17);
			this->check_Class1->TabIndex = 13;
			this->check_Class1->Text = L"class1";
			this->check_Class1->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->Location = System::Drawing::Point(12, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(513, 406);
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->processToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(909, 24);
			this->menuStrip1->TabIndex = 11;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->initialToolStripMenuItem,
					this->trainingToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// initialToolStripMenuItem
			// 
			this->initialToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->randomToolStripMenuItem });
			this->initialToolStripMenuItem->Name = L"initialToolStripMenuItem";
			this->initialToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->initialToolStripMenuItem->Text = L"Initialize";
			// 
			// randomToolStripMenuItem
			// 
			this->randomToolStripMenuItem->Name = L"randomToolStripMenuItem";
			this->randomToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->randomToolStripMenuItem->Text = L"Randomly";
			this->randomToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::randomToolStripMenuItem_Click);
			// 
			// trainingToolStripMenuItem
			// 
			this->trainingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->binaryToolStripMenuItem,
					this->continuousToolStripMenuItem
			});
			this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			this->trainingToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->trainingToolStripMenuItem->Text = L"Training";
			// 
			// binaryToolStripMenuItem
			// 
			this->binaryToolStripMenuItem->Name = L"binaryToolStripMenuItem";
			this->binaryToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->binaryToolStripMenuItem->Text = L"Binary";
			this->binaryToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::binaryToolStripMenuItem_Click);
			// 
			// continuousToolStripMenuItem
			// 
			this->continuousToolStripMenuItem->Name = L"continuousToolStripMenuItem";
			this->continuousToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->continuousToolStripMenuItem->Text = L"Continuous";
			this->continuousToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::continuousToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(909, 433);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->check_Class2);
			this->Controls->Add(this->check_Class1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
		{
			//Ana eksen dogrularinin cizilmesi

			Pen^ pen = gcnew Pen(Color::Black, 3.0f);
			int center_width, center_height;
			center_width = (int)(pictureBox1->Width / 2);
			center_height = (int)(pictureBox1->Height / 2);
			e->Graphics->DrawLine(pen, center_width, 0, center_width, pictureBox1->Height);
			e->Graphics->DrawLine(pen, 0, center_height, pictureBox1->Width, center_height);
		}
		private: System::Void pictureBox1_Click(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (check_Class1->Checked || check_Class2->Checked) {
				if (check_Class1->Checked && check_Class2->Checked) {
					MessageBox::Show("Her iki sinif türü ayni anda seçilemez.");
					check_Class1->Checked = false;
					check_Class2->Checked = false;
				}
				else {
					if (check_Class1->Checked) {
						Pen^ pen = gcnew Pen(Color::Black, 3.0f);
						int temp_x, temp_y;
						double x1, x2; //x1 = width, x2 = height
						temp_x = (Convert::ToInt32(e->X));
						temp_y = (Convert::ToInt32(e->Y));

						// Noktalarin ana eksenin merkezine gore tasinmasi

						x1 = (double)(temp_x - (pictureBox1->Width >> 1));
						x2 = (double)((pictureBox1->Height >> 1) - temp_y);

						if (Size == 0) {
							Size = Size1 = 1;
							sample = new Samples[1];
							sample[0].x1 = x1;
							sample[0].x2 = x2;
							sample[0].id = CLASS1;
						}
						else {
							Samples* temp;
							temp = sample;
							Size1++;
							Size++;
							sample = new Samples[Size];
							for (int i = 0; i < Size - 1; i++) {
								sample[i].x1 = temp[i].x1;
								sample[i].x2 = temp[i].x2;
								sample[i].id = temp[i].id;
							}

							sample[Size - 1].x1 = x1;
							sample[Size - 1].x2 = x2;
							sample[Size - 1].id = CLASS1;
							delete temp;

						}

						label1->Text = "x1 = " + Convert::ToString(sample[Size - 1].x1) + "  x2 = " + Convert::ToString(sample[Size - 1].x2);
						pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
						pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
						label2->Text = "Samples Total = " + Convert::ToString(Size) + "  Class 1 = " + Convert::ToString(Size1);

					}
					//Class2 icin
					else {
						if (check_Class2->Checked) {
							Pen^ pen = gcnew Pen(Color::Red, 3.0f);
							int temp_x, temp_y;
							double x1, x2; //x1 = width, x2 = height
							temp_x = (Convert::ToInt32(e->X));
							temp_y = (Convert::ToInt32(e->Y));
							x2 = (double)((pictureBox1->Height >> 1) - temp_y);
							x1 = (double)(temp_x - (pictureBox1->Width >> 1));
							if (Size == 0) {
								Size = Size2 = 1;
								sample = new Samples[1];
								sample[0].x1 = x1;
								sample[0].x2 = x2;
								sample[0].id = CLASS2;
							}
							else {
								Samples* temp;
								temp = sample;
								Size2++;
								Size++;
								sample = new Samples[Size];
								for (int i = 0; i < Size - 1; i++) {
									sample[i].x1 = temp[i].x1;
									sample[i].x2 = temp[i].x2;
									sample[i].id = temp[i].id;
								}

								sample[Size - 1].x1 = x1;
								sample[Size - 1].x2 = x2;
								sample[Size - 1].id = CLASS2;
								delete temp;

							}

							label1->Text = "x1 = " + Convert::ToString(sample[Size - 1].x1) + "  x2 = " + Convert::ToString(sample[Size - 1].x2);
							pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
							pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
							label2->Text = "Samples Total = " + Convert::ToString(Size) + "  Class 2 = " + Convert::ToString(Size2);
						}
					}
				}
			}
			else {
				MessageBox::Show("Öncelikle örneklerin etiketini belirlemek için ilgili sinifi seçin.");
			}
		}
		private: System::Void randomToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			//Rastgele ayirtac dogrusunun cizdirilmesi (w1*x1 + w2*x2 + w3 = 0)

			Pen^ pen = gcnew Pen(Color::Blue, 3.0f);

			int min_x, max_x, min_y, max_y;

			w = new double[3];
			srand(time(0));
			for (int i = 0; i < 3; i++)
				w[i] = ((double)rand() / (RAND_MAX));

			label3->Text = "w[0]: " + System::Convert::ToString(w[0]);
			label4->Text = "w[1]: " + System::Convert::ToString(w[1]);
			label5->Text = "w[2]: " + System::Convert::ToString(w[2]);

			min_x = (this->pictureBox1->Width) / -2;
			min_y = findY(min_x, w);
			max_x = (this->pictureBox1->Width) / 2;
			max_y = findY(max_x, w);
			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);
		}
		private: System::Void binaryToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			Pen^ pen = gcnew Pen(Color::Blue, 3.0f);

			pictureBox1->Refresh();

			for (int i = 0; i < Size; i++)
			{
				int temp_x = Convert::ToInt32(sample[i].x1 + (pictureBox1->Width / 2));
				int temp_y = Convert::ToInt32((pictureBox1->Height / 2) - sample[i].x2);

				switch (sample[i].id)
				{
				case 0:pen->Color = Color::Black; break;
				case 1:pen->Color = Color::Red; break;
				default:pen->Color = Color::Purple; break;
				}

				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
			}

			int limit = 5000;
			bool is_all_done;
			int j;

			for (j = 0; j < limit; j++)
			{
				int* training_result = new int[Size];
				is_all_done = true;

				for (int i = 0; i < Size; i++)
				{
					training_result[i] = perceptron(sample[i], w, 0.1);
				}
				for (int i = 0; i < Size; i++)
				{
					if (training_result[i] == 0)
					{
						is_all_done = false;
						break;
					}
				}
				if (is_all_done)
				{
					break;
				}
			}

			label3->Text = "w[0]: " + System::Convert::ToString(w[0]);
			label4->Text = "w[1]: " + System::Convert::ToString(w[1]);
			label5->Text = "w[2]: " + System::Convert::ToString(w[2]);
			label6->Text = "Tur sayisi: " + System::Convert::ToString(j);

			int min_x, max_x, min_y, max_y;

			min_x = (this->pictureBox1->Width) / -2;
			min_y = findY(min_x, w);
			max_x = (this->pictureBox1->Width) / 2;
			max_y = findY(max_x, w);

			pen->Color = Color::Blue;
			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);
		}
		private: System::Void continuousToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (!is_normalized)
			{
				MessageBox::Show("Normalize yapilmali!");
				return;
			}

			Pen^ pen = gcnew Pen(Color::Blue, 3.0f);

			pictureBox1->Refresh();

			for (int i = 0; i < Size; i++)
			{
				int temp_x = Convert::ToInt32((pictureBox1->Width) * sample[i].x1 + (pictureBox1->Width / 2));
				int temp_y = Convert::ToInt32((pictureBox1->Height / 2) - pictureBox1->Width * sample[i].x2);

				switch (sample[i].id)
				{
				case 0:pen->Color = Color::Black; break;
				case 1:pen->Color = Color::Red; break;
				default:pen->Color = Color::Purple; break;
				}

				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
			}

			pen->Color = Color::Blue;

			int min_x, max_x, min_y, max_y;

			int limit = 5000;
			bool is_all_done = true;
			int j;

			for (j = 0; j < limit; j++)
			{
				int* training_result = new int[Size];
				is_all_done = true;

				for (int i = 0; i < Size; i++)
				{
					training_result[i] = delta(sample[i], w, 0.1);
				}
				for (int i = 0; i < Size; i++)
				{
					if (training_result[i] == 0)
					{
						is_all_done = false;
						break;
					}
				}
				if (is_all_done)
				{
					break;
				}
			}

			label3->Text = "w[0]: " + System::Convert::ToString(w[0]);
			label4->Text = "w[1]: " + System::Convert::ToString(w[1]);
			label5->Text = "w[2]: " + System::Convert::ToString(w[2]);
			label6->Text = "Tur sayisi: " + System::Convert::ToString(j);

			min_x = (this->pictureBox1->Width) / -2;
			min_y = findY(min_x, w, pictureBox1->Width);
			max_x = (this->pictureBox1->Width) / 2;
			max_y = findY(max_x, w, pictureBox1->Width);

			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);
		}
		private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
		{
			if (!is_normalized)
			{
				for (int i = 0; i < Size; i++)
				{
					sample[i].x1 /= pictureBox1->Width;
					sample[i].x2 /= pictureBox1->Width;
				}
				is_normalized = 1;
			}
		}
		private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			Application::Exit();
		}
};
}
