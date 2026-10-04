#pragma once
#include "dwmapi.h"
#include "Grafo.h"
#include <ctime>

namespace GrafoConexo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			grafo = new Grafo<char>;
			cantidadVertices = 0;
			pasoActual = 0;
			grafoCreado = false;
			prepararEntradaManual();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
			delete grafo;
		}
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
		int cantidadVertices;
		Grafo<char>* grafo;
		bool grafoCreado;
		int pasoActual;
		String^ textoVertice(char vertice) { return System::Char::ToString(vertice); }
	private: System::Windows::Forms::TextBox^ pruebTexto1;
	private: System::Windows::Forms::Panel^ panelConfig;
	private: System::Windows::Forms::Panel^ panelGrafo;
	private: System::Windows::Forms::TextBox^ txtMatriz;
	private: System::Windows::Forms::Button^ btnsiguiente;
	private: System::Windows::Forms::Button^ btnAtras;
	private: System::Windows::Forms::PictureBox^ pictureGrafo;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->pruebTexto1 = (gcnew System::Windows::Forms::TextBox());
			this->panelConfig = (gcnew System::Windows::Forms::Panel());
			this->panelGrafo = (gcnew System::Windows::Forms::Panel());
			this->txtMatriz = (gcnew System::Windows::Forms::TextBox());
			this->pictureGrafo = (gcnew System::Windows::Forms::PictureBox());
			this->btnsiguiente = (gcnew System::Windows::Forms::Button());
			this->btnAtras = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->panelConfig->SuspendLayout();
			this->panelGrafo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureGrafo))->BeginInit();
			this->SuspendLayout();
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(246, 89);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(131, 25);
			this->numericUpDown1->TabIndex = 0;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm1::numericUpDown1_ValueChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(246, 225);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 46);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Crear grafo";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->radioButton1->Location = System::Drawing::Point(246, 169);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(79, 21);
			this->radioButton1->TabIndex = 2;
			this->radioButton1->Text = L"Aleatorio";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Checked = true;
			this->radioButton2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->radioButton2->Location = System::Drawing::Point(246, 136);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(69, 21);
			this->radioButton2->TabIndex = 3;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Manual";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::radioButton2_CheckedChanged);
			// 
			// pruebTexto1
			// 
			this->pruebTexto1->Location = System::Drawing::Point(165, 316);
			this->pruebTexto1->Multiline = true;
			this->pruebTexto1->Name = L"pruebTexto1";
			this->pruebTexto1->Size = System::Drawing::Size(299, 265);
			this->pruebTexto1->TabIndex = 4;
			// 
			// panelConfig
			// 
			this->panelConfig->Controls->Add(this->button1);
			this->panelConfig->Controls->Add(this->pruebTexto1);
			this->panelConfig->Controls->Add(this->numericUpDown1);
			this->panelConfig->Controls->Add(this->radioButton2);
			this->panelConfig->Controls->Add(this->radioButton1);
			this->panelConfig->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelConfig->Location = System::Drawing::Point(0, 0);
			this->panelConfig->Name = L"panelConfig";
			this->panelConfig->Size = System::Drawing::Size(674, 775);
			this->panelConfig->TabIndex = 5;
			// 
			// panelGrafo
			// 
			this->panelGrafo->Controls->Add(this->txtMatriz);
			this->panelGrafo->Controls->Add(this->pictureGrafo);
			this->panelGrafo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelGrafo->Location = System::Drawing::Point(0, 0);
			this->panelGrafo->Name = L"panelGrafo";
			this->panelGrafo->Size = System::Drawing::Size(674, 775);
			this->panelGrafo->TabIndex = 7;
			this->panelGrafo->Visible = false;
			// 
			// txtMatriz
			// 
			this->txtMatriz->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtMatriz->Location = System::Drawing::Point(120, 468);
			this->txtMatriz->Multiline = true;
			this->txtMatriz->Name = L"txtMatriz";
			this->txtMatriz->ReadOnly = true;
			this->txtMatriz->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txtMatriz->Size = System::Drawing::Size(407, 249);
			this->txtMatriz->TabIndex = 1;
			// 
			// pictureGrafo
			// 
			this->pictureGrafo->Location = System::Drawing::Point(12, 12);
			this->pictureGrafo->Name = L"pictureGrafo";
			this->pictureGrafo->Size = System::Drawing::Size(634, 450);
			this->pictureGrafo->TabIndex = 0;
			this->pictureGrafo->TabStop = false;
			this->pictureGrafo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm1::pictureGrafo_Paint);
			// 
			// btnsiguiente
			// 
			this->btnsiguiente->Enabled = false;
			this->btnsiguiente->Location = System::Drawing::Point(540, 730);
			this->btnsiguiente->Name = L"btnsiguiente";
			this->btnsiguiente->Size = System::Drawing::Size(105, 33);
			this->btnsiguiente->TabIndex = 8;
			this->btnsiguiente->Text = L"Siguiente";
			this->btnsiguiente->UseVisualStyleBackColor = true;
			this->btnsiguiente->Click += gcnew System::EventHandler(this, &MyForm1::btnsiguiente_Click);
			// 
			// btnAtras
			// 
			this->btnAtras->Location = System::Drawing::Point(12, 730);
			this->btnAtras->Name = L"btnAtras";
			this->btnAtras->Size = System::Drawing::Size(100, 33);
			this->btnAtras->TabIndex = 9;
			this->btnAtras->Text = L"Atras";
			this->btnAtras->UseVisualStyleBackColor = true;
			this->btnAtras->Click += gcnew System::EventHandler(this, &MyForm1::btnAtras_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->ClientSize = System::Drawing::Size(674, 775);
			this->Controls->Add(this->btnsiguiente);
			this->Controls->Add(this->btnAtras);
			this->Controls->Add(this->panelGrafo);
			this->Controls->Add(this->panelConfig);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm1";
			this->Text = L"GrafoConexo";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->panelConfig->ResumeLayout(false);
			this->panelConfig->PerformLayout();
			this->panelGrafo->ResumeLayout(false);
			this->panelGrafo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureGrafo))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
		IntPtr handle = this->Handle;
		HWND hwnd = (HWND)handle.ToPointer();
		BOOL option = TRUE;
		DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &option, sizeof(option));
	}
	private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		prepararEntradaManual();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		cantidadVertices = (int)numericUpDown1->Value;
		grafo->reiniciar();

		for (char vertice = 'A'; vertice < 'A' + cantidadVertices; vertice++) {
			grafo->agregarVertice(vertice);
		}

		if (radioButton1->Checked) {
			generarAristasAleatorias();
		}
		else {
			if (!cargarAristasManuales()) {
				grafoCreado = false;
				btnsiguiente->Enabled = false;
				return;
			}
		}

		actualizarLista();
		mostrarMatriz(grafo->obtenerMatrizAdyacencia(),L"Matriz de adyacencia");
		pictureGrafo->Invalidate();

		grafoCreado = true;
		mostrarPaso(0);
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureGrafo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (cantidadVertices == 0) return;

		Graphics^ dibujo = e->Graphics;
		float radioNodo = 20;
		float centroX = pictureGrafo->Width / 2;
		float centroY = pictureGrafo->Height / 2;
		float radioGrafo = Math::Min(centroX, centroY) - 45;

		std::vector<float> posicionesX(cantidadVertices);
		std::vector<float> posicionesY(cantidadVertices);

		for (int i = 0; i < cantidadVertices; i++) {
			double angulo = -Math::PI / 2 + 2 * Math::PI * i / cantidadVertices;
			posicionesX[i] = (float)(centroX + radioGrafo * Math::Cos(angulo));
			posicionesY[i] = (float)(centroY + radioGrafo * Math::Sin(angulo));
		}

		std::vector<std::vector<int>> matriz = grafo->obtenerMatrizAdyacencia();
		Pen^ lapiz = gcnew Pen(Color::LightGray, 2);
		lapiz->CustomEndCap = gcnew System::Drawing::Drawing2D::AdjustableArrowCap(6, 6);

		for (int i = 0; i < cantidadVertices; i++) {
			for (int j = 0; j < cantidadVertices; j++) {
				if (matriz[i][j] == 1) {
					float puntaX = (posicionesX[i] + 2 * posicionesX[j]) / 3;
					float puntaY = (posicionesY[i] + 2 * posicionesY[j]) / 3;

					dibujo->DrawLine(lapiz, posicionesX[i], posicionesY[i], posicionesX[j], posicionesY[j]);
					dibujo->DrawLine(lapiz, posicionesX[i], posicionesY[i], puntaX, puntaY);
				}
			}
		}

		Brush^ relleno = gcnew SolidBrush(Color::FromArgb(88, 101, 242));
		System::Drawing::Font^ fuente = gcnew System::Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);

		StringFormat^ formato = gcnew StringFormat();
		formato->Alignment = StringAlignment::Center;
		formato->LineAlignment = StringAlignment::Center;

		for (int i = 0; i < cantidadVertices; i++) {
			RectangleF nodo(posicionesX[i] - radioNodo, posicionesY[i] - radioNodo, radioNodo * 2, radioNodo * 2);
			dibujo->FillEllipse(relleno, nodo);
			dibujo->DrawEllipse(Pens::White, nodo);
			dibujo->DrawString(textoVertice('A' + i), fuente, Brushes::White, nodo, formato);
		}
	}

	private: System::Void btnAtras_Click(System::Object^ sender, System::EventArgs^ e) {
		if (pasoActual > 0) {
			mostrarPaso(pasoActual - 1);
		}
	}

	private: System::Void btnsiguiente_Click(System::Object^ sender, System::EventArgs^ e) {
		if (pasoActual < 2) {
			mostrarPaso(pasoActual + 1);
		}
	}

	void generarAristasAleatorias() {
		srand(time(NULL));
		for (char origen = 'A'; origen < 'A' + cantidadVertices; origen++) {
			for (char destino = 'A'; destino < 'A' + cantidadVertices; destino++) {
				if (origen != destino && rand() % 2 == 0) {
					grafo->agregarArista(origen, destino);
				}
			}
		}
	}

	void mostrarPaso(int paso) {
		pasoActual = paso;
		panelConfig->Visible = (paso == 0);
		panelGrafo->Visible = (paso > 0);

		if (paso == 1) { mostrarMatriz(grafo->obtenerMatrizAdyacencia(),L"Matriz de adyacencia"); }
		else if (paso == 2) { mostrarMatriz(grafo->calcularMatrizCaminos(),L"Matriz de caminos"); }

		btnAtras->Enabled = (paso > 0);
		btnsiguiente->Enabled = (paso < 2) && (paso > 0 || grafoCreado);
	}

	void mostrarMatriz(std::vector<std::vector<int>> matriz, String^ titulo) {
		System::Text::StringBuilder^ texto = gcnew System::Text::StringBuilder();

		texto->AppendLine(titulo);
		texto->AppendLine();
		texto->Append(L"   ");

		for (int j = 0; j < cantidadVertices; j++) {
			texto->Append(textoVertice(('A' + j)));
			texto->Append(L"  ");
		}

		texto->AppendLine();

		for (int i = 0; i < cantidadVertices; i++) {
			texto->Append(textoVertice(('A' + i)));
			texto->Append(L"  ");

			for (int j = 0; j < cantidadVertices; j++) {
				texto->Append(matriz[i][j]);
				texto->Append(L"  ");
			}
			texto->AppendLine();
		}
		txtMatriz->Text = texto->ToString();
	}

	void actualizarLista() {
		System::Text::StringBuilder^ texto = gcnew System::Text::StringBuilder();
		texto->Append(L"Vertices: ");

		for (char vertice = 'A'; vertice < 'A' + cantidadVertices; vertice++) {
			if (vertice != 'A') {
				texto->Append(L", ");
			}
			texto->Append(textoVertice(vertice));
		}

		texto->AppendLine();

		for (char origen = 'A'; origen < 'A' + cantidadVertices; origen++) {
			texto->Append(textoVertice(origen));
			texto->Append(L": ");
			bool primeraConexion = true;

			for (char destino = 'A'; destino < 'A' + cantidadVertices; destino++) {
				if (grafo->existeArista(origen, destino)) {
					if (!primeraConexion) {
						texto->Append(L",");
					}
					texto->Append(textoVertice(destino));
					primeraConexion = false;
				}
			}
			if (primeraConexion) {
				texto->Append(L"Sin aristas");
			}

			texto->AppendLine();
		}

		pruebTexto1->Text = texto->ToString();
	}

	void mostrarErrorManual(String^ mensaje) {
		MessageBox::Show(mensaje, L"Entrada manual invalida", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

	void prepararEntradaManual() {
		int total = (int)numericUpDown1->Value;
		System::Text::StringBuilder^ texto = gcnew System::Text::StringBuilder();
		texto->Append(L"Vertices: ");

		for (char vertice = 'A'; vertice < 'A' + total; vertice++) {
			if (vertice != 'A') {
				texto->Append(L", ");
			}
			texto->Append(textoVertice(vertice));
		}

		texto->AppendLine();

		for (char vertice = 'A'; vertice < 'A' + total; vertice++) {
			texto->Append(textoVertice(vertice));
			texto->Append(L":");

			if (vertice < 'A' + total - 1) {
				texto->AppendLine();
			}
		}
		pruebTexto1->Text = texto->ToString();
	}

	bool cargarAristasManuales() {
		array<String^>^ lineas = pruebTexto1->Lines;

		if (lineas->Length < cantidadVertices + 1) {
			mostrarErrorManual(L"Debe existir una linea para cada vertice.");
			return false;
		}

		char origen = 'A';

		for (int fila = 0; fila < cantidadVertices; fila++, origen++) {
			String^ linea = lineas[fila + 1]->Trim()->ToUpperInvariant();
			String^ prefijo = textoVertice(origen) + L":";

			if (!linea->StartsWith(prefijo)) {
				mostrarErrorManual(L"Se esperaba la linea " + prefijo);
				return false;
			}

			String^ contenido = linea->Substring(prefijo->Length)->Trim();

			if (contenido->Length == 0 || contenido->Equals(L"SIN ARISTAS")) {
				continue;
			}

			array<String^>^ destinos = contenido->Split(',');

			for (int i = 0; i < destinos->Length; i++) {
				String^ textoDestino = destinos[i]->Trim();
				if (textoDestino->Length != 1) {
					mostrarErrorManual(L"Cada destino debe ser una sola letra.");
					return false;
				}

				int letra = textoDestino[0];

				if (letra < 'A' || letra >= 'A' + cantidadVertices) {
					mostrarErrorManual(L"El vertice destino no pertenece al grafo.");
					return false;
				}

				char destino = (char)letra;

				if (origen == destino) {
					mostrarErrorManual(L"No se permiten conexiones de un vertice consigo mismo.");
					return false;
				}
				grafo->agregarArista(origen, destino);
			}
		}
		return true;
	}
};
}