//
// Created by myself on 6/7/20.
//

#ifndef LISTMAKER04_CONTROLLER_H
#define LISTMAKER04_CONTROLLER_H

#include "Model.h"

class Controller {
public:
    Controller(Model*m): model(m){}

    void AddList(std::string l){
        List=model->getList();
        List->push_back(l);
        model->notify();
    }
    void DeleteList(std::string l){
        List=model->getList();
        List->remove(l);
        model->notify();
    }
    void ClearList(){
        List=model->getList();
        List->clear();
        model->notify();
    }
    void AddCard(std::string l, std::string c){
        Card=model->getCard();
        Card->push_back(l);
        Card->push_back(c);
        model->notify();
    }
    void DeleteCard(std::string c){
        Card=model->getCard();
        std::list<string>::iterator it1;
        for(std::list<string>::iterator it=Card->begin();it!=Card->end(); it++){
            if(*it==c){
                Card->remove(c);
                Card->erase(it1);
                model->notify();
                break;
            }
            it1=it;
        }
    }
    void ClearCard(){
        Card=model->getCard();
        Card->clear();
        model->notify();
    }
    void AddHighPriority(std::string l, std::string c, std::string HP){
        CardFrame=model->getCardFrame();
        std::list<string>::iterator it1;
        int counter=0, didit=0;
        for(std::list<string>::iterator it=CardFrame->begin();it!=CardFrame->end(); it++){
            if(*it==l){
                counter++;
                std::advance(it,1);
            }else continue;
            if(counter){
                if(*it==c){
                    std::advance(it,1);
                    it1=it;
                    std::advance(it,std::stoi(*it1)*2);
                    std::advance(it,1);
                    it1=it;
                    std::advance(it,std::stoi(*it1));
                    std::advance(it,1);
                    CardFrame->insert(it,HP);
                    it1=it;
                    CardFrame->erase(it1);
                    didit++;
                    break;
                }
            }else counter--;

        }
        if(!didit){
            CardFrame->push_back(l);
            CardFrame->push_back(c);
            CardFrame->push_back("0");
            CardFrame->push_back("0");//Members
            CardFrame->push_back(HP);
            CardFrame->push_back("NODEADLINE");

        }
    }
    void AddDeadLine(std::string l, std::string c, std::string DL){
        CardFrame=model->getCardFrame();
        for(std::list<string>::iterator it=CardFrame->begin();it!=CardFrame->end(); it++) {
            std::cout<<*it<<std::endl;
        }
        std::list<string>::iterator it1;
        int counter=0, didit=0;
        for(std::list<string>::iterator it=CardFrame->begin();it!=CardFrame->end(); it++){
            if(*it==l){
                counter++;
                std::advance(it,1);
            }else continue;
            if(counter){
                if(*it==c){
                    //Sublist
                    std::advance(it,1);
                    it1=it;
                    std::advance(it,std::stoi(*it1)*2);
                    //Members
                    std::advance(it,1);
                    it1=it;
                    std::advance(it,std::stoi(*it1));
                    std::advance(it,2);
                    CardFrame->insert(it,DL);
                    it1=it;
                    CardFrame->erase(it1);
                    didit++;
                    break;
                }
            }else counter--;
        }
        if(!didit){
            CardFrame->push_back(l);
            CardFrame->push_back(c);
            CardFrame->push_back("0");//Sublists
            CardFrame->push_back("0");//Members
            CardFrame->push_back("NOHIGHPRIORITY");
            CardFrame->push_back(DL);
        }
    }
    void AddSublist(std::string l, std::string c, std::string sub,int num){
        CardFrame=model->getCardFrame();
        std::list<string>::iterator it1;
        int counter=0, didit=0;
        for(std::list<string>::iterator it=CardFrame->begin();it!=CardFrame->end(); it++){
            if(*it==l){
                std::advance(it,1);
                if(*it==c){
                    std::advance(it,1);
                    it1=it;
                    std::advance(it,std::stoi(*it)*2+1);
                    CardFrame->insert(it1,std::to_string(num));
                    CardFrame->erase(it1);
                    CardFrame->insert(it,sub);
                    CardFrame->insert(it,"0");
                    didit++;
                }else continue;
            }else continue;
        }
        if(!didit){
            CardFrame->push_back(l);
            CardFrame->push_back(c);
            //Sublists
            CardFrame->push_back(std::to_string(num));//Sublists
            CardFrame->push_back(sub);
            CardFrame->push_back("0");
            //Members
            CardFrame->push_back("0");
            CardFrame->push_back("NOHIGHPRIORITY");
            CardFrame->push_back("NODEADLINE");

        }
    }

