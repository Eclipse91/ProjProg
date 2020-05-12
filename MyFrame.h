//
// Created by myself on 3/28/20.
//

#ifndef LISTMAKER00_MYFRAME_H
#define LISTMAKER00_MYFRAME_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <wx/wx.h>
#include "MyCard.h"

class MyFrame:public wxFrame{
//CONSTRUCTOR///////////////////////////////////
public:
    MyFrame();
private:
    wxPanel*topPanel;
    wxPanel*bottomPanel;
    wxTextCtrl*nameList;
//END////////////////////////////////////////////
//MENUBAR/////////////////////////////////////////
public:
    void OnMenuNew(wxCommandEvent &evt);
    void OnMenuOpen(wxCommandEvent &evt);
    void OnMenuSave(wxCommandEvent &evt);
    void OnMenuExit(wxCommandEvent &evt);

private:
    wxMenuBar *m_MenuBar= nullptr;
//END////////////////////////////////////////////

//PANELS/////////////////////////////////////////
public:
    void ListCreator(wxCommandEvent &evt);
    void ListDelete1(wxCommandEvent &evt);
    void ListDelete2(wxCommandEvent &evt);
    void ListDelete3(wxCommandEvent &evt);
    void ListDelete4(wxCommandEvent &evt);
    void SetListPosition(int x);
    void OnButtonClicked1(wxCommandEvent &evt);
    void OnButtonClicked2(wxCommandEvent &evt);
    void OnButtonClicked3(wxCommandEvent &evt);
    void OnButtonClicked4(wxCommandEvent &evt);
private:
    int posList=0, countList=0;
    wxPanel*listPanel[4];
    wxStaticText*Title[4];
    wxButton*Deleter[4];
private:
    wxPanel*frontPanel[4];
    wxButton*newText[4];
    wxTextCtrl*txt[4];
//END////////////////////////////////////////////

//CARDS/////////////////////////////////////////
public:
    void DeleteCard1(wxCommandEvent &evt);
    void DeleteCard2(wxCommandEvent &evt);
    void DeleteCard3(wxCommandEvent &evt);
    void DeleteCard4(wxCommandEvent &evt);
    void DeleteCard5(wxCommandEvent &evt);
    void DeleteCard6(wxCommandEvent &evt);
    void DeleteCard7(wxCommandEvent &evt);
    void DeleteCard8(wxCommandEvent &evt);
    void DeleteCard9(wxCommandEvent &evt);
    void DeleteCard10(wxCommandEvent &evt);
    void DeleteCard11(wxCommandEvent &evt);
    void DeleteCard12(wxCommandEvent &evt);
    void DeleteCard13(wxCommandEvent &evt);
    void DeleteCard14(wxCommandEvent &evt);
    void DeleteCard15(wxCommandEvent &evt);
    void DeleteCard16(wxCommandEvent &evt);
    void DeleteCard17(wxCommandEvent &evt);
    void DeleteCard18(wxCommandEvent &evt);
    void DeleteCard19(wxCommandEvent &evt);
    void DeleteCard20(wxCommandEvent &evt);

    void CreateCard(int list);
    void MoveCards(wxPanel*aList,int posCardList,int *numCardList);
    void PassList();
private:
    int numCard[4],posCard=0,totCard=0;
    MyCard*Card[20]={};
    wxStaticText*pointsToDo[20];
    wxButton*deleteCard[20];

wxDECLARE_EVENT_TABLE();

};


#endif //LISTMAKER00_MYFRAME_H
