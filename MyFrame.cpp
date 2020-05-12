//
// Created by myself on 3/28/20.
//

#include "MyFrame.h"

wxBEGIN_EVENT_TABLE(MyFrame,wxMDIParentFrame)
                EVT_MENU(10001,MyFrame::OnMenuNew)
                EVT_MENU(10002,MyFrame::OnMenuOpen)
                EVT_MENU(10003,MyFrame::OnMenuSave)
                EVT_MENU(10004,MyFrame::OnMenuExit)
wxEND_EVENT_TABLE()

MyFrame::MyFrame(): wxFrame(nullptr,wxID_ANY,"wxListMaker",wxPoint(50,50),wxSize(1410,615)) {
    m_MenuBar=new wxMenuBar();
    this->SetMenuBar(m_MenuBar);

    wxMenu *menuFile=new wxMenu();
    menuFile->Append(10001,"New");
    menuFile->Append(10002,"Open");
    menuFile->Append(10003,"Save");
    menuFile->Append(10004,"Exit");

    m_MenuBar->Append(menuFile,"File");


    topPanel = new wxPanel(this);
    topPanel->SetBackgroundColour(wxColor(60,60,110,60));

    bottomPanel=new wxPanel(topPanel,-1,wxDefaultPosition,wxDefaultSize);
    bottomPanel->SetBackgroundColour(wxColor(127,127,127,127));

    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(bottomPanel, 1, wxEXPAND | wxTOP, 100);
    topPanel->SetSizer(vbox);

    wxButton*Creator=new wxButton(topPanel,wxID_ANY,"Add List",wxPoint(10,35),wxSize(160,30));
    Creator->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListCreator,this);
    nameList= new wxTextCtrl(topPanel,wxID_ANY,wxEmptyString,wxPoint(13,10),wxSize(155,20));
}
//MENUBAR/////////////////////////////////////////
void MyFrame::OnMenuNew(wxCommandEvent &evt) {

}
void MyFrame::OnMenuOpen(wxCommandEvent &evt) {
    wxFileDialog dlg(this,"OpenFile","","",".spr Files (*.spr)|*.spr",wxFD_OPEN|wxFD_FILE_MUST_EXIST);

}
void MyFrame::OnMenuSave(wxCommandEvent &evt) {

}
void MyFrame::OnMenuExit(wxCommandEvent &evt) {
    Close();
    evt.Skip();
}
//END////////////////////////////////////////////

