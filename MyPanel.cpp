//
// Created by myself on 3/31/20.
//

#include "MyPanel.h"


MyPanel::MyPanel(wxWindow *parent,
                 wxWindowID id,
                 const wxPoint& pos,
                 const wxSize& size)
                 :wxPanel(parent, id, pos, size)
{
    newText=new wxButton(this,wxID_ANY,"Add Card",wxPoint(10,30),wxSize(140,30));
    newText->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyPanel::OnButtonClicked,this);
    txt=new wxTextCtrl(this,wxID_ANY,"",wxPoint(10,60),wxSize(200,30));


}
void MyPanel::OnButtonClicked(wxCommandEvent &evt) {
    int a=75,b=10;
    if(!ca1){
        b=b+(numberCard)*50;
        Card1=new wxButton(this,wxID_ANY,txt->GetValue(),wxPoint(a,b+85),wxSize(200,50));
        Card1->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyPanel::OnCardClicked1,this);
        deleteCard1=new wxButton(this,wxID_ANY,"X",wxPoint(Card1->GetPosition().x+200,b+85),wxSize(25,25));
        //deleteCard1->SetBitmap(wxBitmap(wxT("/opt/wxWidgets-3.0.4/art/close.xpm"),wxBITMAP_TYPE_XPM));
        deleteCard1->SetForegroundColour(wxColor(255,0,0,0));
        deleteCard1->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyPanel::DeleteCard1,this);
        ca1=1+numberCard;
    }else if(!ca2) {
        b=b+(numberCard)*50;
        Card2=new wxButton(this,wxID_ANY,txt->GetValue(),wxPoint(a,b+85),wxSize(200,50));
        Card2->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyPanel::OnCardClicked2,this);
        deleteCard2=new wxButton(this,wxID_ANY,"X",wxPoint(Card2->GetPosition().x+200,b+85),wxSize(25,25));
        //deleteCard2->SetBitmap(wxBitmap(wxT("/opt/wxWidgets-3.0.4/art/close.xpm"),wxBITMAP_TYPE_XPM));
        deleteCard2->SetForegroundColour(wxColor(255,0,0,0));

        deleteCard2->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyPanel::DeleteCard2,this);
        ca2=1+numberCard;
    }else if(!ca3) {
        b=b+(numberCard)*50;
        Card3=new wxButton(this,wxID_ANY,txt->GetValue(),wxPoint(a,b+85),wxSize(200,50));
        Card3->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyPanel::OnCardClicked3,this);
        deleteCard3=new wxButton(this,wxID_ANY,"X",wxPoint(Card3->GetPosition().x+200,b+85),wxSize(25,25));
        //deleteCard3->SetBitmap(wxBitmap(wxT("/opt/wxWidgets-3.0.4/art/close.xpm"),wxBITMAP_TYPE_XPM));
        deleteCard3->SetForegroundColour(wxColor(255,0,0,0));

        deleteCard3->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyPanel::DeleteCard3,this);
        ca3=1+numberCard;
    }else if(!ca4) {
        b=b+(numberCard)*50;
        Card4=new wxButton(this,wxID_ANY,txt->GetValue(),wxPoint(a,b+85),wxSize(200,50));
        Card4->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyPanel::OnCardClicked4,this);
        deleteCard4=new wxButton(this,wxID_ANY,"X",wxPoint(Card4->GetPosition().x+200,b+85),wxSize(25,25));
        deleteCard4->SetForegroundColour(wxColor(255,0,0,0));

        //deleteCard4->SetBitmap(wxBitmap(wxT("/opt/wxWidgets-3.0.4/art/close.xpm"),wxBITMAP_TYPE_XPM));
        deleteCard4->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyPanel::DeleteCard4,this);
        ca4=1+numberCard;
    }else if(!ca5) {
        b=b+(numberCard)*50;
        Card5=new wxButton(this,wxID_ANY,txt->GetValue(),wxPoint(a,b+85),wxSize(200,50));
        Card5->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyPanel::OnCardClicked5,this);
        deleteCard5=new wxButton(this,wxID_ANY,"X",wxPoint(Card5->GetPosition().x+200,b+85),wxSize(25,25));
        deleteCard5->SetForegroundColour(wxColor(255,0,0,0));

        //deleteCard5->SetBitmap(wxBitmap(wxT("/opt/wxWidgets-3.0.4/art/close.xpm"),wxBITMAP_TYPE_XPM));
        deleteCard5->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyPanel::DeleteCard5,this);
        ca5=1+numberCard;
    }else{
            wxMessageDialog *dial = new wxMessageDialog(NULL,
                    wxT("Max number of lists reached"), wxT("Exclamation"),
                    wxOK | wxICON_EXCLAMATION);
            dial->ShowModal();
            numberCard--;
        }
    numberCard++;
    evt.Skip();
}
void MyPanel::OnCardClicked1(wxCommandEvent &evt){
    MyCardFrame*myCardFrame=new MyCardFrame(this,wxID_ANY,Card1->GetLabel(),wxPoint(400,400),wxSize(600,400));
    myCardFrame->Card=Card1;
    if(panelOne)
        myCardFrame->PanelUno=panelOne;
    else if (panelTwo)
        myCardFrame->PanelDue=panelTwo;
    else if(panelThree)
        myCardFrame->PanelTre=panelThree;
    else if(panelFour)
        myCardFrame->PanelQuattro=panelFour;
    myCardFrame->Show(true);
    evt.Skip();
}
void MyPanel::OnCardClicked2(wxCommandEvent &evt) {
    MyCardFrame*myCardFrame=new MyCardFrame(this,wxID_ANY,Card2->GetLabel(),wxPoint(400,400),wxSize(600,400));
    myCardFrame->Card=Card2;
    if(panelOne)
        myCardFrame->PanelUno=panelOne;
    else if (panelTwo)
        myCardFrame->PanelDue=panelTwo;
    else if(panelThree)
        myCardFrame->PanelTre=panelThree;
    else if(panelFour)
        myCardFrame->PanelQuattro=panelFour;
    myCardFrame->Show(true);
    evt.Skip();
}
void MyPanel::OnCardClicked3(wxCommandEvent &evt) {
    MyCardFrame*myCardFrame=new MyCardFrame(this,wxID_ANY,Card3->GetLabel(),wxPoint(400,400),wxSize(600,400));
    myCardFrame->Card=Card3;
    if(panelOne)
        myCardFrame->PanelUno=panelOne;
    else if (panelTwo)
        myCardFrame->PanelDue=panelTwo;
    else if(panelThree)
        myCardFrame->PanelTre=panelThree;
    else if(panelFour)
        myCardFrame->PanelQuattro=panelFour;
    myCardFrame->Show(true);
    evt.Skip();
}
void MyPanel::OnCardClicked4(wxCommandEvent &evt) {
    MyCardFrame*myCardFrame=new MyCardFrame(this,wxID_ANY,Card4->GetLabel(),wxPoint(400,400),wxSize(600,400));
    myCardFrame->Card=Card4;
    if(panelOne)
        myCardFrame->PanelUno=panelOne;
    else if (panelTwo)
        myCardFrame->PanelDue=panelTwo;
    else if(panelThree)
        myCardFrame->PanelTre=panelThree;
    else if(panelFour)
        myCardFrame->PanelQuattro=panelFour;
    myCardFrame->Show(true);
    evt.Skip();
}
void MyPanel::OnCardClicked5(wxCommandEvent &evt) {
    MyCardFrame*myCardFrame=new MyCardFrame(this,wxID_ANY,Card5->GetLabel(),wxPoint(400,400),wxSize(600,400));
    myCardFrame->Card=Card5;
    if(panelOne)
        myCardFrame->PanelUno=panelOne;
    else if (panelTwo)
        myCardFrame->PanelDue=panelTwo;
    else if(panelThree)
        myCardFrame->PanelTre=panelThree;
    else if(panelFour)
        myCardFrame->PanelQuattro=panelFour;
    myCardFrame->Show(true);
    evt.Skip();
}