    void AddSublistChecker(std::string l, std::string c,std::string s, int boolean){
        CardFrame=model->getCardFrame();
        std::list<string>::iterator it1;
        int counter=0, didit=0;
        for(std::list<string>::iterator it=CardFrame->begin();it!=CardFrame->end(); it++){
            if(*it==l){
                std::advance(it,1);
                if(*it==c){
                    std::advance(it,1);
                    int indRep=std::stoi(*it)*2;
                    for(int i=0;i<indRep;i++){
                        if(*it==s){
                            std::advance(it,1);
                            it1=it;
                            CardFrame->insert(it,std::to_string(boolean));
                            CardFrame->erase(it1);
                            break;
                        }else
                            std::advance(it,1);
                    }
                    break;
                }
            }
        }
    }
    void DeleteSublist(std::string l, std::string c, std::string s){
        CardFrame=model->getCardFrame();
        std::list<string>::iterator it1;
        int counter=0;
        for(std::list<string>::iterator it=CardFrame->begin();it!=CardFrame->end(); it++){
            if(*it==l){
                std::advance(it,1);
                if(*it==c){
                    std::advance(it,1);
                    int indRep=std::stoi(*it)*2;
                    for(int i=0;i<indRep;i++){
                        if(*it==s){
                            it1=it;
                            std::advance(it,1);
                            CardFrame->erase(it1);
                            CardFrame->erase(it);
                            break;
                        }else
                            std::advance(it,1);
                    }
                    break;
                }
            }
        }
    }
    void MoveCardRight(std::string l, std::string c){
        Card=model->getCard();
        CardFrame=model->getCardFrame();
        std::list<string>::iterator it1;
        for(std::list<string>::iterator it=Card->begin();it!=Card->end(); it++){
            if(c==*it){
                *it1=l;
                Card->push_back(*it1);
                Card->push_back(*it);
                Card->erase(it1);
                Card->erase(it);
                break;
            }
            it1=it;
        }
        for(std::list<string>::iterator it=CardFrame->begin();it!=CardFrame->end(); it++){
            if(c==*it){
                *it1=l;
                CardFrame->insert(it1,l);
                CardFrame->insert(it,c);
                CardFrame->erase(it1);
                CardFrame->erase(it);
                break;
            }
            it1=it;
        }
        model->notify();
    }
    void MoveCardLeft(std::string l, std::string c){
        Card=model->getCard();
        CardFrame=model->getCardFrame();
        std::list<string>::iterator it1;
        for(std::list<string>::iterator it=Card->begin();it!=Card->end(); it++){
            if(c==*it){
                *it1=l;
                Card->push_back(*it1);
                Card->push_back(*it);
                Card->erase(it1);
                Card->erase(it);
                break;
            }
            it1=it;
        }
        for(std::list<string>::iterator it=CardFrame->begin();it!=CardFrame->end(); it++){
            if(c==*it){
                *it1=l;
                CardFrame->insert(it1,l);
                CardFrame->insert(it,c);
                CardFrame->erase(it1);
                CardFrame->erase(it);
                break;
            }
            it1=it;
        }
        model->notify();
    }
    void MoveCardDown(std::string l, std::string c){
        Card=model->getCard();
        std::list<string>::iterator it1;
        int counter=0;
        for(std::list<string>::iterator it=Card->begin();it!=Card->end(); it++){
            if(c==*it){
                it1=it;
                counter++;
            }else if(counter==0) continue;
            if(counter==2){
                std::swap(*it,*it1);
                break;
            }
            if(*it==l){
                counter++;
            }
        }
        model->notify();
    }
    void MoveCardUp(std::string l, std::string c){
        Card=model->getCard();
        std::list<string>::iterator it1;
        int counter=0;
        for(std::list<string>::iterator it=Card->begin();it!=Card->end(); it++){
            if(c==*it){
                std::swap(*it1,*it);
                break;
            }
            if(counter==1){
                it1=it;
                counter=0;
                continue;
            }
            if(*it==l){
                counter++;
                continue;
            }
        }
        model->notify();
    }
    void MoveListLeft(std::string l){
        List=model->getList();
        std::list<string>::iterator it1;
        int counter=0;
        for(std::list<string>::iterator it=List->begin();it!=List->end(); it++){
            if(*it==l && counter>0){
                std::swap(*it,*it1);
                break;
            }
            it1=it;
            counter++;
        }
        model->notify();
    }
    void MoveListRight(std::string l){
        List=model->getList();
        std::list<string>::iterator it1;
        int counter=0, i=0;
        for(std::list<string>::iterator it=List->begin();it!=List->end(); it++){
            if(counter==1 && i<List->size()){
                std::swap(*it1,*it);
                break;
            }
            if(*it==l){
                it1=it;
                counter++;
            }
            i++;
        }
        model->notify();
    }
    void ClearCardFrame(){
        CardFrame=model->getCardFrame();
        CardFrame->clear();
        model->notify();
    }
private:
    Model* model;
    std::list<string>* List;
    std::list<string>* Card;
    std::list<string>* CardFrame;
};
#endif //LISTMAKER04_CONTROLLER_H
