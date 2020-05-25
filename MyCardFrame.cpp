//
// Created by myself on 5/1/20.
//

#include "MyCardFrame.h"

MyCardFrame::MyCardFrame(wxWindow *parent,
                         wxWindowID id,
                         const wxString& name,
                         const wxPoint& pos,
                         const wxSize& size)
        :wxFrame(parent,id,name,pos,size)
{
    //LEFT PANEL
    leftPanel = new wxPanel(this);
    leftPanel->SetBackgroundColour(wxColor(60,60,110,60));

    //RIGHT PANEL
    rightPanel=new wxPanel(leftPanel,-1,wxDefaultPosition,wxDefaultSize);
    rightPanel->SetBackgroundColour(wxColor(70,70,120,70));

    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(rightPanel, 1, wxEXPAND | wxLEFT, 300);
    leftPanel->SetSizer(vbox);
    //END///////////////////////////////////////////////////
    //LEFT PANEL
    //Sublist
    title[0]=new wxStaticText(leftPanel,wxID_ANY,"SUBLIST",wxPoint(13,10));

    //RIGHT PANEL
    //Labels
    title[2]=new wxStaticText(rightPanel,wxID_ANY,"LABELS",wxPoint(13,10));
    label[0]=new wxCheckBox(rightPanel,wxID_ANY,"High Priority",wxPoint(10,30));
    label[0]->Bind(wxEVT_COMMAND_CHECKBOX_CLICKED,&MyCardFrame::AddLabel1,this);
    label[1]=new wxCheckBox(rightPanel,wxID_ANY,"Dead Line",wxPoint(10,60));
    label[1]->Bind(wxEVT_COMMAND_CHECKBOX_CLICKED,&MyCardFrame::AddLabel2,this);
    txt[2]=new wxTextCtrl(rightPanel,wxID_ANY,"",wxPoint(100,55),wxSize(100,30));
    //Members
    title[1]=new wxStaticText(rightPanel,wxID_ANY,"MEMBERS",wxPoint(13,110));
    //Move
    title[2]=new wxStaticText(rightPanel,wxID_ANY,"MOVE TO ANOTHER LIST",wxPoint(13,230));

}

void MyCardFrame::AddLabel1(wxCommandEvent &evt) {
    if(label[0]->GetValue()){
        *highPriority=new wxButton(cardAnswer,-1,"High priority",wxPoint(0,0),wxSize(100,25));
        //highPriority->SetForegroundColour(wxColor(255,0,0,0));
        *things[0]=true;
        label[0]->SetValue(true);
        //*checkBox[0]=1;
    }else{
        delete *highPriority;
        *things[0]=false;
        label[0]->SetValue(false);
    }
    evt.Skip();
}
void MyCardFrame::AddLabel2(wxCommandEvent &evt) {
    if(label[1]->GetValue()){
        expiration=txt[2]->GetValue();
        *deadLine=new wxButton(cardAnswer,-1,txt[2]->GetValue(),wxPoint(100,0),wxSize(100,25));
        //highPriority->SetForegroundColour(wxColor(255,0,0,0));
        *things[1]=true;
        label[1]->SetValue(true);
        //*checkBox[1]=1;
    }else{
        delete *deadLine;
        *things[1]=false;
        label[1]->SetValue(false);
    }
    evt.Skip();
}