void MyPanel::DeleteCard1(wxCommandEvent &evt) {
    numberCard--;
    if(ca2 && ca2>ca1){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card2->GetPosition();
        Card2->SetPosition(wxPoint(pos.x,pos.y-50));


        deleteCard2->SetPosition(wxPoint(pos.x+200,pos.y-50));
        ca2--;
    }
    if(ca3 && ca3>ca1){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card3->GetPosition();
        Card3->SetPosition(wxPoint(pos.x,pos.y-50));
        deleteCard3->SetPosition(wxPoint(pos.x+200,pos.y-50));

        ca3--;
    }
    if(ca4 && ca4>ca1){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card4->GetPosition();
        Card4->SetPosition(wxPoint(pos.x,pos.y-50));
        deleteCard4->SetPosition(wxPoint(pos.x+200,pos.y-50));

        ca4--;
    }
    if(ca5 && ca5>ca1){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card5->GetPosition();
        Card5->SetPosition(wxPoint(pos.x,pos.y-50));
        deleteCard5->SetPosition(wxPoint(pos.x+200,pos.y-50));

        ca5--;
    }
    ca1=0;
    delete Card1;
    delete deleteCard1;
}

void MyPanel::DeleteCard2(wxCommandEvent &evt) {
    numberCard--;
    if(ca1 && ca1>ca2){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card1->GetPosition();
        Card1->SetPosition(wxPoint(pos.x,pos.y-50));
        deleteCard1->SetPosition(wxPoint(pos.x+200,pos.y-50));
        ca1--;
    }
    if(ca3 && ca3>ca2){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card3->GetPosition();
        Card3->SetPosition(wxPoint(pos.x,pos.y-50));
        deleteCard3->SetPosition(wxPoint(pos.x+200,pos.y-50));
        ca3--;
    }
    if(ca4 && ca4>ca2){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card4->GetPosition();
        Card4->SetPosition(wxPoint(pos.x,pos.y-50));
        deleteCard4->SetPosition(wxPoint(pos.x+200,pos.y-50));
        ca4--;
    }
    if(ca5 && ca5>ca2){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card5->GetPosition();
        Card5->SetPosition(wxPoint(pos.x,pos.y-50));
        deleteCard5->SetPosition(wxPoint(pos.x+200,pos.y-50));
        ca5--;
    }
    ca2=0;
    delete Card2;
    delete deleteCard2;
}

