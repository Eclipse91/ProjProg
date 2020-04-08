//
// Created by myself on 3/4/20.
//

#include "MyFrame.h"

wxBEGIN_EVENT_TABLE(MyFrame,wxFrame)
wxEND_EVENT_TABLE()

int numberList=0;
int Pan1=0,Pan2=0,Pan3=0,Pan4=0;

MyFrame::MyFrame(): wxFrame(nullptr,wxID_ANY,"wxAPP",wxPoint(50,50),wxSize(1300,600))
{
    topPanel = new wxPanel(this);
    topPanel->SetBackgroundColour(wxColor(0,100,0,0));

    bottomPanel=new wxPanel(topPanel,-1,wxDefaultPosition,wxSize(300,300));
    bottomPanel->SetBackgroundColour(wxColor(127,127,127,127));

    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(bottomPanel, 1, wxEXPAND | wxTOP, 100);
    topPanel->SetSizer(vbox);

    wxButton*Creator=new wxButton(topPanel,wxID_ANY,"Add List",wxPoint(10,35),wxSize(160,30));
    Creator->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListCreator,this);
    nameList= new wxTextCtrl(topPanel,wxID_ANY,wxEmptyString,wxPoint(13,10),wxSize(155,20));


}

void MyFrame::ListCreator(wxCommandEvent &evt) {
    if(!Pan1){
        int x=10,y=10;
        x=x+(numberList)*310;
        listPanel1=new MyPanel(bottomPanel,wxID_ANY,wxPoint(x,y),wxSize(300,400));
        listPanel1->SetBackgroundColour(wxColor(0,100,0,0));
        listPanel1->panelOne=listPanel1;

        Title1=new wxStaticText(listPanel1,wxID_ANY,wxString(),wxPoint(10,10));
        Title1->SetLabel(nameList->GetValue());
        Title1->SetBackgroundColour(wxColor(0,0,0,0));
        Deleter1=new wxButton(listPanel1,wxID_ANY,"Delete List",wxPoint(150,30),wxSize(140,30));
        Deleter1->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListDelete1,this);
        Pan1=1+numberList;
        std::cout<<"Created Pan1"<<std::endl;
    } else if(!Pan2){
        int x=10,y=10;
        x=x+(numberList)*310;
        listPanel2=new MyPanel(bottomPanel,wxID_ANY,wxPoint(x,y),wxSize(300,400));
        listPanel2->SetBackgroundColour(wxColor(0,100,0,0));
        listPanel2->panelTwo=listPanel2;

        Title2=new wxStaticText(listPanel2,wxID_ANY,wxString(),wxPoint(10,10));
        Title2->SetLabel(nameList->GetValue());
        Deleter2=new wxButton(listPanel2,wxID_ANY,"Delete List",wxPoint(150,30),wxSize(140,30));
        Deleter2->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListDelete2,this);
        Pan2=1+numberList;
        std::cout<<"Created Pan2"<<std::endl;
    }else if(!Pan3){
        int x=10,y=10;
        x=x+(numberList)*310;
        listPanel3=new MyPanel(bottomPanel,wxID_ANY,wxPoint(x,y),wxSize(300,400));
        listPanel3->SetBackgroundColour(wxColor(0,100,0,0));
        Title3=new wxStaticText(listPanel3,wxID_ANY,wxString(),wxPoint(10,10));
        Title3->SetLabel(nameList->GetValue());
        Deleter3=new wxButton(listPanel3,wxID_ANY,"Delete List",wxPoint(150,30),wxSize(140,30));
        Deleter3->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListDelete3,this);
        Pan3=1+numberList;
        std::cout<<"Created Pan3"<<std::endl;
    }else if(!Pan4){
        int x=10,y=10;
        x=x+(numberList)*310;
        listPanel4=new MyPanel(bottomPanel,wxID_ANY,wxPoint(x,y),wxSize(300,400));
        listPanel4->SetBackgroundColour(wxColor(0,100,0,0));
        Title4=new wxStaticText(listPanel4,wxID_ANY,wxString(),wxPoint(10,10));
        Title4->SetLabel(nameList->GetValue());
        Deleter4=new wxButton(listPanel4,wxID_ANY,"Delete List",wxPoint(150,30),wxSize(140,30));
        Deleter4->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListDelete4,this);
        Pan4=1+numberList;
        std::cout<<"Created Pan4"<<std::endl;

    }else{
        wxMessageDialog *dial = new wxMessageDialog(NULL,
                                                    wxT("Max number of lists reached"), wxT("Exclamation"),
                                                    wxOK | wxICON_EXCLAMATION);
        dial->ShowModal();
        numberList--;
    }
    numberList= numberList + 1;
}
void MyFrame::ListDelete1(wxCommandEvent &evt) {
    numberList=numberList-1;
    if(Pan2 && Pan2>Pan1){
        struct pos{
            int x,y;
        };
        wxPoint pos=listPanel2->GetPosition();
        listPanel2->SetPosition(wxPoint(pos.x-310,pos.y));
        Pan2=Pan2-1;
    }
    if(Pan3 && Pan3>Pan1){
        struct pos{
            int x,y;
        };
        wxPoint pos=listPanel3->GetPosition();
        listPanel3->SetPosition(wxPoint(pos.x-310,pos.y));
        Pan3=Pan3-1;
    }
    if(Pan4 && Pan4>Pan1){
        struct pos{
            int x,y;
        };
        wxPoint pos=listPanel4->GetPosition();
        listPanel4->SetPosition(wxPoint(pos.x-310,pos.y));
        Pan4=Pan4-1;
    }
    Pan1=0;
    delete listPanel1;
}

