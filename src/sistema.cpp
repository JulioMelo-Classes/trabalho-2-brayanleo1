#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {
  Usuario u;
  u.setId(usuarios.size());
  u.setEmail(email);
  u.setSenha(senha);
  u.setNome(nome);

  //Já existe alguém assim?
  for(auto it = usuarios.begin(); it != usuarios.end(); it++) {
    if(u.getEmail() == it->getEmail()) {
      return "Email já cadastrado!";
    } else if(u.getNome() == it->getNome()) {
      return "Nome de usuário já existe!";
    }
  }
  
  usuarios.push_back(u);
  return "Usuário criado";
}

string Sistema::login(const string email, const string senha) {
  Usuario u;
  u.setEmail(email);
  u.setSenha(senha);

  //Existe esse usuário com esse email e essa senha?
  int id = 0;
  for(auto it = usuarios.begin(); it != usuarios.end(); it++) {
    if(u.getEmail() == it->getEmail()) {
      if(u.getSenha() == it->getSenha()) {
        std::pair<std::string, std::string> nulidade;
        nulidade.first = "\0";
        nulidade.second = "\0";
        std::pair<int, std::pair<std::string, std::string>> logado;
        usuariosLogados.insert(logado);
        return "Logado como "+u.getEmail();
      } else {
        return "Senha ou usuário inválidos!"; //Como só pode ter uma conta por email...
      }
    }
    id++; 
  }

  return "Senha ou usuário inválidos!";
}

string Sistema::disconnect(int id) {
  return "disconnect NÃO IMPLEMENTADO";
}

string Sistema::create_server(int id, const string nome) {
  return "create_server NÃO IMPLEMENTADO";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
  return "set_server_desc NÃO IMPLEMENTADO";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
  return "set_server_invite_code NÃO IMPLEMENTADO";
}

string Sistema::list_servers(int id) {
  return "list_servers NÃO IMPLEMENTADO";
}

string Sistema::remove_server(int id, const string nome) {
  return "remove_server NÃO IMPLEMENTADO";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
  return "enter_server NÃO IMPLEMENTADO";
}

string Sistema::leave_server(int id, const string nome) {
  return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants(int id) {
  return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels(int id) {
  return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(int id, const string nome) {
  return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(int id, const string nome) {
  return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel(int id) {
  return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(int id, const string mensagem) {
  return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages(int id) {
  return "list_messages NÃO IMPLEMENTADO";
}




/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
