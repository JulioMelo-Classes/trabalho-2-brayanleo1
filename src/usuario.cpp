#include "usuario.h"

using namespace std;

Usuario::Usuario(){}

void Usuario::setId(int id_){
    id = id_;
}

int Usuario::getId(){
    return id;
}

void Usuario::setNome(string nome_){
    nome = nome_;
}

string Usuario::getNome(){
    return nome;
}
void Usuario::setEmail(string email_){
    email = email_;
}

string Usuario::getEmail(){
    return email;
}

void Usuario::setSenha(string senha_){
    senha = senha_;
}

string Usuario::getSenha(){
    return senha;
}