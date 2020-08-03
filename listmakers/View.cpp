//
// Created by myself on 6/8/20.
//

#include "View.h"
wxBEGIN_EVENT_TABLE(View,wxMDIParentFrame)
                EVT_MENU(10001,View::OnMenuNew)
                EVT_MENU(10002,View::OnMenuOpen)
                EVT_MENU(10003,View::OnMenuSave)
                EVT_MENU(10004,View::OnMenuExit)
wxEND_EVENT_TABLE()

View::View(Model* m, Controller* c): wxFrame(nullptr,wxID_ANY,"wxListMaker",wxPoint(50,50),wxSize(1410,615)) {
    model = m;
    model->addObserver(this);
    controller = c;
    m_MenuBar=new wxMenuBar();
    this->SetMenuBar(m_MenuBar);

    menuFile=new wxMenu();
    menuFile->Append(10001,"New");
    menuFile->Append(10002,"Open");
    menuFile->Append(10003,"Save");
    menuFile->Append(10004,"Exit");

    m_MenuBar->Append(menuFile,"File");

    topPanel = new wxPanel(this);
    topPanel->SetBackgroundColour(wxColor(60,60,110,60));

    bottomPanel=new wxPanel(topPanel,-1,wxDefaultPosition,wxDefaultSize);
    bottomPanel->SetBackgroundColour(wxColor(127,127,127,127));

    vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(bottomPanel, 1, wxEXPAND | wxTOP, 100);
    topPanel->SetSizer(vbox);

    Creator=new wxButton(topPanel,wxID_ANY,"Add List",wxPoint(10,35),wxSize(160,30));
    Creator->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&View::ListCreator,this);
    nameList= new wxTextCtrl(topPanel,wxID_ANY,wxEmptyString,wxPoint(13,10),wxSize(155,20));
}

void View::ListCreator(wxCommandEvent &evt) {
    if(nameList->GetValue().empty()){
        wxMessageDialog *dial = new wxMessageDialog(NULL,
                                                    wxT("Write the name of the list"), wxT("Exclamation"),
                                                    wxOK | wxICON_EXCLAMATION);
        dial->ShowModal();
    }else{
        int exist=0;
        for(const auto& name:*model->getList()){
            if(std::string(nameList->GetValue())==name){
                exist++;
            }
        }
        if(exist){
            wxMessageDialog *dial = new wxMessageDialog(NULL,
                                                        wxT("This list already exist"), wxT("Exclamation"),
                                                        wxOK | wxICON_EXCLAMATION);
            dial->ShowModal();
        }else{
            controller->AddList(std::string(nameList->GetValue()));
        }
    }
}

