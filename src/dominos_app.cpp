#include "main_window.hpp"
#include "dominos_app.hpp"

bool DominosApp::OnInit() {
    MainWindow *frame = new MainWindow( L"Dominos",
      wxDefaultPosition, wxSize(800, 900));
    frame->Show( true );
    return true;
}
