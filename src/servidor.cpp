#include "servidor.h"

using namespace std;

Servidor::Servidor(){}

void Servidor::setId(int id_){
    usuarioDonoId = id_;
}

int Servidor::getId(){
    return usuarioDonoId;
}

void Servidor::setNome(string nome_){
    nome = nome_;
}

string Servidor::getNome(){
    return nome;
}

void Servidor::setDescricao(string descricao_){
    descricao = descricao_;
}

string Servidor::getDescricao(){
    return descricao;
}

void Servidor::setCodigo(string codigo_){
    codigoConvite = codigo_;
}

string Servidor::getCodigo(){
    return codigoConvite;
}

void Servidor::addUser(int id_){
    participantesIDs.push_back(id_);
}

bool Servidor::findUser(int id_){
    bool existe = false;
    for(auto it = participantesIDs.begin(); it != participantesIDs.end(); it++){
        if(*it == id_) {
            existe = true;
        }
    }
    return existe;
}

void Servidor::removeUser(int id_) {
    for(auto it = participantesIDs.begin(); it != participantesIDs.end(); it++){
        if(*it == id_) {
            participantesIDs.erase(it);
            break;
        }
    }
}

string Servidor::printUsers(vector<Usuario> usuarios_){
    string usuarios;
    for(auto it = participantesIDs.begin(); it != participantesIDs.end(); it++) {
        for(auto it2 = usuarios_.begin(); it2 != usuarios_.end(); it2++) {
            if(*it == it2->getId()){
                usuarios.append(it2->getNome());
                auto itAux = it;
                itAux++;
                if(itAux != participantesIDs.end()){
                    usuarios.append("\n");
                }
            }
        }
    }
    return usuarios;
}

string Servidor::printChannels(){
    string channels;
    channels.append("#canais de texto \n");
    for(auto it = canaisTexto.begin(); it != canaisTexto.end(); it++) {
        channels.append(it->getNome());
        channels.append("\n");
    }
    return channels;
}

bool Servidor::findChannel(string nome_){
    bool existe = false;
    for(auto it = canaisTexto.begin(); it != canaisTexto.end(); it++){
        if(it->getNome() == nome_) {
            existe = true;
        }
    }
    return existe;
}

void Servidor::addChannel(string nome_){
    CanalTexto canal;
    canal.setNome(nome_);
    canaisTexto.push_back(canal);
}

vector<CanalTexto>::iterator Servidor::getThatChannel(string nome_){
    auto channel = canaisTexto.begin();
    for(auto it = canaisTexto.begin(); it != canaisTexto.end(); it++){
        if(it->getNome() == nome_) {
            channel = it;
        }
    }
    return channel;
}

string Servidor::printMsgsFromChannel(string nome_, vector<Usuario> usuarios_){
    string msgs;
    auto channelIt = getThatChannel(nome_);
    auto pos = channelIt->getMsgIts();
    for(auto it = pos.first; it != pos.second; it++){
        auto id = it->getEnv();
        string n;
        for(auto it2 = usuarios_.begin(); it2 != usuarios_.end(); it2++){
            if(id == it2->getId()){
                n.append(it2->getNome());
                it2 = usuarios_.end();
                it2--;
            }
        }
        msgs.append(n);
        msgs.append(it->printMsg());
        auto itAux = it;
        itAux++;
        if(itAux != pos.second) {
            msgs.append("\n");
        }
    }
    return msgs;
}