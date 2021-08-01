#include "mensagem.h"

using namespace std;

Mensagem::Mensagem(){}

void Mensagem::setDH(string dataHora_){
    dataHora = dataHora_;
}

void Mensagem::setEnv(int id){
    enviadaPor = id;
}

int Mensagem::getEnv(){
    return enviadaPor;
}

void Mensagem::setContent(string conteudo_){
    conteudo = conteudo_;
}

string Mensagem::printMsg(){
    string msg;
    msg.append(dataHora);
    msg.append(conteudo);
    return msg;
}