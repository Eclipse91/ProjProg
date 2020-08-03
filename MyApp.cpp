//
// Created by myself on 6/8/20.
//

#include "MyApp.h"
#include "View.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    Model* model=new Model;
    Controller* controller=new Controller(model);
    auto frame = new View(model, controller);
    frame->Show();
    return true;
}