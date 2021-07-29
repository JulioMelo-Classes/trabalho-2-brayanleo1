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
        //Usuário está logado?
        for(auto it = usuariosLogados.begin(); it != usuariosLogados.end(); it++) {
          if(it->first == id) {
            return "Usuário "+ u.getEmail() + " já logado";
          }
        }

        std::pair<std::string, std::string> nulidade;
        nulidade.first = "";
        nulidade.second = "";
        std::pair<int, std::pair<std::string, std::string>> logado;
        logado.first = id;
        logado.second = nulidade;
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
  for(auto it = usuariosLogados.begin(); it != usuariosLogados.end(); it++) {
    if(it->first == id) {
      usuariosLogados.erase(it);
      return "Desconectando usuário " + usuarios[id].getEmail();
    }
  }

  return "Não está conectado";
}

string Sistema::create_server(int id, const string nome) {
  Servidor s;
  s.setId(id);
  s.setNome(nome);
  s.setCodigo("");

  //Existe alguém logado?
  int x = usuariosLogados.size();

  if(x > 0) {
    //Usuário está logado?
    bool logado = false;
    for(auto it = usuariosLogados.begin(); it != usuariosLogados.end(); it++){
      if(it->first == id){ //Tá logado
      logado = true;
        //Já existe servidor com esse nome?
        for(auto it2 = servidores.begin(); it2 != servidores.end(); it2++){
          if(it2->getNome() == nome) {
            return "Servidor com esse nome já existe";
          }
        }

      } 
      auto itAux = it;
      itAux++;
      if(itAux == usuariosLogados.end() && logado == false){ //Não tá logado pois testou todos
        return "Usuário não logado 2";
      }
    }
  } else {
    return "Usuário não logado";
  }

  servidores.push_back(s);
  return "Servidor criado";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
  //Existe alguém logado?
  int x = usuariosLogados.size();

  if(x > 0) {
    //Usuário está logado?
    bool logado = false;
    for(auto it = usuariosLogados.begin(); it != usuariosLogados.end(); it++){
      if(it->first == id){ //Tá logado
        logado = true;
        //Tem algum servidor com esse nome?
        bool existe = false;
        for(auto it2 = servidores.begin(); it2 != servidores.end(); it2++) {
          if(it2->getNome() == nome){ //Nome existe
            logado = true;
            //Você é o dono desse servidor?
            if(it2->getId() == id){
              it2->setDescricao(descricao);
              return "Descrição do servidor " + nome + " modificada!";
            }
          }
          auto it2Aux = it2;
          it2Aux++;
          if(it2Aux == servidores.end() && existe == false) {
            return "Servidor " + nome + " não existe";
          }
        }

      }
      auto itAux = it;
      itAux++;
      if(itAux == usuariosLogados.end() && logado == false){ //Não tá logado pois testou todos
        return "Usuário não logado 2";
      }
    }
  } else {
    return "Usuário não logado";
  }

  return "Você não pode alterar a descrição de um servidor que não foi criado por você";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
  //Existe alguém logado?
  int x = usuariosLogados.size();

  if(x > 0) {
    //Usuário está logado?
    bool logado = false;
    for(auto it = usuariosLogados.begin(); it != usuariosLogados.end(); it++){
      if(it->first == id){ //Tá logado
        logado = true;
        //Tem algum servidor com esse nome?
        bool existe = false;
        for(auto it2 = servidores.begin(); it2 != servidores.end(); it2++) {
          if(it2->getNome() == nome){ //Nome existe
            existe = true;
            //Você é o dono desse servidor?
            if(it2->getId() == id){
              it2->setCodigo(codigo);
              if(codigo == "") {
                return "Código de convite do servidor " + nome + " removido!";
              } else {
                return "Código de convite do servidor " + nome + " modificado!";
              }
              
            }
          }
          auto it2Aux = it2;
          it2Aux++;
          if(it2Aux == servidores.end() && existe == false) {
            return "Servidor " + nome + " não existe";
          }
        }

      } 
      auto itAux = it;
      itAux++;
      if(itAux == usuariosLogados.end() && logado == false){ //Não tá logado pois testou todos
        return "Usuário não logado";
      }
    }
  } else {
    return "Usuário não logado";
  }

  return "Você não pode alterar o código de um servidor que não foi criado por você";
}

