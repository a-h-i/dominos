#include "main_window.hpp"
#include "card_button.hpp"
#include <cstdlib>
#include <ctime>

enum MainWindowEvents { ID_NEW_GAME };

BEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_MENU(wxID_EXIT, MainWindow::OnExit)
    EVT_MENU(wxID_ABOUT, MainWindow::OnAbout)
    EVT_MENU(MainWindowEvents::ID_NEW_GAME, MainWindow::OnNewGame)
END_EVENT_TABLE()


void drawHand(Player *p, wxPanel * panel) {
  for (auto & card : p->hand) {
    auto cardPanel = new wxPanel(panel, wxID_NEW,
      wxPoint(-1, -1), wxSize(-1, -1));
    cardPanel.SetBackgroundColour(wxColour(0, 0, 0));
    
  }
}



MainWindow::MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size) {
    wxMenu *menuGame = new wxMenu;
    menuGame->Append(MainWindowEvents::ID_NEW_GAME, L"&New Game...\tCtrl-N",
                    L"Start a new game");
    menuGame->AppendSeparator();
    menuGame->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuGame, L"&Game" );
    menuBar->Append( menuHelp, L"&Help" );
    SetMenuBar( menuBar );
    CreateStatusBar();

    panel = new wxPanel(this, wxID_ANY);
    board_panel = nullptr;

    Centre();
}

void MainWindow::OnNewGame(wxCommandEvent& event) {
  std::srand(std::time(0));
  currentGame = std::make_unique<Game>(2);
  if (board_panel != nullptr) {
    board_panel->Destroy();
  }
  board_panel = new wxPanel(panel, wxID_NEW,
  wxPoint(15, 20), wxSize(750, 500), wxSUNKEN_BORDER);

  board_panel->SetBackgroundColour(wxColour(0, 77, 64));
  SetStatusText(L"Player One's turn");

  currentHand = new wxPanel(panel, wxID_NEW,
    wxPoint(), wxSize(750, 400), wxSUNKEN_BORDER);
  Player & currentPlayer = currentGame.getCurrentPlayer();
  drawHand(&currentPlayer, currentHand);
}

void MainWindow::OnExit(wxCommandEvent& event) {
    Close( true );
}

void MainWindow::OnAbout(wxCommandEvent& event) {
    wxMessageBox( L"Simple Dominos game written in C++",
                  L"About Dominos", wxOK | wxICON_INFORMATION );
}