void MyPanel::DeleteCard3(wxCommandEvent &evt) {
    numberCard--;
    if(ca2 && ca2>ca3){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card2->GetPosition();
        Card2->SetPosition(wxPoint(pos.x,pos.y-50));


        deleteCard2->SetPosition(wxPoint(pos.x+200,pos.y-50));
        ca2--;
    }
    if(ca1 && ca1>ca3){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card1->GetPosition();
        Card1->SetPosition(wxPoint(pos.x,pos.y-50));
        deleteCard1->SetPosition(wxPoint(pos.x+200,pos.y-50));

        ca1--;
    }
    if(ca4 && ca4>ca3){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card4->GetPosition();
        Card4->SetPosition(wxPoint(pos.x,pos.y-50));
        deleteCard4->SetPosition(wxPoint(pos.x+200,pos.y-50));

        ca4--;
    }
    if(ca5 && ca5>ca3){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card5->GetPosition();
        Card5->SetPosition(wxPoint(pos.x,pos.y-50));
        deleteCard5->SetPosition(wxPoint(pos.x+200,pos.y-50));

        ca5--;
    }
    ca3=0;
    delete Card3;
    delete deleteCard3;
}

void MyPanel::DeleteCard4(wxCommandEvent &evt) {
    numberCard--;
    if(ca2 && ca2>ca4){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card2->GetPosition();
        Card2->SetPosition(wxPoint(pos.x,pos.y-50));


        deleteCard2->SetPosition(wxPoint(pos.x+200,pos.y-50));
        ca2--;
    }
    if(ca3 && ca3>ca4){
        struct pos{
            int x,y;
        };

        wxPoint pos=Card3->GetPosition();
        Card3->SetPosition(wxPoint(pos.x,pos.y-50));
        deleteCard3->SetPosition(wxPoint(pos.x+200,pos.y-50));

        ca3--;
    }
    if(ca1 && ca1>ca4){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card1->GetPosition();
        Card1->SetPosition(wxPoint(pos.x,pos.y-50));
        deleteCard1->SetPosition(wxPoint(pos.x+200,pos.y-50));

        ca1--;
    }
    if(ca5 && ca5>ca4){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card5->GetPosition();
        Card5->SetPosition(wxPoint(pos.x,pos.y-50));
        deleteCard5->SetPosition(wxPoint(pos.x+200,pos.y-50));

        ca5--;
    }
    ca4=0;
    delete Card4;
    delete deleteCard4;
}

void MyPanel::DeleteCard5(wxCommandEvent &evt) {
    numberCard--;
    if(ca2 && ca2>ca5){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card2->GetPosition();
        Card2->SetPosition(wxPoint(pos.x,pos.y-50));


        deleteCard2->SetPosition(wxPoint(pos.x+200,pos.y-50));
        ca2--;
    }
    if(ca3 && ca3>ca5){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card3->GetPosition();
        Card3->SetPosition(wxPoint(pos.x,pos.y-50));
        deleteCard3->SetPosition(wxPoint(pos.x+200,pos.y-50));

        ca3--;
    }
    if(ca4 && ca4>ca5){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card4->GetPosition();
        Card4->SetPosition(wxPoint(pos.x,pos.y-50));
        deleteCard4->SetPosition(wxPoint(pos.x+200,pos.y-50));

        ca4--;
    }
    if(ca1 && ca1>ca5){
        struct pos{
            int x,y;
        };
        wxPoint pos=Card1->GetPosition();
        Card1->SetPosition(wxPoint(pos.x,pos.y-50));
        deleteCard1->SetPosition(wxPoint(pos.x+200,pos.y-50));

        ca1--;
    }
    ca5=0;
    delete Card5;
    delete deleteCard5;
}
