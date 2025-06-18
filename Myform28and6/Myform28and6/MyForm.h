#pragma once

namespace Myform28and6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button1;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"цена:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(27, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"кол-во:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(104, 38);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox1_KeyDown);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(104, 82);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox2_KeyPress);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(27, 125);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 95);
			this->listBox1->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(176, 220);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"стоимость";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter) {
			this->textBox2->Focus();
		}
	}

private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8 && e->KeyChar != ',') {
		e->Handled = true;
	}
}

private: System::Void textBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
		e->Handled = true;
	}
}

private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->textBox1->Text != "" && this->textBox2->Text != "") {
		this->button1->Enabled = true;
	}
	else {
		this->button1->Enabled = false;
	}
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		double price = Convert::ToDouble(this->textBox1->Text);
		int quantity = Convert::ToInt32(this->textBox2->Text);

		if (price <= 0 || quantity <= 0)
			throw gcnew Exception("«начени€ должны быть положительными");

		double total = price * quantity;
		double discount = 0;

		if (total > 1200) discount = 0.10;
		else if (total > 700) discount = 0.07;

		double discountValue = total * discount;
		double finalPrice = total - discountValue;

		if (discount > 0) {
			MessageBox::Show(L"—кидка " + (discount * 100).ToString("F0") +
				L"%: " + discountValue.ToString("F2") + L" руб.", L"»нформаци€ о скидке");
		}

		String^ resultLine = "÷ена: " + price.ToString("F2") +
			" x " + quantity.ToString() +
			" = " + total.ToString("F2") +
			" ? »тог: " + finalPrice.ToString("F2") + " руб.";

		this->listBox1->Items->Add(resultLine);
		this->listBox1->TopIndex = this->listBox1->Items->Count - 1;
	}
	catch (...) {
		MessageBox::Show(L"ќшибка! ¬ведите корректные значени€.", L"ќшибка");
	}
}

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	this->button1->Enabled = false;
	this->textBox1->Focus();
}
};
}
