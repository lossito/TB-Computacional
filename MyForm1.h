#pragma once
#include "dwmapi.h"
#include "Grafo.h"
#include <ctime>
#include <algorithm>//


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
	private: System::Windows::Forms::TextBox^ pruebTexto1;
	private: System::Windows::Forms::Panel^ panelConfig;
	private: System::Windows::Forms::Panel^ panelGrafo;
	private: System::Windows::Forms::TextBox^ txtMatriz;
	private: System::Windows::Forms::Button^ btnSiguiente;
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
			this->btnSiguiente = (gcnew System::Windows::Forms::Button());
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
			this->txtMatriz->Location = System::Drawing::Point(158, 483);
			this->txtMatriz->Multiline = true;
			this->txtMatriz->Name = L"txtMatriz";
			this->txtMatriz->ReadOnly = true;
			this->txtMatriz->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txtMatriz->Size = System::Drawing::Size(369, 234);
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
			// btnSiguiente
			// 
			this->btnSiguiente->Enabled = false;
			this->btnSiguiente->Location = System::Drawing::Point(540, 730);
			this->btnSiguiente->Name = L"btnSiguiente";
			this->btnSiguiente->Size = System::Drawing::Size(105, 33);
			this->btnSiguiente->TabIndex = 8;
			this->btnSiguiente->Text = L"Siguiente";
			this->btnSiguiente->UseVisualStyleBackColor = true;
			this->btnSiguiente->Click += gcnew System::EventHandler(this, &MyForm1::btnSiguiente_Click);
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
			this->Controls->Add(this->btnSiguiente);
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
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		srand(time(NULL));
		this->cantidadVertices = (int)numericUpDown1->Value;
		grafo->reiniciarMatriz();
		for (char i = 'A'; i < 'A' + cantidadVertices; i++) grafo->agregarVertice(i);

		if(estado == 1) {
			for (char i = 'A'; i < 'A' + cantidadVertices; i++) {
				for (char j = 'A'; j < 'A' + cantidadVertices; j++) {
					if (rand() % 2 == 0) grafo->agregarArista(i, j);
				}
			}
		}
		/*else if(estado == 2) {
			for (char i = 'A'; i < cantidadVertices; i++) {
				for (char j = i + 1; j <= cantidadVertices; j++) {
					if (MessageBox::Show("¿Desea agregar una arista entre " + gcnew String(i.ToString()) + " y " + gcnew String(j.ToString()) + "?", "Agregar arista", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
						grafo->agregarArista(i, j);
					}
				}
			}
		}*/

		pruebTexto1->Clear();

		for (auto& par : grafo->getMatrizAdyacencia()) { //el cuadro de texto es un objeto de .NET y trabaja con el tipo de texto de .NET, por lo que se necesita convertir el char a String^ usando gcnew String(char, 1)
			pruebTexto1->AppendText("Vertice: " + gcnew String(par.first, 1) + " -> ");
			for (auto& vecino : par.second) {
				pruebTexto1->AppendText(gcnew String(vecino, 1) + " ");
			}
			pruebTexto1->AppendText("\r\n");
		}
		ActualizarMatriz();
		pictureGrafo->Invalidate();
		grafoCreado = true;
		MostrarPaso(0);

	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		estado = 1; //aleatorio
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		estado = 2; //manual
	}
	private: System::Void pictureGrafo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		if (cantidadVertices <= 0) return;
		Graphics^ g = e->Graphics;
		g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

		int n = cantidadVertices;
		float rNodo = 20.0f;
		float cx = pictureGrafo->Width / 2.0f;
		float cy = pictureGrafo->Height / 2.0f;
		float R = Math::Min(cx, cy) - rNodo - 25.0f;
		const double PI = 3.14159265358979;

		// posición de cada vértice según su letra (A = 0, B = 1, ...)
		cli::array<PointF>^ pos = gcnew cli::array<PointF>(n);
		for (int i = 0; i < n; i++) {
			double ang = -PI / 2 + 2 * PI * i / n;
			pos[i] = PointF(cx + (float)(R * Math::Cos(ang)), cy + (float)(R * Math::Sin(ang)));
		}

		Pen^ pen = gcnew Pen(Color::LightGray, 2.0f);
		pen->CustomEndCap = gcnew System::Drawing::Drawing2D::AdjustableArrowCap(5, 5);

		// aristas: una flecha por cada conexión del hashmap
		for (auto& par : grafo->getMatrizAdyacencia()) {
			int i = par.first - 'A';
			for (auto& vecino : par.second) {
				int j = vecino - 'A';
				if (i == j) { // lazo con flecha
					float ux = (pos[i].X - cx) / R, uy = (pos[i].Y - cy) / R;
					float rLazo = 14.0f;
					float lx = pos[i].X + ux * (rNodo + 8), ly = pos[i].Y + uy * (rNodo + 8);
					float angFuera = (float)(Math::Atan2(uy, ux) * 180.0 / PI);
					// el hueco del arco queda mirando al vértice
					g->DrawArc(pen, lx - rLazo, ly - rLazo, 2 * rLazo, 2 * rLazo, angFuera + 180.0f + 40.0f, 280.0f);
				}
				else {
					DibujarFlecha(g, pen, pos[i], pos[j], rNodo);
				}
			}
		}

		// vértices con su letra
		Brush^ relleno = gcnew SolidBrush(Color::FromArgb(88, 101, 242));
		System::Drawing::Font^ fuente = gcnew System::Drawing::Font("Segoe UI", 11.0f, FontStyle::Bold);
		StringFormat^ sf = gcnew StringFormat();
		sf->Alignment = StringAlignment::Center;
		sf->LineAlignment = StringAlignment::Center;

		for (int i = 0; i < n; i++) {
			RectangleF rect(pos[i].X - rNodo, pos[i].Y - rNodo, 2 * rNodo, 2 * rNodo);
			g->FillEllipse(relleno, rect);
			g->DrawEllipse(Pens::White, rect);
			g->DrawString(gcnew String((char)('A' + i), 1), fuente, Brushes::White, rect, sf);
		}

	}
	private: System::Void btnAtras_Click(System::Object^ sender, System::EventArgs^ e) {
		if (pasoActual > 0) MostrarPaso(pasoActual - 1);
	}
	private: System::Void btnSiguiente_Click(System::Object^ sender, System::EventArgs^ e) {
		Siguiente();
	}


	//desde aqui
		   bool hayArista(char a, char b) {
			   const auto& mapa = grafo->getMatrizAdyacencia();
			   auto it = mapa.find(a);
			   if (it == mapa.end()) return false;
			   return std::find(it->second.begin(), it->second.end(), b) != it->second.end();
		   }

		   void MostrarPaso(int paso) {
			   panelConfig->Visible = (paso == 0);
			   panelGrafo->Visible = (paso == 1);
			   pasoActual = paso;

			   btnAtras->Enabled = (paso > 0);
			   btnSiguiente->Enabled = (paso < ultimoPaso) && (paso > 0 || grafoCreado);
		   }

		   void Siguiente() {
			   if (pasoActual < ultimoPaso) MostrarPaso(pasoActual + 1);
		   }

		   void ActualizarMatriz() {
			   System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();
			   sb->Append("   ");
			   for (char c = 'A'; c < 'A' + cantidadVertices; c++)
				   sb->Append(gcnew String(c, 1) + "  ");
			   sb->Append(Environment::NewLine);

			   for (char i = 'A'; i < 'A' + cantidadVertices; i++) {
				   sb->Append(gcnew String(i, 1) + "  ");
				   for (char j = 'A'; j < 'A' + cantidadVertices; j++)
					   sb->Append((hayArista(i, j) ? "1" : "0") + "  ");
				   sb->Append(Environment::NewLine);
			   }
			   txtMatriz->Text = sb->ToString();
		   }

		   // flecha de p1 a p2, desplazada a un lado para que ida y vuelta no se superpongan
		   void DibujarFlecha(Graphics^ g, Pen^ pen, PointF p1, PointF p2, float r) {
			   float dx = p2.X - p1.X, dy = p2.Y - p1.Y;
			   float len = (float)Math::Sqrt(dx * dx + dy * dy);
			   if (len < 1) return;
			   float ux = dx / len, uy = dy / len;
			   float ox = -uy * 5.0f, oy = ux * 5.0f;   // desplazamiento perpendicular
			   g->DrawLine(pen, p1.X + ux * r + ox, p1.Y + uy * r + oy,
				   p2.X - ux * r + ox, p2.Y - uy * r + oy);
		   }


};
}