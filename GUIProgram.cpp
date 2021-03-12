#include "PhotoViewer.h"
#include "GUIProgram.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]//leave this as is
void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    MiniPhotoshop3::GUIProgram form;
    Application::Run(% form);
}