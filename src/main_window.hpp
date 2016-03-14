#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
   #include <wx/wx.h>
#endif
#include "game.hpp"
#include <memory>
#include <vector>
class MainWindow: public wxFrame {
public:
  MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size);
  std::unique_ptr<Game> currentGame;
  wxPanel * board_panel, * panel, *currentHand;
private:
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnNewGame(wxCommandEvent& event);
    DECLARE_EVENT_TABLE();
};