//PANELS/////////////////////////////////////////
void MyFrame::ListCreator(wxCommandEvent &evt) {
    if(!listPanel[0]){
        posList=10+(countList*350);
        listPanel[0]=new wxPanel(bottomPanel,wxID_ANY,wxPoint(posList,10),wxSize(340,445));
        Title[0]=new wxStaticText(listPanel[0],wxID_ANY,wxString(),wxPoint(5,2));
        Title[0]->SetLabel(nameList->GetValue());
        Deleter[0]=new wxButton(listPanel[0],wxID_ANY,"X",wxPoint(318,0),wxSize(25,20));
        Deleter[0]->SetForegroundColour(wxColor(255,0,0,0));
        Deleter[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListDelete1,this);
        countList++;
        frontPanel[0]=new wxPanel(listPanel[0],wxID_ANY,wxPoint(5,20),wxSize(330,420));
        frontPanel[0]->SetBackgroundColour(wxColor(60,60,110,60));
        newText[0]=new wxButton(frontPanel[0],wxID_ANY,"Add Card",wxPoint(5,5),wxSize(140,30));
        newText[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::OnButtonClicked1,this);
        txt[0]=new wxTextCtrl(frontPanel[0],wxID_ANY,"",wxPoint(5,35),wxSize(200,30));
        PassList();
    }else if(!listPanel[1]){
        posList=10+(countList*350);
        listPanel[1]=new wxPanel(bottomPanel,wxID_ANY,wxPoint(posList,10),wxSize(340,445));
        Title[1]=new wxStaticText(listPanel[1],wxID_ANY,wxString(),wxPoint(5,2));
        Title[1]->SetLabel(nameList->GetValue());
        Deleter[1]=new wxButton(listPanel[1],wxID_ANY,"X",wxPoint(318,0),wxSize(25,20));
        Deleter[1]->SetForegroundColour(wxColor(255,0,0,0));
        Deleter[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListDelete2,this);
        countList++;
        frontPanel[1]=new wxPanel(listPanel[1],wxID_ANY,wxPoint(5,20),wxSize(330,420));
        frontPanel[1]->SetBackgroundColour(wxColor(60,60,110,60));
        newText[1]=new wxButton(frontPanel[1],wxID_ANY,"Add Card",wxPoint(5,5),wxSize(140,30));
        newText[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::OnButtonClicked2,this);
        txt[1]=new wxTextCtrl(frontPanel[1],wxID_ANY,"",wxPoint(5,35),wxSize(200,30));
        PassList();
    }else if(!listPanel[2]){
        posList=10+(countList*350);
        listPanel[2]=new wxPanel(bottomPanel,wxID_ANY,wxPoint(posList,10),wxSize(340,445));
        Title[2]=new wxStaticText(listPanel[2],wxID_ANY,wxString(),wxPoint(5,2));
        Title[2]->SetLabel(nameList->GetValue());
        Deleter[2]=new wxButton(listPanel[2],wxID_ANY,"X",wxPoint(318,0),wxSize(25,20));
        Deleter[2]->SetForegroundColour(wxColor(255,0,0,0));
        Deleter[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListDelete3,this);
        countList++;
        frontPanel[2]=new wxPanel(listPanel[2],wxID_ANY,wxPoint(5,20),wxSize(330,420));
        frontPanel[2]->SetBackgroundColour(wxColor(60,60,110,60));
        newText[2]=new wxButton(frontPanel[2],wxID_ANY,"Add Card",wxPoint(5,5),wxSize(140,30));
        newText[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::OnButtonClicked3,this);
        txt[2]=new wxTextCtrl(frontPanel[2],wxID_ANY,"",wxPoint(5,35),wxSize(200,30));
        PassList();
    }else if(!listPanel[3]){
        posList=10+(countList*350);
        listPanel[3]=new wxPanel(bottomPanel,wxID_ANY,wxPoint(posList,10),wxSize(340,445));
        Title[3]=new wxStaticText(listPanel[3],wxID_ANY,wxString(),wxPoint(5,2));
        Title[3]->SetLabel(nameList->GetValue());
        Deleter[3]=new wxButton(listPanel[3],wxID_ANY,"X",wxPoint(318,0),wxSize(25,20));
        Deleter[3]->SetForegroundColour(wxColor(255,0,0,0));
        Deleter[3]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListDelete4,this);
        countList++;
        frontPanel[3]=new wxPanel(listPanel[3],wxID_ANY,wxPoint(5,20),wxSize(330,420));
        frontPanel[3]->SetBackgroundColour(wxColor(60,60,110,60));
        newText[3]=new wxButton(frontPanel[3],wxID_ANY,"Add Card",wxPoint(5,5),wxSize(140,30));
        newText[3]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::OnButtonClicked4,this);
        txt[3]=new wxTextCtrl(frontPanel[3],wxID_ANY,"",wxPoint(5,35),wxSize(200,30));
        PassList();
    }else {
        wxMessageDialog *dial = new wxMessageDialog(NULL,
                                                    wxT("Max number of lists reached"), wxT("Exclamation"),
                                                    wxOK | wxICON_EXCLAMATION);
        dial->ShowModal();
    }
}
void MyFrame::ListDelete1(wxCommandEvent &evt) {
    //Delete any card on the list
    for (int k=2;k<listPanel[0]->GetChildren()[2]->GetChildren().size();k++){
        if(listPanel[0]->GetChildren()[2]->GetChildren()[k]){
            for (int j=0;j<20;j++){
                if(Card[j]){
                    if(Card[j]==listPanel[0]->GetChildren()[2]->GetChildren()[k]){
                        delete Card[j];
                        Card[j]=nullptr;
                        k=k-1;
                        break;
                    }
                }
            }
        }
    }
    numCard[0]=0;
    //Delete the list
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=listPanel[0]->GetPosition();
    SetListPosition(panelPosition.x);
    delete listPanel[0];
    listPanel[0]=nullptr;
    PassList();
}
void MyFrame::ListDelete2(wxCommandEvent &evt) {
    //Delete any card on the list
    for (int k=2;k<listPanel[1]->GetChildren()[2]->GetChildren().size();k++){
        if(listPanel[1]->GetChildren()[2]->GetChildren()[k]){
            for (int j=0;j<20;j++){
                if(Card[j]){
                    if(Card[j]==listPanel[1]->GetChildren()[2]->GetChildren()[k]){
                        delete Card[j];
                        Card[j]=nullptr;
                        k=k-1;
                        break;
                    }
                }
            }
        }
    }
    numCard[1]=0;
    //Delete the list
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=listPanel[1]->GetPosition();
    SetListPosition(panelPosition.x);
    delete listPanel[1];
    listPanel[1]=nullptr;
    PassList();
}
void MyFrame::ListDelete3(wxCommandEvent &evt) {
    //Delete any card on the list
    for (int k=2;k<listPanel[2]->GetChildren()[2]->GetChildren().size();k++){
        if(listPanel[2]->GetChildren()[2]->GetChildren()[k]){
            for (int j=0;j<20;j++){
                if(Card[j]){
                    if(Card[j]==listPanel[2]->GetChildren()[2]->GetChildren()[k]){
                        delete Card[j];
                        Card[j]=nullptr;
                        k=k-1;
                        break;
                    }
                }
            }
        }
    }
    numCard[2]=0;
    //Delete the list
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=listPanel[2]->GetPosition();
    SetListPosition(panelPosition.x);
    delete listPanel[2];
    listPanel[2]=nullptr;
    PassList();
}
void MyFrame::ListDelete4(wxCommandEvent &evt) {
    //Delete any card on the list
    for (int k=2;k<listPanel[3]->GetChildren()[2]->GetChildren().size();k++){
        if(listPanel[3]->GetChildren()[2]->GetChildren()[k]){
            for (int j=0;j<20;j++){
                if(Card[j]){
                    if(Card[j]==listPanel[3]->GetChildren()[2]->GetChildren()[k]){
                        delete Card[j];
                        Card[j]=nullptr;
                        k=k-1;
                        break;
                    }
                }
            }
        }
    }
    numCard[3]=0;
    //Delete the list
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=listPanel[3]->GetPosition();
    SetListPosition(panelPosition.x);
    delete listPanel[3];
    listPanel[3]=nullptr;
    PassList();
}
void MyFrame::SetListPosition(int x) {
    int posx,posy;
    for(int i=0;i<4;i++){
        if(listPanel[i]){
            struct panelPosition{
                int x,y;
            };
            wxPoint panelPosition=listPanel[i]->GetPosition();
            posx=panelPosition.x;
            posy=panelPosition.y;
        }else continue;
        if(posx>x){
            listPanel[i]->SetPosition(wxPoint(posx-350,posy));
        }
    }
    countList--;
}
//END/////////////////////////////////////////
//CARDS///////////////////////////////////////
void MyFrame::OnButtonClicked1(wxCommandEvent &evt) {
    CreateCard(0);
}
void MyFrame::OnButtonClicked2(wxCommandEvent &evt) {
    CreateCard(1);
}
void MyFrame::OnButtonClicked3(wxCommandEvent &evt) {
    CreateCard(2);
}
void MyFrame::OnButtonClicked4(wxCommandEvent &evt) {
    CreateCard(3);
}

