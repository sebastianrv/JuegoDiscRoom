#include "Formulario.h"
using namespace JuegoDiscRoom;

using namespace System;
using namespace System::Windows::Forms; [STAThread]
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew JuegoDiscRoom::Formulario());
}
