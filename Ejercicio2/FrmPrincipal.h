#pragma once
#include "Circulo.h"
#include "Rectangulo.h"
#include "Triangulo.h"
namespace Ejercicio2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmPrincipal
	/// </summary>
	public ref class FrmPrincipal : public System::Windows::Forms::Form
	{
	private:
		int cont;
		CCirculo*oCirculo;
		CRectangulo*oRectangulo;
		CTriangulo*oTriangulo;
		Bitmap^bmpFondo = gcnew Bitmap("Imagenes\\puestos.jpg");
		int puesto;
		bool c;
		bool r;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
			 bool t;
	public:
		FrmPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			cont = 0;
			puesto = 1;
			c = false;
			r = false;
			t = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::Windows::Forms::Timer^  timer2;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmPrincipal::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmPrincipal::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 2500;
			this->timer2->Tick += gcnew System::EventHandler(this, &FrmPrincipal::timer2_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-19, 102);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(620, 413);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(262, 142);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(117, 215);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(401, 238);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"label3";
			// 
			// FrmPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 562);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"FrmPrincipal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FrmPrincipal";
			this->Load += gcnew System::EventHandler(this, &FrmPrincipal::FrmPrincipal_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
		Random r;
		if(cont==0)
			oCirculo = new CCirculo(4, 100, r.Next(4, 15), 100, 100);
		if(cont==1)
			oRectangulo = new CRectangulo(4, 250, r.Next(4, 15), 100, 100);
		if (cont == 2) {
			oTriangulo = new CTriangulo(54, 400, r.Next(4, 15), 100, 100);
			timer2->Enabled = false;
			timer1->Enabled = true; // Pasamos a graficar
		}
		cont++;
		
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext ^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->DrawLine(Pens::Yellow, 500, 0, 500, this->Height);
		oCirculo->dibujar(buffer->Graphics);
		oCirculo->mover(500);

		oRectangulo->dibujar(buffer->Graphics);
		oRectangulo->mover(500);

		oTriangulo->dibujar(buffer->Graphics);
		oTriangulo->mover(500);

		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;
		if (oCirculo->getCont() == 5 && c==false) {
			oCirculo->setPuesto(puesto);
			puesto++;
			c = true;
		}
		if (oRectangulo->getCont() == 5 && r==false) {
			oRectangulo->setPuesto(puesto);
			puesto++;
			r = true;
		}
		if (oTriangulo->getCont() == 5 && t==false) {
			oTriangulo->setPuesto(puesto);
			puesto++;
			t = true;
		}

		this->Text = "SCORE || Circulo: " + oCirculo->getCont()
			+ " Rectangulo: " + oRectangulo->getCont()
			+ "Triangulo: " + oTriangulo->getCont();
		if (oCirculo->getCont() == 5 && oRectangulo->getCont() == 5 && oTriangulo->getCont()==5) {
			if (oCirculo->getpuesto() > oRectangulo->getpuesto() && oCirculo->getpuesto() > oTriangulo->getpuesto())
			{
				label1->Text = "Circulo";
				if (oTriangulo->getpuesto() < oRectangulo->getpuesto())
				{
					label2->Text = "Rectangulo";
					label3->Text = "Triangulo";
				}
				else {
					label2->Text = "Triangulo";
					label3->Text = "Rectangulo";
				}
			}
			else {
				if (oCirculo->getpuesto() < oRectangulo->getpuesto() && oTriangulo->getpuesto() < oRectangulo->getpuesto())
				{
					label1->Text = "Rectangulo";
					if (oTriangulo->getpuesto() < oCirculo->getpuesto())
					{
						label2->Text = "Circulo";
						label3->Text = "Triangulo";
					}
					else {
						label2->Text = "Triangulo";
						label3->Text = "Circulo";
					}
				}
				else {
					label1->Text = "Triangulo";
					if (oRectangulo->getpuesto() < oCirculo->getpuesto())
					{
						label2->Text = "Circulo";
						label3->Text = "Rectangulo";
					}
					else {
						label2->Text = "Rectangulo";
						label3->Text = "Circulo";
					}

				}
			}
			pictureBox1->Visible = true;
			label1->Visible = true;
			label2->Visible = true;
			label3->Visible = true;
			timer1->Enabled = false;
		}
	}
	private: System::Void FrmPrincipal_Load(System::Object^  sender, System::EventArgs^  e) {
		pictureBox1->Visible = false;
		label1->Visible = false;
		label2->Visible = false;
		label3->Visible = false;
	}
};
}