void View::DisplayList(std::list<string> *List) {
    std::list<string>* Card=model->getCard();
    MyPanel*Panel[List->size()];
    int countList=0,posList;
    for(auto name : *List){//for(std::list<string>*iterator name=List.begin();name!=List.end();name++)
        posList=10+(countList*350);
        Panel[countList]=new MyPanel(model,controller,bottomPanel,wxID_ANY,wxPoint(posList,10),wxSize(340,445));
        Panel[countList]->listName->SetLabel(name);

        DisplayCard(Panel[countList],Card,List);

        if(!countList){
            wxPanel*CoverPanel=new wxPanel(Panel[0],wxID_ANY,wxPoint(272,0),wxSize(25,20));
        }
        countList++;
        if(List->size()==(countList)){
            wxPanel*CoverPanel=new wxPanel(Panel[countList-1],wxID_ANY,wxPoint(295,0),wxSize(25,20));
        }
    }
}
void View::DisplayCard(MyPanel *Panel, std::list<string> *Card,std::list<string>* List) {
    int numberOfCards=0;//TODO set number of sublist searching in the CardFrame
    std::string nameOfPanel;
    for(auto name:*Card){
        if(name==Panel->listName->GetLabel()){
            numberOfCards++;
            nameOfPanel=name;
        }
    }
    int numberOfList=0,positionOfList=0;
    for(auto name:*List){
        ++numberOfList;
        if(name==Panel->listName->GetLabel()){
            positionOfList=numberOfList;
        }
    }
    std::list<string>* CardFrame=model->getCardFrame();
    std::list<string>::iterator name1;
    MyCard*Cards[numberOfCards];
    int vero=0,countCard=0,posCard;
    for(auto name:*Card){//se Card[0]=Panel->listName->GetLabel() allora crea card in quel panel
        if(vero){
            posCard=70+countCard*70;
            Cards[countCard]=new MyCard(List,Card,CardFrame,model,controller,Panel->frontPanel,wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            Cards[countCard]->thingToDo->SetLabel(name);
            if(!countCard){
                auto*CoverPanel=new wxPanel(Cards[countCard],wxID_ANY,wxPoint(254,0),wxSize(25,25));
            }
            if(countCard+1==numberOfCards){
                auto*CoverPanel=new wxPanel(Cards[countCard],wxID_ANY,wxPoint(233,0),wxSize(25,25));
            }
            if(positionOfList==1){
                auto*CoverPanel=new wxPanel(Cards[countCard],wxID_ANY,wxPoint(191,0),wxSize(25,25));
            }
            if(positionOfList==numberOfList){
                auto*CoverPanel=new wxPanel(Cards[countCard],wxID_ANY,wxPoint(212,0),wxSize(25,25));

            }


                DisplayCardFeature(Cards[countCard],name,nameOfPanel);
            countCard++;
        }
        vero=0;
        if(name==Panel->listName->GetLabel()){
            vero=1;
        }
    }
}

void View::DisplayCardFeature(MyCard *PanelCard, std::string Card, std::string List) {
    std::list<string>* CardFrame=model->getCardFrame();
    std::list<string>::iterator name1;

    for(std::list<string>::iterator name=CardFrame->begin();name!=CardFrame->end(); name++){
        if(*name==List){
            std::advance(name,1);
            if(*name==Card){
                //Sublist
                std::advance(name,1);
                name1=name;
                std::advance(name,std::stoi(*name1)*2);
                //Members
                std::advance(name,1);//not sure
                name1=name;
                std::advance(name,std::stoi(*name1));
                std::advance(name,1);//not sure
                if(*name!="NOHIGHPRIORITY"){
                    PanelCard->highPriority=new wxButton(PanelCard,-1,"High priority",wxPoint(0,0),wxSize(100,25));
                }
                std::advance(name,1);//not sure
                if(*name!="NODEADLINE"){
                    PanelCard->DeadL=new wxButton(PanelCard,-1,*name,wxPoint(100,0),wxSize(94,25));
                }
            }
        }
    }

}

void View::DeleteList() {
    for(int i=0;i<bottomPanel->GetChildren().size();i++){
        delete bottomPanel->GetChildren()[i];
        --i;
    }
}

void View::OnMenuNew(wxCommandEvent &evt) {
    ClearLists();
    evt.Skip();
}
void View::ClearLists() {
    controller->ClearCardFrame();
    controller->ClearCard();
    controller->ClearList();
}
void View::OnMenuOpen(wxCommandEvent &evt) {
    wxFileDialog dlg(this,"OpenFile","","",".txt Files (*.txt)|*.txt",wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if(dlg.ShowModal()==wxID_OK){
        Open(dlg.GetPath());
    }
    evt.Skip();
}
bool View::Open(wxString fileName) {
    ClearLists();
    std::list<string>* List=model->getList();
    std::list<string>* Card=model->getCard();
    std::list<string>* CardFrame=model->getCardFrame();

    std::ifstream infile;
    infile.open(fileName);
    std::string Temp;
    int count=0;

    while (std::getline(infile, Temp)) {
        if(Temp=="#LiSt1#"){count=1;continue;}
        if(Temp=="#LiSt2#"){count=2;continue;}
        if(Temp=="#LiSt3#"){count=3;continue;}

        if(count==1){
            List->push_back(Temp);
            continue;
        }
        if(count==2){
            Card->push_back(Temp);
            continue;
        }
        if(count==3){
            CardFrame->push_back(Temp);
            continue;
        }
    }
    DisplayList(List);
    return false;
}

void View::OnMenuSave(wxCommandEvent &evt) {
    wxFileDialog dlg(this,"SaveFile","","",".txt Files (*.txt)|*.txt",wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if(dlg.ShowModal()==wxID_OK){
        Save(dlg.GetPath());
    }
    evt.Skip();
}
bool View::Save(wxString fileName) {
    std::ofstream outfile;
    outfile.open(fileName);

    outfile<<"#LiSt1#"<<std::endl;
    std::list<string>* List=model->getList();
    for(auto name:*List){
        outfile<<name<<std::endl;
    }
    outfile<<"#LiSt2#"<<std::endl;
    std::list<string>* Card=model->getCard();
    for(auto name:*Card){
        outfile<<name<<std::endl;
    }
    outfile<<"#LiSt3#"<<std::endl;
    std::list<string>* CardFrame=model->getCardFrame();
    for(auto name:*CardFrame){
        outfile<<name<<std::endl;
    }
    return false;
}

void View::OnMenuExit(wxCommandEvent &evt) {
    Close();
    evt.Skip();
}




