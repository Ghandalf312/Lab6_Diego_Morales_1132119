#pragma once

namespace Lab6DiegoMorales1132119 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Diagnostics;
	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tbCantidad;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ tbBuscar;
	private: System::Windows::Forms::Button^ btnSecuencial;
	private: System::Windows::Forms::Button^ btnBinaria;
	private: System::Windows::Forms::Label^ label2;

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbCantidad = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tbBuscar = (gcnew System::Windows::Forms::TextBox());
			this->btnSecuencial = (gcnew System::Windows::Forms::Button());
			this->btnBinaria = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(138, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ingrese el tamaño del Array:";
			// 
			// tbCantidad
			// 
			this->tbCantidad->Location = System::Drawing::Point(169, 36);
			this->tbCantidad->Name = L"tbCantidad";
			this->tbCantidad->Size = System::Drawing::Size(100, 20);
			this->tbCantidad->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(169, 71);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 40);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Generar Arreglo";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(50, 189);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 40);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Busqueda Hash";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::Button2_Click);
			// 
			// tbBuscar
			// 
			this->tbBuscar->Location = System::Drawing::Point(202, 137);
			this->tbBuscar->Name = L"tbBuscar";
			this->tbBuscar->Size = System::Drawing::Size(100, 20);
			this->tbBuscar->TabIndex = 4;
			// 
			// btnSecuencial
			// 
			this->btnSecuencial->Location = System::Drawing::Point(169, 189);
			this->btnSecuencial->Name = L"btnSecuencial";
			this->btnSecuencial->Size = System::Drawing::Size(75, 40);
			this->btnSecuencial->TabIndex = 5;
			this->btnSecuencial->Text = L"Busqueda Secuencial";
			this->btnSecuencial->UseVisualStyleBackColor = true;
			this->btnSecuencial->Click += gcnew System::EventHandler(this, &MyForm::Button3_Click);
			// 
			// btnBinaria
			// 
			this->btnBinaria->Location = System::Drawing::Point(290, 189);
			this->btnBinaria->Name = L"btnBinaria";
			this->btnBinaria->Size = System::Drawing::Size(75, 40);
			this->btnBinaria->TabIndex = 6;
			this->btnBinaria->Text = L"Busqueda Binaria";
			this->btnBinaria->UseVisualStyleBackColor = true;
			this->btnBinaria->Click += gcnew System::EventHandler(this, &MyForm::BtnBinaria_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(14, 140);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(182, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Ingrese el numero que desea buscar:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(396, 262);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnBinaria);
			this->Controls->Add(this->btnSecuencial);
			this->Controls->Add(this->tbBuscar);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tbCantidad);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: ArrayList^ ArregloNum; //Arreglo de numeros
			 Hashtable^ TablaHash;
	private: int size;
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int cantidad = int::Parse(tbCantidad->Text);
		generarNumerosAleatorios(cantidad);
		mostrarNumerosAleatorios();
		LlenarTablaHash(cantidad);
		size = cantidad;
	}
			 //Llenar el array de numeros aleatorios
	private: System::Void generarNumerosAleatorios(int size) {
		ArregloNum = gcnew ArrayList();
		Random^ random = gcnew Random();
		for (int i = 0; i < size; i++)
		{
			ArregloNum->Add(random->Next(0, 100));
		}
	}
	private: System::Void mostrarNumerosAleatorios() {
		String^ valores = "";
		for each (int num in ArregloNum)
		{
			valores += num + " ";
		}
		System::Windows::Forms::MessageBox::Show(valores);
	}
	private: System::Void LlenarTablaHash(int size) {
		TablaHash = gcnew Hashtable(size * 2);
		int llave = 0;
		for each (int num in ArregloNum)
		{
			llave = num % size * 2;
			while (TablaHash[llave] != nullptr)
			{
				llave++;
			}
			TablaHash->Add(llave, num);
		}
	}
	private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int ValorBuscar = int::Parse(tbBuscar->Text);
		Stopwatch^ Timer = gcnew Stopwatch();
		Timer->Start();
		int x = PosicionEnHash(ValorBuscar, size);
		Timer->Stop();
		System::Windows::Forms::MessageBox::Show("Tiempo de ejecución: " + System::Convert::ToString(Timer->Elapsed));
		System::Windows::Forms::MessageBox::Show("La posicion en la que se encuentra es: " + x.ToString());
	}
	private: System::Int16 PosicionEnHash(int valorBuscar, int size) {
		int posicion = valorBuscar % size;
		if (System::Convert::ToInt16(TablaHash[posicion]) == valorBuscar)
			return posicion;
		while (System::Convert::ToInt16(TablaHash[posicion]) != valorBuscar)
		{
			posicion++;
		}
		return posicion;
	}
	private: System::Void Button3_Click(System::Object^ sender, System::EventArgs^ e) {
		int ValorBuscar = int::Parse(tbBuscar->Text);
		Stopwatch^ Timer = gcnew Stopwatch();
		Timer->Start();
		int x = BusquedaLineal(ArregloNum, ValorBuscar, size);
		System::Windows::Forms::MessageBox::Show("La posicion en la que se encuentra es: " + x.ToString());
		Timer->Stop();
		System::Windows::Forms::MessageBox::Show("Tiempo de ejecución: " + System::Convert::ToString(Timer->Elapsed));

	}
	private: System::Int16 BusquedaLineal(ArrayList^ A, int ValorBuscar, int size) {
		for (int i = 0; i < size; i++)
		{
			if (ValorBuscar == System::Convert::ToInt16(A[i]))
			{
				return i + 1;
			}
		}
	}
	private: System::Void BtnBinaria_Click(System::Object^ sender, System::EventArgs^ e) {
		int ValorBuscar = int::Parse(tbBuscar->Text);
		Stopwatch^ Timer = gcnew Stopwatch();
		Timer->Start();
		ArregloNum->Sort();
		int x = BusquedaBinaria(ArregloNum, ValorBuscar, size);
		System::Windows::Forms::MessageBox::Show("La posicion en la que se encuentra es: " + x.ToString());
		Timer->Stop();
		System::Windows::Forms::MessageBox::Show("Tiempo de ejecución: " + System::Convert::ToString(Timer->Elapsed));
	}
	private: System::Int16 BusquedaBinaria(ArrayList^ A, int ValorBuscar, int size) {
		int first = 0;
		int middle;
		int last = size - 1;
		while (first <= last)
		{
			middle = (first + last) / 2;

			if (ValorBuscar == System::Convert::ToInt16(A[middle]))
			{
				return middle + 1;
			}
			else {
				if (System::Convert::ToInt16(A[middle]) > ValorBuscar)
				{
					last = middle - 1;
				}
				else {
					first = middle + 1;
				}
			}
		}
		return -1;
	}
	};
	};
