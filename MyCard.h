//
// Created by myself on 4/21/20.
//

#ifndef LISTMAKER060_MYCARD_H
#define LISTMAKER060_MYCARD_H

#include <wx/wx.h>
#include "MyCardFrame.h"

class MyCard:public wxPanel{
//CONSTRUCTOR////////////////////////////////////
public:
    MyCard(wxWindow *parent,
    wxWindowID id,
    const wxPoint &pos,
    const wxSize &size);

    void OnCardClicked(wxCommandEvent &evt);

private:
    wxButton*Card;
//END////////////////////////////////////////////
//MYCARDFRAME////////////////////////////////////
public:
    //Other list Name
    int *numCard[4];
    wxPanel*anyPanel[4]={};
    wxString anyTitle[4];
    void CreateButtons();
    wxButton*listName[4];
    void OnButton1(wxCommandEvent &evt);
    void OnButton2(wxCommandEvent &evt);
    void OnButton3(wxCommandEvent &evt);
    void OnButton4(wxCommandEvent &evt);
    wxPanel*thisPanel;
public:
    //Members
    wxButton*addMember;
    wxTextCtrl*nameMember;
    void NewMember(wxCommandEvent &evt);
    int numberMember=0;
    wxButton*Member[3]={};
    wxString labelMember[3]={};
    wxPanel*hidingPanel;
    wxButton*removeMember[3];
    void RemoveMember1(wxCommandEvent &evt);
    void RemoveMember2(wxCommandEvent &evt);
    void RemoveMember3(wxCommandEvent &evt);
public:
    //Labels
    MyCardFrame*cardFrame;
    wxButton*highPriority;
    wxButton*deadLine;
    bool things[2]={false,false};
public:
    //Sublist
    int numberSublist=0;
    wxButton*addSublist;
    wxTextCtrl*nameSublist;
    wxPanel*panelSublist[6];
    wxButton*removeSublist[6];
    wxString stringSublist[6]={};
    wxCheckBox*checkboxSublist[6];
    wxStaticText*staticSublist[6];
    void NewSublist(wxCommandEvent &evt);
    wxPanel*coverPanel;
    void RemoveSublist1(wxCommandEvent &evt);
    void RemoveSublist2(wxCommandEvent &evt);
    void RemoveSublist3(wxCommandEvent &evt);
    void RemoveSublist4(wxCommandEvent &evt);
    void RemoveSublist5(wxCommandEvent &evt);
    void RemoveSublist6(wxCommandEvent &evt);
    bool labelsSublist[6]={false,false,false,false,false,false};
    void SetCheckBox1(wxCommandEvent &evt);
    void SetCheckBox2(wxCommandEvent &evt);
    void SetCheckBox3(wxCommandEvent &evt);
    void SetCheckBox4(wxCommandEvent &evt);
    void SetCheckBox5(wxCommandEvent &evt);
    void SetCheckBox6(wxCommandEvent &evt);

//END////////////////////////////////////////////
wxDECLARE_EVENT_TABLE();
};


#endif //LISTMAKER060_MYCARD_H