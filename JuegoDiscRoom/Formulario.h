#pragma once
#include "Juego.h"
#include "Jugador.h"
namespace JuegoDiscRoom {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Formulario
	/// </summary>
	public ref class Formulario : public System::Windows::Forms::Form
	{
	public:
		CJuego * objJuego=new CJuego();

	public:
		Bitmap ^ bmpNivel1 = gcnew Bitmap("todaimagen\\MapaNivel1.png");
		Bitmap ^ bmpBatman = gcnew Bitmap("todaImagen\\personajeBatman.png");
		Formulario(void)
		{
			bmpBatman->MakeTransparent(bmpBatman->GetPixel(0,0));
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~Formulario()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Formulario::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Formulario::timer1_Tick);
			// 
			// Formulario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(682, 653);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Formulario";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DISC ROOM-UPC";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Formulario::TeclaPresionada);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Formulario::UltimaTecla);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^buffer = espacio->Allocate(g, this->ClientRectangle);
		//buffer->Graphics->Clear(Color::White);
		objJuego->dibujarJuego(buffer->Graphics,bmpNivel1,bmpBatman);
		buffer->Render(g);
		delete buffer;
		delete	espacio; 
		delete g;
	}
	private: System::Void TeclaPresionada(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode)
		{
		case Keys::Up:
			objJuego->getObjJugador()->setDirecciones(Direcciones::Arriba);
			break;
		case Keys::Down:
			objJuego->getObjJugador()->setDirecciones(Direcciones::Abajo);
			break;
		case Keys::Right:
			objJuego->getObjJugador()->setDirecciones(Direcciones::Derecha);
			break;
		case Keys::Left:
			objJuego->getObjJugador()->setDirecciones(Direcciones::Izquierda);
			break;

		default:
			break;
		}
	}
	private: System::Void UltimaTecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode)
		{
		default:
			objJuego->getObjJugador()->setDirecciones(Direcciones::Ninguno);
			break;
		}
	}
	};
}
