//
// Created by myself on 3/31/20.
//

#ifndef TEST00_MYPANEL_H
#define TEST00_MYPANEL_H

#include "wx/wx.h"
#include "MyCardFrame.h"

class MyPanel: public wxPanel {
public:
    MyPanel(wxWindow *parent,
             wxWindowID id,
             const wxPoint& pos,
             const wxSize& size);
    wxButton*newText;
    wxTextCtrl*txt;
    int numberCard=0;
    int ca1=0,ca2=0,ca3=0,ca4=0,ca5=0;
    void OnButtonClicked(wxCommandEvent &evt);



    wxPanel*panelOne;
    wxPanel*panelTwo;
    wxPanel*panelThree;
    wxPanel*panelFour;

    wxButton*Card1;
    wxButton*deleteCard1;
    void DeleteCard1(wxCommandEvent &evt);
    void OnCardClicked1(wxCommandEvent &evt);

    wxButton*Card2;
    wxButton*deleteCard2;
    void DeleteCard2(wxCommandEvent &evt);
    void OnCardClicked2(wxCommandEvent &evt);

    wxButton*Card3;
    wxButton*deleteCard3;
    void DeleteCard3(wxCommandEvent &evt);
    void OnCardClicked3(wxCommandEvent &evt);

    wxButton*Card4;
    wxButton*deleteCard4;
    void DeleteCard4(wxCommandEvent &evt);
    void OnCardClicked4(wxCommandEvent &evt);


    wxButton*Card5;
    wxButton*deleteCard5;
    void DeleteCard5(wxCommandEvent &evt);
    void OnCardClicked5(wxCommandEvent &evt);
};


#endif //TEST00_MYPANEL_H
