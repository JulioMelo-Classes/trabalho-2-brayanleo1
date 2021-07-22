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