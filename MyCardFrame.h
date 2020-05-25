//
// Created by myself on 5/1/20.
//

#ifndef LISTMAKER10_MYCARDFRAME_H
#define LISTMAKER10_MYCARDFRAME_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <wx/wx.h>

class MyCardFrame:public wxFrame {
//CONSTRUCTOR////////////////////////////////////
public:
    MyCardFrame(wxWindow *parent,
                wxWindowID id,
                const wxString& name,
                const wxPoint& pos,
                const wxSize& size);

    wxPanel*leftPanel;
    wxPanel*rightPanel;
    void AddLabel1(wxCommandEvent &evt);
    void AddLabel2(wxCommandEvent &evt);
//END////////////////////////////////////////////
public:
    //Members
    wxStaticText*title[3];
    wxTextCtrl*txt[3];
    wxListBox*list[2];
    wxButton*btn[2];
    //Info of the card
    wxString cardTitle;
    wxString expiration;
    wxButton**highPriority;
    wxButton**deadLine;
    wxPanel*cardAnswer;
    wxCheckBox*label[3];
    bool*things[2];
};


#endif //LISTMAKER10_MYCARDFRAME_H
