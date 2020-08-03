//
// Created by myself on 6/7/20.
//

#ifndef LISTMAKER04_VIEW_H
#define LISTMAKER04_VIEW_H

#include "Controller.h"
#include "MyPanel.h"

class View:public Observer,public wxFrame {
public:
    View(Model* m, Controller* c);

    virtual ~View() {
        model->removeObserver (this);
    }
    virtual void update() {
        DeleteList();
        std::list<string>* List=model->getList();
        std::list<string>* Card=model->getCard();
        std::list<string>* CardFrame=model->getCardFrame();
        DisplayList(List);
    }
    void ListCreator(wxCommandEvent &evt);
    void DisplayList(std::list<string>* List);
    void DeleteList();
    void DisplayCard(MyPanel*Panel,std::list<string>* Card,std::list<string>* List);
    void DisplayCardFeature(MyCard*PanelCard,std::string Card,std::string List);

private:
    Model* model;
    Controller* controller;
private:
    wxMenuBar*m_MenuBar;
    wxMenu *menuFile;
    wxPanel*topPanel;
    wxPanel*bottomPanel;
    wxBoxSizer*vbox;
    wxButton*Creator;
    wxTextCtrl*nameList;

public:
    void OnMenuNew(wxCommandEvent &evt);
    void ClearLists();
    void OnMenuOpen(wxCommandEvent &evt);
    bool Open(wxString fileName);
    void OnMenuSave(wxCommandEvent &evt);
    bool Save(wxString fileName);
    void OnMenuExit(wxCommandEvent &evt);
wxDECLARE_EVENT_TABLE();
};
#endif //LISTMAKER04_VIEW_H
