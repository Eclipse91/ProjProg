//
// Created by myself on 5/1/20.
//

#ifndef LISTMAKER10_MYCARDFRAME_H
#define LISTMAKER10_MYCARDFRAME_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <wx/wx.h>
#include "Controller.h"
#include "MySublist.h"

class MyCardFrame:public wxFrame {
//CONSTRUCTOR////////////////////////////////////
public:
    MyCardFrame(std::list<string>* l,std::list<string>* ca,std::list<string>* caf,
                Model *m, Controller *c,
                int *numberOfSublists,
                wxWindow *parent,
                wxWindowID id,
                const wxString& name,
                const wxPoint& pos,
                const wxSize& size);
    wxPanel*leftPanel;
    wxPanel*rightPanel;

//END////////////////////////////////////////////
    void AddHighPriority(wxCommandEvent &evt);
    void AddDeadLine(wxCommandEvent &evt);
    void AddSublist(wxCommandEvent &evt);
    std::string GetPanelName();
    void DisplayMyCardFrame();
    wxStaticText*sublists;
    wxTextCtrl*nameSublist;
    wxStaticText*labels;
    wxCheckBox*CheckHigh;
    wxCheckBox*CheckDead;
    wxTextCtrl*TxtDead;
    wxStaticText*members;
    wxStaticText*MoveCards;
    std::string CardFrameName;
    wxButton**DeadL;
    wxButton**highPriority;
    int* numberOfSublist,num=0;
private:
    Model* model;
    Controller* controller;
    std::list<string>* List;
    std::list<string>* Card;
    std::list<string>* CardFrame;
};


#endif //LISTMAKER10_MYCARDFRAME_H