void MyFrame::ListDelete2(wxCommandEvent &evt) {
    numberList=numberList-1;
    if(Pan1 && Pan1>Pan2){
        struct pos{
            int x,y;
        };
        wxPoint pos=listPanel1->GetPosition();
        listPanel1->SetPosition(wxPoint(pos.x-310,pos.y));
        Pan1=Pan1-1;
    }
    if(Pan3 && Pan3>Pan2){
        struct pos{
            int x,y;
        };
        wxPoint pos=listPanel3->GetPosition();
        listPanel3->SetPosition(wxPoint(pos.x-310,pos.y));
        Pan3=Pan3-1;
    }
    if(Pan4 && Pan4>Pan2){
        struct pos{
            int x,y;
        };
        wxPoint pos=listPanel4->GetPosition();
        listPanel4->SetPosition(wxPoint(pos.x-310,pos.y));
        Pan4=Pan4-1;
    }
    Pan2=0;
    delete listPanel2;
}

void MyFrame::ListDelete3(wxCommandEvent &evt) {
    numberList=numberList-1;
    if(Pan2 && Pan2>Pan3){
        struct pos{
            int x,y;
        };
        wxPoint pos=listPanel2->GetPosition();
        listPanel2->SetPosition(wxPoint(pos.x-310,pos.y));
        Pan2=Pan2-1;
    }
    if(Pan1 && Pan1>Pan3){
        struct pos{
            int x,y;
        };
        wxPoint pos=listPanel1->GetPosition();
        listPanel1->SetPosition(wxPoint(pos.x-310,pos.y));
        Pan1=Pan1-1;
    }
    if(Pan4 && Pan4>Pan3){
        struct pos{
            int x,y;
        };
        wxPoint pos=listPanel4->GetPosition();
        listPanel4->SetPosition(wxPoint(pos.x-310,pos.y));
        Pan4=Pan4-1;
    }
    Pan3=0;
    delete listPanel3;
}

void MyFrame::ListDelete4(wxCommandEvent &evt) {
    numberList=numberList-1;
    if(Pan2 && Pan2>Pan4){
        struct pos{
            int x,y;
        };
        wxPoint pos=listPanel2->GetPosition();
        listPanel2->SetPosition(wxPoint(pos.x-310,pos.y));
        Pan2=Pan2-1;
    }
    if(Pan3 && Pan3>Pan4){
        struct pos{
            int x,y;
        };
        wxPoint pos=listPanel3->GetPosition();
        listPanel3->SetPosition(wxPoint(pos.x-310,pos.y));
        Pan3=Pan3-1;
    }
    if(Pan1 && Pan1>Pan4){
        struct pos{
            int x,y;
        };
        wxPoint pos=listPanel1->GetPosition();
        listPanel1->SetPosition(wxPoint(pos.x-310,pos.y));
        Pan1=Pan1-1;
    }
    Pan4=0;
    delete listPanel4;
}