void MyFrame::CreateCard(int list) {
    if(list==0 && numCard[list]<5){
        if(!Card[0]){
            posCard=70+numCard[list]*70;
            Card[0]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[0]=new wxButton(Card[0],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard1,this);
            deleteCard[0]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[0]=new wxStaticText(Card[0],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[0]->SetLabel(txt[list]->GetValue());
            pointsToDo[0]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
            //Card[0]->numCard[list]=&numCard[list];
        }else if(!Card[1]){
            posCard=70+numCard[list]*70;
            Card[1]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[1]=new wxButton(Card[1],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard2,this);
            deleteCard[1]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[1]=new wxStaticText(Card[1],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[1]->SetLabel(txt[list]->GetValue());
            pointsToDo[1]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[2]){
            posCard=70+numCard[list]*70;
            Card[2]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[2]=new wxButton(Card[2],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard3,this);
            deleteCard[2]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[2]=new wxStaticText(Card[2],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[2]->SetLabel(txt[list]->GetValue());
            pointsToDo[2]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[3]){
            posCard=70+numCard[list]*70;
            Card[3]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[3]=new wxButton(Card[3],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[3]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard4,this);
            deleteCard[3]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[3]=new wxStaticText(Card[3],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[3]->SetLabel(txt[list]->GetValue());
            pointsToDo[3]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[4]){
            posCard=70+numCard[list]*70;
            Card[4]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[4]=new wxButton(Card[4],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[4]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard5,this);
            deleteCard[4]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[4]=new wxStaticText(Card[4],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[4]->SetLabel(txt[list]->GetValue());
            pointsToDo[4]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[5]){
            posCard=70+numCard[list]*70;
            Card[5]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[5]=new wxButton(Card[5],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[5]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard6,this);
            deleteCard[5]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[5]=new wxStaticText(Card[5],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[5]->SetLabel(txt[list]->GetValue());
            pointsToDo[5]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[6]){
            posCard=70+numCard[list]*70;
            Card[6]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[6]=new wxButton(Card[6],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[6]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard7,this);
            deleteCard[6]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[6]=new wxStaticText(Card[6],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[6]->SetLabel(txt[list]->GetValue());
            pointsToDo[6]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[7]){
            posCard=70+numCard[list]*70;
            Card[7]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[7]=new wxButton(Card[7],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[7]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard8,this);
            deleteCard[7]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[7]=new wxStaticText(Card[7],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[7]->SetLabel(txt[list]->GetValue());
            pointsToDo[7]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[8]){
            posCard=70+numCard[list]*70;
            Card[8]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[8]=new wxButton(Card[8],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[8]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard9,this);
            deleteCard[8]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[8]=new wxStaticText(Card[8],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[8]->SetLabel(txt[list]->GetValue());
            pointsToDo[8]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[9]){
            posCard=70+numCard[list]*70;
            Card[9]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[9]=new wxButton(Card[9],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[9]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard10,this);
            deleteCard[9]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[9]=new wxStaticText(Card[9],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[9]->SetLabel(txt[list]->GetValue());
            pointsToDo[9]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[10]){
            posCard=70+numCard[list]*70;
            Card[10]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[10]=new wxButton(Card[10],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[10]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard11,this);
            deleteCard[10]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[10]=new wxStaticText(Card[10],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[10]->SetLabel(txt[list]->GetValue());
            pointsToDo[10]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[11]){
            posCard=70+numCard[list]*70;
            Card[11]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[11]=new wxButton(Card[11],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[11]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard12,this);
            deleteCard[11]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[11]=new wxStaticText(Card[11],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[11]->SetLabel(txt[list]->GetValue());
            pointsToDo[11]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[12]){
            posCard=70+numCard[list]*70;
            Card[12]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[12]=new wxButton(Card[12],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[12]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard13,this);
            deleteCard[12]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[12]=new wxStaticText(Card[12],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[12]->SetLabel(txt[list]->GetValue());
            pointsToDo[12]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[13]){
            posCard=70+numCard[list]*70;
            Card[13]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[13]=new wxButton(Card[13],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[13]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard14,this);
            deleteCard[13]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[13]=new wxStaticText(Card[13],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[13]->SetLabel(txt[list]->GetValue());
            pointsToDo[13]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[14]){
            posCard=70+numCard[list]*70;
            Card[14]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[14]=new wxButton(Card[14],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[14]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard15,this);
            deleteCard[14]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[14]=new wxStaticText(Card[14],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[14]->SetLabel(txt[list]->GetValue());
            pointsToDo[14]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[15]){
            posCard=70+numCard[list]*70;
            Card[15]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[15]=new wxButton(Card[15],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[15]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard16,this);
            deleteCard[15]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[15]=new wxStaticText(Card[15],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[15]->SetLabel(txt[list]->GetValue());
            pointsToDo[15]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[16]){
            posCard=70+numCard[list]*70;
            Card[16]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[16]=new wxButton(Card[16],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[16]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard17,this);
            deleteCard[16]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[16]=new wxStaticText(Card[16],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[16]->SetLabel(txt[list]->GetValue());
            pointsToDo[16]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[17]){
            posCard=70+numCard[list]*70;
            Card[17]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[17]=new wxButton(Card[17],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[17]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard18,this);
            deleteCard[17]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[17]=new wxStaticText(Card[17],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[17]->SetLabel(txt[list]->GetValue());
            pointsToDo[17]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[18]){
            posCard=70+numCard[list]*70;
            Card[18]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[18]=new wxButton(Card[18],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[18]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard19,this);
            deleteCard[18]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[18]=new wxStaticText(Card[18],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[18]->SetLabel(txt[list]->GetValue());
            pointsToDo[18]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[19]){
            posCard=70+numCard[list]*70;
            Card[19]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[19]=new wxButton(Card[19],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[19]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard20,this);
            deleteCard[19]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[19]=new wxStaticText(Card[19],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[19]->SetLabel(txt[list]->GetValue());
            pointsToDo[19]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }
    }else if(list==1 && numCard[list]<5){
        if(!Card[0]){
            posCard=70+numCard[list]*70;
            Card[0]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[0]=new wxButton(Card[0],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard1,this);
            deleteCard[0]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[0]=new wxStaticText(Card[0],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[0]->SetLabel(txt[list]->GetValue());
            pointsToDo[0]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[1]){
            posCard=70+numCard[list]*70;
            Card[1]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[1]=new wxButton(Card[1],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard2,this);
            deleteCard[1]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[1]=new wxStaticText(Card[1],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[1]->SetLabel(txt[list]->GetValue());
            pointsToDo[1]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[2]){
            posCard=70+numCard[list]*70;
            Card[2]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[2]=new wxButton(Card[2],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard3,this);
            deleteCard[2]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[2]=new wxStaticText(Card[2],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[2]->SetLabel(txt[list]->GetValue());
            pointsToDo[2]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[3]){
            posCard=70+numCard[list]*70;
            Card[3]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[3]=new wxButton(Card[3],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[3]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard4,this);
            deleteCard[3]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[3]=new wxStaticText(Card[3],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[3]->SetLabel(txt[list]->GetValue());
            pointsToDo[3]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[4]){
            posCard=70+numCard[list]*70;
            Card[4]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[4]=new wxButton(Card[4],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[4]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard5,this);
            deleteCard[4]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[4]=new wxStaticText(Card[4],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[4]->SetLabel(txt[list]->GetValue());
            pointsToDo[4]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[5]){
            posCard=70+numCard[list]*70;
            Card[5]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[5]=new wxButton(Card[5],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[5]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard6,this);
            deleteCard[5]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[5]=new wxStaticText(Card[5],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[5]->SetLabel(txt[list]->GetValue());
            pointsToDo[5]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[6]){
            posCard=70+numCard[list]*70;
            Card[6]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[6]=new wxButton(Card[6],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[6]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard7,this);
            deleteCard[6]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[6]=new wxStaticText(Card[6],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[6]->SetLabel(txt[list]->GetValue());
            pointsToDo[6]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[7]){
            posCard=70+numCard[list]*70;
            Card[7]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[7]=new wxButton(Card[7],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[7]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard8,this);
            deleteCard[7]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[7]=new wxStaticText(Card[7],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[7]->SetLabel(txt[list]->GetValue());
            pointsToDo[7]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[8]){
            posCard=70+numCard[list]*70;
            Card[8]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[8]=new wxButton(Card[8],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[8]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard9,this);
            deleteCard[8]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[8]=new wxStaticText(Card[8],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[8]->SetLabel(txt[list]->GetValue());
            pointsToDo[8]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[9]){
            posCard=70+numCard[list]*70;
            Card[9]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[9]=new wxButton(Card[9],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[9]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard10,this);
            deleteCard[9]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[9]=new wxStaticText(Card[9],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[9]->SetLabel(txt[list]->GetValue());
            pointsToDo[9]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[10]){
            posCard=70+numCard[list]*70;
            Card[10]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[10]=new wxButton(Card[10],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[10]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard11,this);
            deleteCard[10]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[10]=new wxStaticText(Card[10],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[10]->SetLabel(txt[list]->GetValue());
            pointsToDo[10]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[11]){
            posCard=70+numCard[list]*70;
            Card[11]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[11]=new wxButton(Card[11],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[11]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard12,this);
            deleteCard[11]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[11]=new wxStaticText(Card[11],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[11]->SetLabel(txt[list]->GetValue());
            pointsToDo[11]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[12]){
            posCard=70+numCard[list]*70;
            Card[12]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[12]=new wxButton(Card[12],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[12]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard13,this);
            deleteCard[12]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[12]=new wxStaticText(Card[12],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[12]->SetLabel(txt[list]->GetValue());
            pointsToDo[12]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[13]){
            posCard=70+numCard[list]*70;
            Card[13]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[13]=new wxButton(Card[13],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[13]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard14,this);
            deleteCard[13]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[13]=new wxStaticText(Card[13],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[13]->SetLabel(txt[list]->GetValue());
            pointsToDo[13]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[14]){
            posCard=70+numCard[list]*70;
            Card[14]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[14]=new wxButton(Card[14],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[14]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard15,this);
            deleteCard[14]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[14]=new wxStaticText(Card[14],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[14]->SetLabel(txt[list]->GetValue());
            pointsToDo[14]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[15]){
            posCard=70+numCard[list]*70;
            Card[15]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[15]=new wxButton(Card[15],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[15]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard16,this);
            deleteCard[15]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[15]=new wxStaticText(Card[15],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[15]->SetLabel(txt[list]->GetValue());
            pointsToDo[15]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[16]){
            posCard=70+numCard[list]*70;
            Card[16]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[16]=new wxButton(Card[16],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[16]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard17,this);
            deleteCard[16]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[16]=new wxStaticText(Card[16],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[16]->SetLabel(txt[list]->GetValue());
            pointsToDo[16]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[17]){
            posCard=70+numCard[list]*70;
            Card[17]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[17]=new wxButton(Card[17],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[17]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard18,this);
            deleteCard[17]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[17]=new wxStaticText(Card[17],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[17]->SetLabel(txt[list]->GetValue());
            pointsToDo[17]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[18]){
            posCard=70+numCard[list]*70;
            Card[18]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[18]=new wxButton(Card[18],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[18]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard19,this);
            deleteCard[18]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[18]=new wxStaticText(Card[18],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[18]->SetLabel(txt[list]->GetValue());
            pointsToDo[18]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[19]){
            posCard=70+numCard[list]*70;
            Card[19]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[19]=new wxButton(Card[19],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[19]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard20,this);
            deleteCard[19]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[19]=new wxStaticText(Card[19],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[19]->SetLabel(txt[list]->GetValue());
            pointsToDo[19]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }
    }else if(list==2 && numCard[list]<5){
        if(!Card[0]){
            posCard=70+numCard[list]*70;
            Card[0]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[0]=new wxButton(Card[0],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard1,this);
            deleteCard[0]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[0]=new wxStaticText(Card[0],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[0]->SetLabel(txt[list]->GetValue());
            pointsToDo[0]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[1]){
            posCard=70+numCard[list]*70;
            Card[1]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[1]=new wxButton(Card[1],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard2,this);
            deleteCard[1]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[1]=new wxStaticText(Card[1],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[1]->SetLabel(txt[list]->GetValue());
            pointsToDo[1]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[2]){
            posCard=70+numCard[list]*70;
            Card[2]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[2]=new wxButton(Card[2],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard3,this);
            deleteCard[2]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[2]=new wxStaticText(Card[2],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[2]->SetLabel(txt[list]->GetValue());
            pointsToDo[2]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[3]){
            posCard=70+numCard[list]*70;
            Card[3]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[3]=new wxButton(Card[3],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[3]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard4,this);
            deleteCard[3]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[3]=new wxStaticText(Card[3],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[3]->SetLabel(txt[list]->GetValue());
            pointsToDo[3]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[4]){
            posCard=70+numCard[list]*70;
            Card[4]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[4]=new wxButton(Card[4],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[4]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard5,this);
            deleteCard[4]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[4]=new wxStaticText(Card[4],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[4]->SetLabel(txt[list]->GetValue());
            pointsToDo[4]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[5]){
            posCard=70+numCard[list]*70;
            Card[5]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[5]=new wxButton(Card[5],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[5]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard6,this);
            deleteCard[5]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[5]=new wxStaticText(Card[5],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[5]->SetLabel(txt[list]->GetValue());
            pointsToDo[5]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[6]){
            posCard=70+numCard[list]*70;
            Card[6]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[6]=new wxButton(Card[6],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[6]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard7,this);
            deleteCard[6]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[6]=new wxStaticText(Card[6],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[6]->SetLabel(txt[list]->GetValue());
            pointsToDo[6]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[7]){
            posCard=70+numCard[list]*70;
            Card[7]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[7]=new wxButton(Card[7],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[7]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard8,this);
            deleteCard[7]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[7]=new wxStaticText(Card[7],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[7]->SetLabel(txt[list]->GetValue());
            pointsToDo[7]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[8]){
            posCard=70+numCard[list]*70;
            Card[8]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[8]=new wxButton(Card[8],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[8]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard9,this);
            deleteCard[8]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[8]=new wxStaticText(Card[8],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[8]->SetLabel(txt[list]->GetValue());
            pointsToDo[8]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[9]){
            posCard=70+numCard[list]*70;
            Card[9]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[9]=new wxButton(Card[9],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[9]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard10,this);
            deleteCard[9]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[9]=new wxStaticText(Card[9],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[9]->SetLabel(txt[list]->GetValue());
            pointsToDo[9]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[10]){
            posCard=70+numCard[list]*70;
            Card[10]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[10]=new wxButton(Card[10],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[10]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard11,this);
            deleteCard[10]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[10]=new wxStaticText(Card[10],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[10]->SetLabel(txt[list]->GetValue());
            pointsToDo[10]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[11]){
            posCard=70+numCard[list]*70;
            Card[11]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[11]=new wxButton(Card[11],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[11]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard12,this);
            deleteCard[11]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[11]=new wxStaticText(Card[11],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[11]->SetLabel(txt[list]->GetValue());
            pointsToDo[11]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[12]){
            posCard=70+numCard[list]*70;
            Card[12]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[12]=new wxButton(Card[12],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[12]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard13,this);
            deleteCard[12]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[12]=new wxStaticText(Card[12],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[12]->SetLabel(txt[list]->GetValue());
            pointsToDo[12]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[13]){
            posCard=70+numCard[list]*70;
            Card[13]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[13]=new wxButton(Card[13],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[13]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard14,this);
            deleteCard[13]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[13]=new wxStaticText(Card[13],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[13]->SetLabel(txt[list]->GetValue());
            pointsToDo[13]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[14]){
            posCard=70+numCard[list]*70;
            Card[14]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[14]=new wxButton(Card[14],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[14]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard15,this);
            deleteCard[14]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[14]=new wxStaticText(Card[14],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[14]->SetLabel(txt[list]->GetValue());
            pointsToDo[14]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[15]){
            posCard=70+numCard[list]*70;
            Card[15]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[15]=new wxButton(Card[15],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[15]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard16,this);
            deleteCard[15]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[15]=new wxStaticText(Card[15],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[15]->SetLabel(txt[list]->GetValue());
            pointsToDo[15]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[16]){
            posCard=70+numCard[list]*70;
            Card[16]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[16]=new wxButton(Card[16],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[16]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard17,this);
            deleteCard[16]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[16]=new wxStaticText(Card[16],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[16]->SetLabel(txt[list]->GetValue());
            pointsToDo[16]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[17]){
            posCard=70+numCard[list]*70;
            Card[17]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[17]=new wxButton(Card[17],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[17]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard18,this);
            deleteCard[17]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[17]=new wxStaticText(Card[17],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[17]->SetLabel(txt[list]->GetValue());
            pointsToDo[17]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[18]){
            posCard=70+numCard[list]*70;
            Card[18]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[18]=new wxButton(Card[18],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[18]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard19,this);
            deleteCard[18]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[18]=new wxStaticText(Card[18],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[18]->SetLabel(txt[list]->GetValue());
            pointsToDo[18]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[19]){
            posCard=70+numCard[list]*70;
            Card[19]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[19]=new wxButton(Card[19],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[19]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard20,this);
            deleteCard[19]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[19]=new wxStaticText(Card[19],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[19]->SetLabel(txt[list]->GetValue());
            pointsToDo[19]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }
    }else if(list==3 && numCard[list]<5){
        if(!Card[0]){
            posCard=70+numCard[list]*70;
            Card[0]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[0]=new wxButton(Card[0],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard1,this);
            deleteCard[0]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[0]=new wxStaticText(Card[0],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[0]->SetLabel(txt[list]->GetValue());
            pointsToDo[0]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[1]){
            posCard=70+numCard[list]*70;
            Card[1]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[1]=new wxButton(Card[1],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard2,this);
            deleteCard[1]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[1]=new wxStaticText(Card[1],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[1]->SetLabel(txt[list]->GetValue());
            pointsToDo[1]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[2]){
            posCard=70+numCard[list]*70;
            Card[2]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[2]=new wxButton(Card[2],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard3,this);
            deleteCard[2]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[2]=new wxStaticText(Card[2],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[2]->SetLabel(txt[list]->GetValue());
            pointsToDo[2]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[3]){
            posCard=70+numCard[list]*70;
            Card[3]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[3]=new wxButton(Card[3],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[3]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard4,this);
            deleteCard[3]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[3]=new wxStaticText(Card[3],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[3]->SetLabel(txt[list]->GetValue());
            pointsToDo[3]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[4]){
            posCard=70+numCard[list]*70;
            Card[4]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[4]=new wxButton(Card[4],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[4]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard5,this);
            deleteCard[4]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[4]=new wxStaticText(Card[4],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[4]->SetLabel(txt[list]->GetValue());
            pointsToDo[4]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[5]){
            posCard=70+numCard[list]*70;
            Card[5]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[5]=new wxButton(Card[5],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[5]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard6,this);
            deleteCard[5]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[5]=new wxStaticText(Card[5],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[5]->SetLabel(txt[list]->GetValue());
            pointsToDo[5]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[6]){
            posCard=70+numCard[list]*70;
            Card[6]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[6]=new wxButton(Card[6],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[6]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard7,this);
            deleteCard[6]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[6]=new wxStaticText(Card[6],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[6]->SetLabel(txt[list]->GetValue());
            pointsToDo[6]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[7]){
            posCard=70+numCard[list]*70;
            Card[7]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[7]=new wxButton(Card[7],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[7]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard8,this);
            deleteCard[7]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[7]=new wxStaticText(Card[7],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[7]->SetLabel(txt[list]->GetValue());
            pointsToDo[7]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[8]){
            posCard=70+numCard[list]*70;
            Card[8]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[8]=new wxButton(Card[8],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[8]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard9,this);
            deleteCard[8]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[8]=new wxStaticText(Card[8],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[8]->SetLabel(txt[list]->GetValue());
            pointsToDo[8]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[9]){
            posCard=70+numCard[list]*70;
            Card[9]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[9]=new wxButton(Card[9],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[9]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard10,this);
            deleteCard[9]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[9]=new wxStaticText(Card[9],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[9]->SetLabel(txt[list]->GetValue());
            pointsToDo[9]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[10]){
            posCard=70+numCard[list]*70;
            Card[10]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[10]=new wxButton(Card[10],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[10]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard11,this);
            deleteCard[10]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[10]=new wxStaticText(Card[10],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[10]->SetLabel(txt[list]->GetValue());
            pointsToDo[10]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[11]){
            posCard=70+numCard[list]*70;
            Card[11]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[11]=new wxButton(Card[11],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[11]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard12,this);
            deleteCard[11]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[11]=new wxStaticText(Card[11],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[11]->SetLabel(txt[list]->GetValue());
            pointsToDo[11]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[12]){
            posCard=70+numCard[list]*70;
            Card[12]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[12]=new wxButton(Card[12],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[12]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard13,this);
            deleteCard[12]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[12]=new wxStaticText(Card[12],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[12]->SetLabel(txt[list]->GetValue());
            pointsToDo[12]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[13]){
            posCard=70+numCard[list]*70;
            Card[13]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[13]=new wxButton(Card[13],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[13]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard14,this);
            deleteCard[13]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[13]=new wxStaticText(Card[13],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[13]->SetLabel(txt[list]->GetValue());
            pointsToDo[13]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[14]){
            posCard=70+numCard[list]*70;
            Card[14]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[14]=new wxButton(Card[14],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[14]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard15,this);
            deleteCard[14]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[14]=new wxStaticText(Card[14],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[14]->SetLabel(txt[list]->GetValue());
            pointsToDo[14]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[15]){
            posCard=70+numCard[list]*70;
            Card[15]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[15]=new wxButton(Card[15],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[15]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard16,this);
            deleteCard[15]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[15]=new wxStaticText(Card[15],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[15]->SetLabel(txt[list]->GetValue());
            pointsToDo[15]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[16]){
            posCard=70+numCard[list]*70;
            Card[16]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[16]=new wxButton(Card[16],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[16]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard17,this);
            deleteCard[16]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[16]=new wxStaticText(Card[16],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[16]->SetLabel(txt[list]->GetValue());
            pointsToDo[16]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[17]){
            posCard=70+numCard[list]*70;
            Card[17]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[17]=new wxButton(Card[17],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[17]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard18,this);
            deleteCard[17]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[17]=new wxStaticText(Card[17],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[17]->SetLabel(txt[list]->GetValue());
            pointsToDo[17]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[18]){
            posCard=70+numCard[list]*70;
            Card[18]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[18]=new wxButton(Card[18],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[18]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard19,this);
            deleteCard[18]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[18]=new wxStaticText(Card[18],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[18]->SetLabel(txt[list]->GetValue());
            pointsToDo[18]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[19]){
            posCard=70+numCard[list]*70;
            Card[19]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[19]=new wxButton(Card[19],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[19]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard20,this);
            deleteCard[19]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[19]=new wxStaticText(Card[19],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[19]->SetLabel(txt[list]->GetValue());
            pointsToDo[19]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }
    }else{
        wxMessageDialog *dial = new wxMessageDialog(NULL,
                                                    wxT("Max number of cards reached"), wxT("Exclamation"),
                                                    wxOK | wxICON_EXCLAMATION);
        dial->ShowModal();
    }
    PassList();
}

void MyFrame::DeleteCard1(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[0]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[0]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);

    delete Card[0];
    Card[0]=nullptr;
}

void MyFrame::DeleteCard2(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[1]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[1]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[1];
    Card[1]=nullptr;
}

void MyFrame::DeleteCard3(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[2]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[2]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[2];
    Card[2]=nullptr;
}

void MyFrame::DeleteCard4(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[3]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[3]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[3];
    Card[3]=nullptr;
}

void MyFrame::DeleteCard5(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[4]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[4]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[4];
    Card[4]=nullptr;
}

void MyFrame::DeleteCard6(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[5]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[5]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[5];
    Card[5]=nullptr;
}

void MyFrame::DeleteCard7(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[6]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[6]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[6];
    Card[6]=nullptr;
}

void MyFrame::DeleteCard8(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[7]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[7]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[7];
    Card[7]=nullptr;
}

void MyFrame::DeleteCard9(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[8]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[8]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[8];
    Card[8]=nullptr;
}

void MyFrame::DeleteCard10(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[9]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[9]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[9];
    Card[9]=nullptr;
}

void MyFrame::DeleteCard11(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[10]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[10]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[10];
    Card[10]=nullptr;
}

void MyFrame::DeleteCard12(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[11]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[11]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[11];
    Card[11]=nullptr;
}

void MyFrame::DeleteCard13(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[12]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[12]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[12];
    Card[12]=nullptr;
}

void MyFrame::DeleteCard14(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[13]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[13]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[13];
    Card[13]=nullptr;
}

void MyFrame::DeleteCard15(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[14]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[14]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[14];
    Card[14]=nullptr;
}

void MyFrame::DeleteCard16(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[15]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[15]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[15];
    Card[15]=nullptr;
}

void MyFrame::DeleteCard17(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[16]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[16]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[16];
    Card[16]=nullptr;
}

void MyFrame::DeleteCard18(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[17]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[17]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[17];
    Card[17]=nullptr;
}

void MyFrame::DeleteCard19(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[18]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[18]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[18];
    Card[18]=nullptr;
}

void MyFrame::DeleteCard20(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[19]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[19]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[19];
    Card[19]=nullptr;
}

void MyFrame::MoveCards(wxPanel *aList,int posCard,int *numCardList) {//aList è il frontPanel di porvenienza //posCard è la y del card //numCardList è il numero di cards
    struct panelPosition{
        int x,y;
    };
    for(int i=2;i<aList->GetChildren()[2]->GetChildren().size();i++){
        wxPoint panelPosition=aList->GetChildren()[2]->GetChildren()[i]->GetPosition();
        if(posCard<panelPosition.y)
            aList->GetChildren()[2]->GetChildren()[i]->SetPosition(wxPoint(panelPosition.x,panelPosition.y-70));//Move some Cards
    }
    *numCardList=*numCardList-1;// Decrement the numbers of cards for this list
}

void MyFrame::PassList() {
    for(int i=0;i<20;i++){
        if(Card[i])
            for(int j=0;j<4;j++)
                if(listPanel[j]){
                    Card[i]->anyPanel[j]=listPanel[j];
                    Card[i]->anyTitle[j]=Title[j]->GetLabelText();
                    Card[i]->numCard[j]=&numCard[j];
                }
    }
}