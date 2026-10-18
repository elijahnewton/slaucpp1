#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace SLAUGRADING;
using namespace SLAUGRADING::Data;

[STAThread]
int Main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    bool configured = DatabaseConfig::Load();

    MainForm^ form = gcnew MainForm();

    if (!configured) {
        SettingsForm^ sf = gcnew SettingsForm();
        if (sf->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
            return 0;
        }
    }

    Application::Run(form);
    return 0;
}