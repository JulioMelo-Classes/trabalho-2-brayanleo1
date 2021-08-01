#include "canaltexto.h"

#include "time.h"

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
    string dh;
    dh.append("<");
    dh.append(__DATE__);
    dh.append(" - ");
    dh.append(__TIME__);
    dh.append(">");
    m.setDH(dh);

    mensagens.push_back(m);
}

pair<vector<Mensagem>::iterator, vector<Mensagem>::iterator> CanalTexto::getMsgIts(){
    pair<vector<Mensagem>::iterator, vector<Mensagem>::iterator> p;
    p.first = mensagens.begin();
    p.second = mensagens.end();
    return p;
}