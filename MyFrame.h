//
// Created by myself on 3/4/20.
//

#ifndef LISTMAKER07_MYFRAME_H
#define LISTMAKER07_MYFRAME_H

#include "wx/wx.h"
#include "MyPanel.h"

class MyFrame: public wxFrame {
public:
    MyFrame();

    void ListCreator(wxCommandEvent &evt);
    wxPanel*topPanel;
    wxPanel*bottomPanel;
    wxTextCtrl*nameList;

    MyPanel*listPanel1;
    wxStaticText*Title1;
    wxButton*Deleter1;
    void ListDelete1(wxCommandEvent &evt);
    MyPanel*listPanel2;
    wxStaticText*Title2;
    wxButton*Deleter2;
    void ListDelete2(wxCommandEvent &evt);
    MyPanel*listPanel3;
    wxStaticText*Title3;
    wxButton*Deleter3;
    void ListDelete3(wxCommandEvent &evt);
    MyPanel*listPanel4;
    wxStaticText*Title4;
    wxButton*Deleter4;
    void ListDelete4(wxCommandEvent &evt);

    wxDECLARE_EVENT_TABLE();

};


#endif //LISTMAKER07_MYFRAME_H
