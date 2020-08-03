//
// Created by myself on 6/9/20.
//

#ifndef LISTMAKER05_MYPANEL_H
#define LISTMAKER05_MYPANEL_H

#include "Controller.h"
#include "MyCard.h"

class MyPanel:public wxPanel{
public:
    MyPanel(Model* m, Controller* c,
            wxWindow *parent,
            wxWindowID id,
            const wxPoint &pos,
            const wxSize &size);
    wxPanel*frontPanel;
    wxButton*newCard;
    wxTextCtrl*txt;
    wxButton*deleteList;
    wxButton*rightList;
    wxButton*leftList;
    wxStaticText*listName;
public:
    void DeleteList(wxCommandEvent& evt);
    void NewCard(wxCommandEvent& evt);
    void MoveRight(wxCommandEvent& evt);
    void MoveLeft(wxCommandEvent& evt);
private:
    Model* model;
    Controller* controller;
};


#endif //LISTMAKER05_MYPANEL_H