string Sistema::list_servers(int id) {
  //Esse usuário está logado?
  for(auto it = usuariosLogados.begin(); it != usuariosLogados.end(); it++) {
    if(it->first == id) {
      string listaServers;
      if(servidores.size() == 0) {
        return "Não existem servidores criados no momento";
      }
      for(auto it2 = servidores.begin(); it2 != servidores.end(); it2++) {
        listaServers.append(it2->getNome());
        listaServers.append("\n");
      }
      return listaServers;
    }
  }

  return "Usuário não logado";
}

string Sistema::remove_server(int id, const string nome) {
  //Existe alguém logado?
  int x = usuariosLogados.size();

  if(x > 0) {
    //Usuário está logado?
    bool logado = false;
    for(auto it = usuariosLogados.begin(); it != usuariosLogados.end(); it++){
      if(it->first == id){ //Tá logado
        logado = true;
        //Tem algum servidor com esse nome?
        bool existe = false;
        for(auto it2 = servidores.begin(); it2 != servidores.end(); it2++) {
          if(it2->getNome() == nome){ //Nome existe
          existe = true;
            //Você é o dono desse servidor?
            if(it2->getId() == id){
              servidores.erase(it2);
              //Desassociando users nesse servidor
              for(auto it3 = usuariosLogados.begin(); it3 != usuariosLogados.end(); it3++) {
                if(it3->second.first == nome) {
                  it3->second.first = "";
                  it3->second.second = "";
                }
              }
              return "Servidor " + nome + " removido";
            }
          }
          auto it2Aux = it2;
          it2Aux++;
          if(it2Aux == servidores.end() && existe == false) {
            return "Servidor " + nome + " não encontrado";
          }
        }

      }
      auto itAux = it;
      itAux++;
      if(itAux == usuariosLogados.end() && logado == false){ //Não tá logado pois testou todos
        return "Usuário não logado";
      }
    }
  } else {
    return "Usuário não logado";
  }

  return "Você não é o dono do servidor " + nome;
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
  //Existe alguém logado?
  int x = usuariosLogados.size();

  if(x > 0) {
    //Usuário está logado?
    bool logado = false;
    for(auto it = usuariosLogados.begin(); it != usuariosLogados.end(); it++){
      if(it->first == id){ //Tá logado
        logado = true;
        //Existe servidor com esse nome?
        bool existe = false;
        for(auto it2 = servidores.begin(); it2 != servidores.end(); it2++){
          if(it2->getNome() == nome) {//Servidor existe
            existe = true;
            //Já está dentro do servidor?
            if(it2->findUser(it->first) == false) {//Não está dentro
              //É dono do servidor?
              if(it2->getId() == it->first) {//É dono
                pair<string,string> status;
                status.first = nome; //Associa a visualização do usuário aquele server
                status.second = ""; //Coloca o usuário para não ver nenhum canal
                it->second = status; //Atualiza as informações
                it2->addUser(it->first); //Adiciona o id do usuário a lista de participantes
                return "Entrou no servidor com sucesso";
              } else {//Não é dono
                //Código de convite necessário?
                if(it2->getCodigo() != "") {//É necessário
                  //Há código de convite válido?
                  if(codigo == ""){
                    return "Servidor requer código de convite";
                  } else if(codigo == it2->getCodigo()) {
                    pair<string,string> status;
                    status.first = nome; //Associa a visualização do usuário aquele server
                    status.second = ""; //Coloca o usuário para não ver nenhum canal
                    it->second = status; //Atualiza as informações
                    it2->addUser(it->first); //Adiciona o id do usuário a lista de participantes
                    return "Entrou no servidor com sucesso";
                  }
                } else {//Não é necessário
                    pair<string,string> status;
                    status.first = nome; //Associa a visualização do usuário aquele server
                    status.second = ""; //Coloca o usuário para não ver nenhum canal
                    it->second = status; //Atualiza as informações
                    it2->addUser(it->first); //Adiciona o id do usuário a lista de participantes
                    return "Entrou no servidor com sucesso";
                }
              }
            } else{//Está dentro
              //Está visualizando aquele servidor?
              pair<string,string> status;
              if(it->second.first != nome){//Não
                status.first = nome; //Associa a visualização do usuário aquele server
                status.second = ""; //Coloca o usuário para não ver nenhum canal
                it->second = status; //Atualiza as informações
              }
              return "";
            }
          } 
          auto it2Aux = it2;
          it2Aux++;
          if(it2Aux == servidores.end() && existe == false) {//Servidor não existe
            return "Servidor " + nome + " não encontrado";
          }
        }

      } 
      auto itAux = it;
      itAux++;
      if(itAux == usuariosLogados.end() && logado == false){ //Não tá logado pois testou todos
        return "Usuário não logado 2";
      }
    }
  } else {
    return "Usuário não logado";
  }

  return "Código de convite inválido";
}

