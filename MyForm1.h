//MyForm1.h:
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

	
	public ref class Cuadro
	{
	public:
		String^ titulo;
		String^ explicacion;
		array<int, 2>^ m;          // matriz a dibujar
		array<int>^ filas;         // orden en que se muestran las filas
		array<int>^ cols;          // orden en que se muestran las columnas
		int filaActiva;            // fila que recibe los 1 (flecha roja)
		int filaCopia;             // fila de la que se copia (recuadro dorado)
		int colActiva;             // columna del 1 seleccionado (circulo)
		array<int>^ nuevos;        // columnas que pasaron de 0 a 1 (en rojo)
		bool conteo;               // mostrar cantidad de 1 por fila
		array<int>^ bloques;       // tamanos de los bloques diagonales
		array<int>^ compDeVertice; // componente de cada vertice (para colorear el grafo)

		Cuadro()
		{
			filaActiva = -1;
			filaCopia = -1;
			colActiva = -1;
			nuevos = nullptr;
			conteo = false;
			bloques = nullptr;
			compDeVertice = nullptr;
		}
	};

	
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
			cuadros = gcnew System::Collections::Generic::List<Cuadro^>();
			cuadroActual = nullptr;
			srand((unsigned int)time(NULL));

			// Zona donde se dibuja la matriz paso a paso (creada por codigo)
			pictureMatriz = gcnew System::Windows::Forms::PictureBox();
			pictureMatriz->Location = System::Drawing::Point(12, 468);
			pictureMatriz->Size = System::Drawing::Size(310, 250);
			pictureMatriz->BackColor = System::Drawing::Color::FromArgb(43, 45, 49);
			pictureMatriz->TabStop = false;
			pictureMatriz->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm1::pictureMatriz_Paint);
			panelGrafo->Controls->Add(pictureMatriz);

			// txtMatriz ahora muestra la explicacion de cada etapa
			txtMatriz->Location = System::Drawing::Point(330, 468);
			txtMatriz->Size = System::Drawing::Size(316, 250);
			txtMatriz->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			txtMatriz->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;

			prepararEntradaManual();
		}

	protected:
		
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
		
		System::ComponentModel::Container^ components;
		int cantidadVertices;
		Grafo<char>* grafo;
		bool grafoCreado;
		int pasoActual; // 0 = pantalla de configuracion, k>0 = cuadros[k-1]
		System::Collections::Generic::List<Cuadro^>^ cuadros;
		Cuadro^ cuadroActual;
		System::Windows::Forms::PictureBox^ pictureMatriz;
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
		construirCuadros();

		grafoCreado = true;
		mostrarPaso(0);
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureGrafo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (cantidadVertices == 0) {
			return;
		}

		Graphics^ dibujo = e->Graphics;
		dibujo->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
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
		lapiz->CustomEndCap = gcnew System::Drawing::Drawing2D::AdjustableArrowCap(4, 5);

		// Aristas dirigidas: flecha de i hacia j
		for (int i = 0; i < cantidadVertices; i++) {
			for (int j = 0; j < cantidadVertices; j++) {
				if (i != j && matriz[i][j] == 1) {
					float dx = posicionesX[j] - posicionesX[i];
					float dy = posicionesY[j] - posicionesY[i];
					float largo = (float)Math::Sqrt(dx * dx + dy * dy);
					float ux = dx / largo;
					float uy = dy / largo;

					// si tambien existe j -> i, se separan las dos flechas
					float desvioX = 0, desvioY = 0;
					if (matriz[j][i] == 1) {
						desvioX = -uy * 6;
						desvioY = ux * 6;
					}

					float x1 = posicionesX[i] + ux * radioNodo + desvioX;
					float y1 = posicionesY[i] + uy * radioNodo + desvioY;
					float x2 = posicionesX[j] - ux * (radioNodo + 2) + desvioX;
					float y2 = posicionesY[j] - uy * (radioNodo + 2) + desvioY;
					dibujo->DrawLine(lapiz, x1, y1, x2, y2);
				}
			}
		}

		Brush^ relleno = gcnew SolidBrush(Color::FromArgb(88, 101, 242));
		System::Drawing::Font^ fuente = gcnew System::Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);

		// colores por componente (solo en la etapa final)
		array<Color>^ paleta = gcnew array<Color>(8);
		paleta[0] = Color::FromArgb(88, 101, 242);
		paleta[1] = Color::FromArgb(237, 66, 69);
		paleta[2] = Color::FromArgb(35, 165, 90);
		paleta[3] = Color::FromArgb(200, 150, 0);
		paleta[4] = Color::FromArgb(200, 60, 160);
		paleta[5] = Color::FromArgb(230, 120, 30);
		paleta[6] = Color::FromArgb(0, 150, 200);
		paleta[7] = Color::FromArgb(140, 100, 220);

		StringFormat^ formato = gcnew StringFormat();
		formato->Alignment = StringAlignment::Center;
		formato->LineAlignment = StringAlignment::Center;

		for (int i = 0; i < cantidadVertices; i++) {
			Brush^ pincel = relleno;
			if (cuadroActual != nullptr && cuadroActual->compDeVertice != nullptr) {
				pincel = gcnew SolidBrush(paleta[cuadroActual->compDeVertice[i] % paleta->Length]);
			}
			RectangleF nodo(posicionesX[i] - radioNodo, posicionesY[i] - radioNodo, radioNodo * 2, radioNodo * 2);
			dibujo->FillEllipse(pincel, nodo);
			dibujo->DrawEllipse(Pens::White, nodo);
			dibujo->DrawString(textoVertice('A' + i), fuente, Brushes::White, nodo, formato);
		}
	}

		   // Dibuja la matriz de la etapa actual (con flechas, circulos, recuadros y 1 nuevos en rojo)
	private: System::Void pictureMatriz_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (cuadroActual == nullptr || cantidadVertices == 0) {
			return;
		}

		Cuadro^ q = cuadroActual;
		Graphics^ g = e->Graphics;
		g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

		int n = cantidadVertices;
		float ancho = (float)pictureMatriz->Width;
		float alto = (float)pictureMatriz->Height;
		float c = Math::Min((ancho - 20) / (n + 2), (alto - 6) / (n + 1));
		float x0 = 18 + c;
		float y0 = c;

		System::Drawing::Font^ fuente = gcnew System::Drawing::Font(L"Consolas", 10, FontStyle::Bold);
		StringFormat^ formato = gcnew StringFormat();
		formato->Alignment = StringAlignment::Center;
		formato->LineAlignment = StringAlignment::Center;

		Pen^ lapizCirculo = gcnew Pen(Color::Tomato, 2);
		Pen^ lapizCopia = gcnew Pen(Color::Gold, 2);
		Pen^ lapizBloque = gcnew Pen(Color::Tomato, 3);
		Brush^ pincelRojo = gcnew SolidBrush(Color::Tomato);
		Brush^ pincelFondoFila = gcnew SolidBrush(Color::FromArgb(45, 255, 255, 255));
		Brush^ pincelConteo = gcnew SolidBrush(Color::DeepSkyBlue);

		// encabezado de columnas
		for (int j = 0; j < n; j++) {
			RectangleF rc(x0 + j * c, 0, c, c);
			g->DrawString(textoVertice('A' + q->cols[j]), fuente, Brushes::LightGray, rc, formato);
			if (q->colActiva == q->cols[j]) {
				g->DrawEllipse(lapizCirculo, x0 + j * c + 1, 1.0f, c - 2, c - 2);
			}
		}

		if (q->conteo) {
			RectangleF rc(x0 + n * c + 2, 0, c * 1.5f, c);
			g->DrawString(L"#1", fuente, pincelConteo, rc, formato);
		}

		// filas
		for (int r = 0; r < n; r++) {
			int fi = q->filas[r];
			float y = y0 + r * c;

			RectangleF rcEtiqueta(18, y, c, c);
			g->DrawString(textoVertice('A' + fi), fuente, Brushes::LightGray, rcEtiqueta, formato);

			if (fi == q->filaActiva) {
				g->FillRectangle(pincelFondoFila, x0, y, n * c, c);
				array<PointF>^ flecha = gcnew array<PointF>(3);
				flecha[0] = PointF(2, y + c / 2 - 5);
				flecha[1] = PointF(2, y + c / 2 + 5);
				flecha[2] = PointF(14, y + c / 2);
				g->FillPolygon(pincelRojo, flecha);
			}

			int suma = 0;
			for (int j = 0; j < n; j++) {
				int col = q->cols[j];
				int valor = q->m[fi, col];
				suma += valor;
				RectangleF rc(x0 + j * c, y, c, c);

				Brush^ pincel = Brushes::White;
				if (fi == q->filaActiva && contiene(q->nuevos, col)) {
					pincel = pincelRojo;
				}
				g->DrawString(valor.ToString(), fuente, pincel, rc, formato);
			}

			if (q->conteo) {
				RectangleF rc(x0 + n * c + 2, y, c * 1.5f, c);
				g->DrawString(suma.ToString(), fuente, pincelConteo, rc, formato);
			}

			// recuadro de la fila de la que se copian los 1
			if (fi == q->filaCopia) {
				g->DrawRectangle(lapizCopia, x0, y, n * c, c);
			}
		}

		// bloques diagonales (componentes conexas)
		if (q->bloques != nullptr) {
			float inicio = 0;
			for (int b = 0; b < q->bloques->Length; b++) {
				float tam = (float)q->bloques[b];
				g->DrawRectangle(lapizBloque, x0 + inicio * c, y0 + inicio * c, tam * c, tam * c);
				inicio += tam;
			}
		}
	}

	private: System::Void btnAtras_Click(System::Object^ sender, System::EventArgs^ e) {
		if (pasoActual > 0) {
			mostrarPaso(pasoActual - 1);
		}
	}

	private: System::Void btnsiguiente_Click(System::Object^ sender, System::EventArgs^ e) {
		if (pasoActual < cuadros->Count) {
			mostrarPaso(pasoActual + 1);
		}
	}

		   void generarAristasAleatorias() {
			   // Grafo dirigido: cada par ordenado (origen, destino) se decide por separado,
			   // asi que A -> B no implica B -> A. Probabilidad de arista: 30%.
			   for (char origen = 'A'; origen < 'A' + cantidadVertices; origen++) {
				   for (char destino = 'A'; destino < 'A' + cantidadVertices; destino++) {
					   if (origen != destino && rand() % 100 < 30) {
						   grafo->agregarArista(origen, destino);
					   }
				   }
			   }
		   }

		   // ---------------------------------------------------------------
		   // Utilidades
		   // ---------------------------------------------------------------
		   String^ nombre(int indice) {
			   return textoVertice((char)('A' + indice));
		   }

		   String^ listaNombres(array<int>^ indices) {
			   System::Text::StringBuilder^ texto = gcnew System::Text::StringBuilder();
			   for (int i = 0; i < indices->Length; i++) {
				   if (i > 0) { texto->Append(L", "); }
				   texto->Append(nombre(indices[i]));
			   }
			   return texto->ToString();
		   }

		   bool contiene(array<int>^ lista, int valor) {
			   if (lista == nullptr) { return false; }
			   for (int i = 0; i < lista->Length; i++) {
				   if (lista[i] == valor) { return true; }
			   }
			   return false;
		   }

		   array<int>^ identidad(int n) {
			   array<int>^ r = gcnew array<int>(n);
			   for (int i = 0; i < n; i++) { r[i] = i; }
			   return r;
		   }

		   array<int, 2>^ aManaged(const std::vector<std::vector<int>>& v) {
			   int n = (int)v.size();
			   array<int, 2>^ r = gcnew array<int, 2>(n, n);
			   for (int i = 0; i < n; i++) {
				   for (int j = 0; j < n; j++) {
					   r[i, j] = v[i][j];
				   }
			   }
			   return r;
		   }

		   array<int>^ aManagedVec(const std::vector<int>& v) {
			   array<int>^ r = gcnew array<int>((int)v.size());
			   for (int i = 0; i < (int)v.size(); i++) { r[i] = v[i]; }
			   return r;
		   }

		   Cuadro^ nuevoCuadro(String^ titulo, String^ explicacion, array<int, 2>^ m, array<int>^ filas, array<int>^ cols) {
			   Cuadro^ c = gcnew Cuadro();
			   c->titulo = titulo;
			   c->explicacion = explicacion;
			   c->m = m;
			   c->filas = filas;
			   c->cols = cols;
			   return c;
		   }

		   // ---------------------------------------------------------------
		   // Construye TODAS las etapas del algoritmo (pasos 1, 2, 3 y 4)
		   // ---------------------------------------------------------------
		   void construirCuadros() {
			   cuadros->Clear();
			   cuadroActual = nullptr;

			   int n = cantidadVertices;
			   array<int>^ id = identidad(n);
			   Cuadro^ c;

			   // ================= PASO 1: matriz de adyacencia =================
			   std::vector<std::vector<int>> ady = grafo->obtenerMatrizAdyacenciaConDiagonal();
			   c = nuevoCuadro(
				   L"Paso 1: Matriz de adyacencia",
				   L"Construimos la matriz de adyacencia del grafo y le agregamos el valor 1 en la diagonal principal.",
				   aManaged(ady), id, id);
			   cuadros->Add(c);

			   // ================= PASO 2: matriz de caminos (paso a paso) =================
			   std::vector<PasoCamino> pasos = grafo->calcularPasosMatrizCaminos();
			   String^ titulo2 = L"Paso 2: Matriz de caminos";

			   for (int k = 0; k < (int)pasos.size(); k++) {
				   PasoCamino& p = pasos[k];
				   String^ explicacion;

				   if (p.tipo == 0) {
					   explicacion = L"Partimos de la matriz del paso 1. Para cada fila tomamos cada 1 que no este en la diagonal "
						   L"y copiamos a esa fila todos los 1 de la fila de dicha columna.";
				   }
				   else if (p.tipo == 1) {
					   explicacion = L"Fila " + nombre(p.fila) + L": tomamos el 1 de la columna " + nombre(p.columna) +
						   L" (aun no visitado).\r\nAhora copiaremos a la fila " + nombre(p.fila) +
						   L" todos los 1 de la fila " + nombre(p.columna) + L" (fila con recuadro dorado).";
				   }
				   else if (p.tipo == 2) {
					   explicacion = L"Se copiaron los 1 de la fila " + nombre(p.columna) + L" a la fila " + nombre(p.fila) + L".\r\n";
					   if (p.nuevos.size() == 0) {
						   explicacion = explicacion + L"No aparecio ningun 1 nuevo.";
					   }
					   else {
						   explicacion = explicacion + L"Nuevos 1 (en rojo) en las columnas: " + listaNombres(aManagedVec(p.nuevos)) + L".";
					   }
					   explicacion = explicacion + L"\r\nSe vuelve a revisar la fila " + nombre(p.fila) +
						   L" desde el inicio por si hay algun 1 nuevo sin visitar.";
				   }
				   else {
					   explicacion = L"Fila " + nombre(p.fila) + L" terminada: todos sus 1 ya fueron visitados.";
					   if (p.fila == n - 1) {
						   explicacion = explicacion + L"\r\n\r\nLa matriz de caminos esta completa.";
					   }
				   }

				   c = nuevoCuadro(titulo2, explicacion, aManaged(p.matriz), id, id);
				   if (p.tipo == 1 || p.tipo == 2) {
					   c->filaActiva = p.fila;
					   c->filaCopia = p.columna;
					   c->colActiva = p.columna;
				   }
				   else if (p.tipo == 3) {
					   c->filaActiva = p.fila;
				   }
				   if (p.tipo == 2) {
					   c->nuevos = aManagedVec(p.nuevos);
				   }
				   cuadros->Add(c);
			   }

			   std::vector<std::vector<int>> mcam = pasos[pasos.size() - 1].matriz;
			   array<int, 2>^ mcamArr = aManaged(mcam);

			   // ================= PASO 3: ordenar filas =================
			   std::vector<int> ordenVec = grafo->calcularOrdenFilas(mcam);
			   array<int>^ orden = aManagedVec(ordenVec);

			   c = nuevoCuadro(
				   L"Paso 3: Ordenar las filas",
				   L"Contamos la cantidad de 1 que hay en cada fila (columna #1 a la derecha).",
				   mcamArr, id, id);
			   c->conteo = true;
			   cuadros->Add(c);

			   c = nuevoCuadro(
				   L"Paso 3: Ordenar las filas",
				   L"Ordenamos las filas de mayor a menor cantidad de 1. Si dos filas tienen la misma cantidad, "
				   L"va primero la que tiene el 1 mas cercano a la primera columna.\r\n\r\nNuevo orden de filas: " + listaNombres(orden),
				   mcamArr, orden, id);
			   c->conteo = true;
			   cuadros->Add(c);

			   // ================= PASO 4: ordenar columnas y hallar bloques =================
			   std::vector<std::vector<int>> compVec = grafo->calcularComponentes(ordenVec, mcam);
			   int total = (int)compVec.size();

			   // orden final: miembros de cada componente juntos (normalmente igual al orden del paso 3)
			   std::vector<int> ordenFinalVec;
			   for (int i = 0; i < total; i++) {
				   for (int k = 0; k < (int)compVec[i].size(); k++) {
					   ordenFinalVec.push_back(compVec[i][k]);
				   }
			   }
			   orden = aManagedVec(ordenFinalVec);

			   c = nuevoCuadro(
				   L"Paso 4: Ordenar las columnas",
				   L"Ordenamos las columnas siguiendo el mismo orden de las filas: " + listaNombres(orden) + L".",
				   mcamArr, orden, orden);
			   cuadros->Add(c);

			   array<int>^ bloques = gcnew array<int>(total);
			   array<int>^ compDeVertice = gcnew array<int>(n);
			   for (int i = 0; i < total; i++) {
				   bloques[i] = (int)compVec[i].size();
				   for (int k = 0; k < (int)compVec[i].size(); k++) {
					   compDeVertice[compVec[i][k]] = i;
				   }
			   }

			   c = nuevoCuadro(
				   L"Paso 4: Bloques diagonales",
				   L"Los bloques cuadrados diagonales formados por 1 (recuadros rojos) son las componentes conexas.",
				   mcamArr, orden, orden);
			   c->bloques = bloques;
			   cuadros->Add(c);

			   // resultado final
			   System::Text::StringBuilder^ resultado = gcnew System::Text::StringBuilder();
			   resultado->Append(L"Numero de componentes conexas: ");
			   resultado->Append(total);
			   resultado->AppendLine();
			   if (total == 1) {
				   resultado->AppendLine(L"El grafo es conexo.");
			   }
			   else {
				   resultado->AppendLine(L"El grafo no es conexo.");
			   }
			   resultado->AppendLine();
			   for (int i = 0; i < total; i++) {
				   resultado->Append(L"V");
				   resultado->Append(i + 1);
				   resultado->Append(L" = { ");
				   resultado->Append(listaNombres(aManagedVec(compVec[i])));
				   resultado->AppendLine(L" }");
			   }
			   resultado->AppendLine();
			   resultado->Append(L"En el grafo, cada componente tiene su propio color.");

			   c = nuevoCuadro(L"Resultado final", resultado->ToString(), mcamArr, orden, orden);
			   c->bloques = bloques;
			   c->compDeVertice = compDeVertice;
			   cuadros->Add(c);
		   }

		   // pasoActual = 0 -> configuracion; pasoActual = k -> etapa k (cuadros[k-1])
		   void mostrarPaso(int paso) {
			   pasoActual = paso;
			   panelConfig->Visible = (paso == 0);
			   panelGrafo->Visible = (paso > 0);

			   if (paso > 0 && paso <= cuadros->Count) {
				   cuadroActual = cuadros[paso - 1];
				   txtMatriz->Text = cuadroActual->titulo + L"\r\n\r\n" + cuadroActual->explicacion +
					   L"\r\n\r\n(Etapa " + paso.ToString() + L" de " + cuadros->Count.ToString() + L")";
				   txtMatriz->SelectionStart = 0;
				   txtMatriz->SelectionLength = 0;
				   pictureMatriz->Invalidate();
				   pictureGrafo->Invalidate();
			   }
			   else {
				   cuadroActual = nullptr;
			   }

			   btnAtras->Enabled = (paso > 0);
			   btnsiguiente->Enabled = (paso < cuadros->Count) && (paso > 0 || grafoCreado);
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