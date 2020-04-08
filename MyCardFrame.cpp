//
// Created by myself on 4/2/20.
//

#include "MyCardFrame.h"

MyCardFrame::MyCardFrame(wxWindow *parent,
                         wxWindowID id,
                         const wxString& name,
                         const wxPoint& pos,
                         const wxSize& size)
                         : wxFrame(parent,id,name,pos,size) {
    Label1=new wxCheckBox(this,wxID_ANY,"High Priority",wxPoint(400,100));
    Label1->Bind(wxEVT_COMMAND_CHECKBOX_CLICKED,&MyCardFrame::AddLabel,this);

    SubList=new wxListBox(this,wxID_ANY,wxPoint(10,50),wxSize(300,300));
}
void MyCardFrame::AddLabel(wxCommandEvent &evt) {
    if(Label1->GetValue()){

        //Card->SetBitmapLabel(wxBitmap(wxT("/opt/wxWidgets-3.0.4/art/minus.xpm"), wxBITMAP_TYPE_XPM));
        highPriority=new wxButton(PanelUno,-1,"High priority",wxPoint(Card->GetPosition().x+100,Card->GetPosition().y+25),wxSize(100,25));
        highPriority->SetForegroundColour(wxColor(255,0,0,0));
        //CardUno->SetPosition(wxPoint(100,100));
        //CardUno->SetParent(PanelDue);
        Label1->SetValue(true);

    }else{
        delete highPriority;
        //Card->SetBitmapLabel(wxBitmap(wxT("/opt/wxWidgets-3.0.4/art/llNone.xpm"), wxBITMAP_TYPE_XPM));
        Label1->SetValue(false);
    }
    //CardUno->SetBitmapLabel(wxBitmap(wxT("/opt/wxWidgets-3.0.4/art/minus.xpm"), wxBITMAP_TYPE_PNG));
    evt.Skip();
}


