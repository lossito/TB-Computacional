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
			estado = 2; //manual
			pasoActual = 0;
			ultimoPaso = 1;
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
		int estado;
		int pasoActual;
		int ultimoPaso;
		bool grafoCreado;
		String^ TextoVertice(char vertice) { return gcnew String((wchar_t)vertice, 1); }
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
			this->btnsiguiente->Text = L"siguiente";
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
		if (radioButton2->Checked) {
			prepararEntradaManual();
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		srand(time(NULL));
		this->cantidadVertices = (int)numericUpDown1->Value;
		grafo->reiniciar();
		for (char i = 'A'; i < 'A' + cantidadVertices; i++) grafo->agregarVertice(i);

		if (estado == 1) {
			for (char origen = 'A'; origen < 'A' + cantidadVertices; origen++) {
				char destino = origen;
				destino++;
				for (;destino < 'A' + cantidadVertices; destino++) {
					if (rand() % 2 == 0) {
						grafo->agregarArista(origen, destino);
					}
				}
			}
		} else if (estado == 2) {
			if (!cargarAristasManuales()) {
				grafoCreado = false;
				btnsiguiente->Enabled = false;
				return;
			}
		}
		actualizarLista();
		actualizarMatriz();
		pictureGrafo->Invalidate();
		grafoCreado = true;
		mostrarPaso(0);

	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioButton1->Checked) {
			estado = 1;
			pruebTexto1->ReadOnly = true;
			prepararEntradaManual();
		}
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioButton2->Checked) {
			estado = 2;
			pruebTexto1->ReadOnly = false;
			prepararEntradaManual();
		}
	}
	private: System::Void pictureGrafo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (cantidadVertices <= 0) return;
		Graphics^ dibujo = e->Graphics;
		dibujo->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

		int n = cantidadVertices;
		float radioNodo = 20.0f;
		float centroX = pictureGrafo->Width / 2.0f;
		float centroY = pictureGrafo->Height / 2.0f;

		float radioGrafo = Math::Min(centroX, centroY) - radioNodo - 25.0f;
		const double PI = 3.14159265358979;
		cli::array<PointF>^ posiciones = gcnew cli::array<PointF>(n);

		for (int i = 0; i < n; i++) {
			double angulo = -PI / 2 + 2 * PI * i / n;
			posiciones[i] = PointF(centroX + (float)(radioGrafo * Math::Cos(angulo)), centroY + (float)(radioGrafo * Math::Sin(angulo)));
		}

		Pen^ lapiz = gcnew Pen(Color::LightGray, 2.0f); char origen = 'A';

		for (int i = 0; i < n; i++, origen++) {
			char destino = origen;
			destino++;

			for (int j = i + 1; j < n; j++, destino++) {
				if (grafo->existeArista(origen, destino)) {
					dibujo->DrawLine(lapiz, posiciones[i], posiciones[j]);
				}
			}
		}

		Brush^ relleno = gcnew SolidBrush(Color::FromArgb(88, 101, 242));

		System::Drawing::Font^ fuente = gcnew System::Drawing::Font(L"Segoe UI", 11.0f,FontStyle::Bold);

		StringFormat^ formato = gcnew StringFormat();
		formato->Alignment = StringAlignment::Center;
		formato->LineAlignment = StringAlignment::Center;

		char etiqueta = 'A';

		for (int i = 0; i < n; i++, etiqueta++) {
			RectangleF nodo(posiciones[i].X - radioNodo,posiciones[i].Y - radioNodo,2 * radioNodo,2 * radioNodo);

			dibujo->FillEllipse(relleno, nodo);
			dibujo->DrawEllipse(Pens::White, nodo);
			dibujo->DrawString(TextoVertice(etiqueta),fuente,Brushes::White,nodo,formato);
		}
	}

	private: System::Void btnAtras_Click(System::Object^ sender, System::EventArgs^ e) {
		if (pasoActual > 0) mostrarPaso(pasoActual - 1);
	}
	private: System::Void btnsiguiente_Click(System::Object^ sender, System::EventArgs^ e) {
		siguiente();
	}

	void mostrarPaso(int paso) {
		panelConfig->Visible = (paso == 0);
		panelGrafo->Visible = (paso == 1);
		pasoActual = paso;

		btnAtras->Enabled = (paso > 0);
		btnsiguiente->Enabled = (paso < ultimoPaso) && (paso > 0 || grafoCreado);
	}

	void siguiente() {
		if (pasoActual < ultimoPaso) mostrarPaso(pasoActual + 1);
	}

	void actualizarMatriz() {
		System::Text::StringBuilder^ texto = gcnew System::Text::StringBuilder();
		texto->Append(L"   ");

		for (char vertice = 'A'; vertice < 'A' + cantidadVertices; vertice++) {
			texto->Append(TextoVertice(vertice));
			texto->Append(L"  ");
		}

		texto->AppendLine();

		for (char origen = 'A'; origen < 'A' + cantidadVertices; origen++) {
			texto->Append(TextoVertice(origen));
			texto->Append(L"  ");

			for (char destino = 'A'; destino < 'A' + cantidadVertices; destino++) {
				if (grafo->existeArista(origen, destino)) { texto->Append(L"1  ");
				} else {
					texto->Append(L"0  ");
				}
			}
			texto->AppendLine();
		}
		txtMatriz->Text = texto->ToString();
	}

	void actualizarLista() {
		System::Text::StringBuilder^ texto = gcnew System::Text::StringBuilder();

		texto->Append(L"Vertices: ");
		char vertice = 'A';

		for (int i = 0; i < cantidadVertices; i++, vertice++) {
			if (i > 0) { texto->Append(L", "); }
			texto->Append(TextoVertice(vertice));
		}

		texto->AppendLine();
		char origen = 'A';

		for (int i = 0; i < cantidadVertices; i++, origen++) {

			texto->Append(TextoVertice(origen));
			texto->Append(L": ");

			bool primeraConexion = true;
			char destino = 'A';

			for (int j = 0; j < cantidadVertices; j++, destino++) {

				if (grafo->existeArista(origen, destino)) {
					if (!primeraConexion) {
						texto->Append(L",");
					}

					texto->Append(TextoVertice(destino));
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
		char vertice = 'A';

		for (int i = 0; i < total; i++, vertice++) {
			if (i > 0) { texto->Append(L", "); }

			texto->Append(TextoVertice(vertice));
		}

		texto->AppendLine();
		vertice = 'A';

		for (int i = 0; i < total; i++, vertice++) {
			texto->Append(TextoVertice(vertice));
			texto->Append(L":");

			if (i < total - 1) {
				texto->AppendLine();
			}
		}

		pruebTexto1->Text = texto->ToString();
	}

	bool cargarAristasManuales() {
		bool conexiones[12][12] = {};
		array<String^>^ lineas = pruebTexto1->Lines;

		if (lineas->Length < cantidadVertices + 1) {
			mostrarErrorManual(L"Debe existir una linea para cada vertice.");
			return false;
		}

		if (!lineas[0]->Trim()->StartsWith(L"Vertices:",StringComparison::OrdinalIgnoreCase)) {
			mostrarErrorManual(L"La primera linea debe comenzar con \"Vertices:\".");
			return false;
		}

		array<wchar_t>^ separador = gcnew array<wchar_t>(1);
		separador[0] = L',';
		char origen = 'A';

		for (int fila = 0; fila < cantidadVertices; fila++, origen++) {
			String^ linea = lineas[fila + 1]->Trim()->ToUpperInvariant();
			String^ prefijo = TextoVertice(origen) + L":";

			if (!linea->StartsWith(prefijo)) {
				mostrarErrorManual(L"Se esperaba la linea " + prefijo + L" en la posicion correspondiente.");
				return false;
			}

			String^ contenido = linea->Substring(prefijo->Length)->Trim();

			if (contenido->Length == 0 || contenido->Equals(L"SIN ARISTAS")) {
				continue;
			}

			array<String^>^ destinos = contenido->Split(separador);

			for each (String ^ elemento in destinos) {
				String^ textoDestino = elemento->Trim();
				if (textoDestino->Length != 1) { mostrarErrorManual(L"Cada destino debe ser una sola letra " L"separada por comas.");
					return false;
				}

				wchar_t letra = textoDestino[0];

				if (letra < L'A' || letra >= L'A' + cantidadVertices) {
					mostrarErrorManual(L"Se ingreso un vertice que no pertenece " L"al grafo.");
					return false;
				}

				int columna = letra - L'A';

				if (fila == columna) { mostrarErrorManual(L"No se permiten conexiones de un " L"vertice consigo mismo.");
					return false;
				}

				if (conexiones[fila][columna]) {
					mostrarErrorManual(L"No repita una conexion en la misma fila.");
					return false;
				}

				conexiones[fila][columna] = true;
			}
		}

		for (int i = cantidadVertices + 1; i < lineas->Length; i++) {
			if (!String::IsNullOrWhiteSpace(lineas[i])) {
				mostrarErrorManual(L"Hay lineas adicionales que no pertenecen " L"al formato.");
				return false;
			}
		}

		char verticeA = 'A';

		for (int i = 0; i < cantidadVertices; i++, verticeA++) {
			char verticeB = verticeA; verticeB++;
			for (int j = i + 1; j < cantidadVertices; j++, verticeB++) {
				if (conexiones[i][j] != conexiones[j][i]) {
					mostrarErrorManual(L"La conexion entre " + TextoVertice(verticeA) + L" y " + TextoVertice(verticeB) + L" debe aparecer en ambas filas.");
					return false;
				}
			}
		}

		verticeA = 'A';
		for (int i = 0; i < cantidadVertices; i++, verticeA++) {
			char verticeB = verticeA; verticeB++;
			for (int j = i + 1; j < cantidadVertices; j++, verticeB++) {
				if (conexiones[i][j]) { grafo->agregarArista(verticeA, verticeB);
				}
			}
		}

		return true;
	}
};
}