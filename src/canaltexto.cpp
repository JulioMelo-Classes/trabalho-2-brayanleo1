#include "canaltexto.h"

using namespace std;

CanalTexto::CanalTexto(){}

void CanalTexto::setNome(string nome_){
    nome = nome_;
}

string CanalTexto::getNome(){
    return nome;
}