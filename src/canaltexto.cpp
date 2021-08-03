#include "canaltexto.h"

#include <ctime>
#include <string>

using namespace std;

CanalTexto::CanalTexto(){}

void CanalTexto::setNome(string nome_){
    nome = nome_;
}

string CanalTexto::getNome(){
    return nome;
}

void CanalTexto::addMsg(int id, string conteudo){
    Mensagem m;
    m.setEnv(id);
    m.setContent(conteudo);
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"<%d/%m/%Y - %H:%M>: ",timeinfo);
    std::string dh(buffer);
    m.setDH(dh);

    mensagens.push_back(m);
}

pair<vector<Mensagem>::iterator, vector<Mensagem>::iterator> CanalTexto::getMsgIts(){
    pair<vector<Mensagem>::iterator, vector<Mensagem>::iterator> p;
    p.first = mensagens.begin();
    p.second = mensagens.end();
    return p;
}