string Sistema::leave_server(int id, const string nome) {
  //Existe alguém logado?
  int x = usuariosLogados.size();

  if(x > 0) {
    //Usuário está logado?
    bool logado = false;
    for(auto it = usuariosLogados.begin(); it != usuariosLogados.end(); it++){
      if(it->first == id){ //Tá logado
        logado = true;
        //Usuário pertence a algum servidor?
        bool pertence = false;
        for(auto itAux = servidores.begin(); itAux != servidores.end(); itAux++){
          if(itAux->findUser(it->first) == true){
            pertence = true;
          }
        }
        if(pertence == true) {//Pertence
          //Existe servidor com esse nome?
          bool existe = false;
          for(auto it2 = servidores.begin(); it2 != servidores.end(); it2++){
            if(it2->getNome() == nome) {//Existe
              //O usuário está logado nesse servidor?
              if(it2->findUser(it->first) == true) {//Está logado
                //Está visualizando esse servidor?
                if(it->second.first == nome){
                    it->second.first = "";
                    it->second.second = "";
                }
                it2->removeUser(it->first);
                return "Saindo do servidor " + nome;
              } else {//Não está logado
                return "Você não está logado no servidor " + nome;
              }
            } 
            auto it2Aux = it2;
            it2Aux++;
            if(it2Aux == servidores.end() && existe == false) {//Servidor não existe
              return "Servidor " + nome + " não encontrado";
            }
          }
        } else {//Não pertence
          return "Você não está em qualquer servidor";
        }

      } 
      auto itAux = it;
      itAux++;
      if(itAux == usuariosLogados.end() && logado == false){ //Não tá logado pois testou todos
        return "Usuário não logado 2";
      }
    }
  } else {
    return "Usuário não logado";
  }

  return "Você não está em qualquer servidor";
}

string Sistema::list_participants(int id) {
  //Existe alguém logado?
  int x = usuariosLogados.size();

  if(x > 0) {
    //Usuário está logado?
    bool logado = false;
    for(auto it = usuariosLogados.begin(); it != usuariosLogados.end(); it++){
      if(it->first == id){ //Tá logado
      logado = true;
      string nome = it->second.first;
        //Existe tal servidor?
        for(auto it2 = servidores.begin(); it2 != servidores.end(); it2++){
          if(it2->getNome() == nome) {
            return it2->printUsers(usuarios);
          }
        }

      } 
      auto itAux = it;
      itAux++;
      if(itAux == usuariosLogados.end() && logado == false){ //Não tá logado pois testou todos
        return "Usuário não logado 2";
      }
    }
  } else {
    return "Usuário não logado";
  }

  return "Usuário não está visualizando nenhum servidor";
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
