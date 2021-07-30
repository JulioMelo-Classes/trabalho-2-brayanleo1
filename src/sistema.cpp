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

pair<bool, std::map< int, std::pair<std::string, std::string> >::iterator> Sistema::is_user_logged (int id) {
  pair<bool, std::map< int, std::pair<std::string, std::string> >::iterator> par;
  par.first = false;
  for(auto it = usuariosLogados.begin(); it != usuariosLogados.end(); it++){
    if(it->first == id){ //Tá logado
    par.first = true; //Tá logado
    par.second = it; //Nessa posição
    it = usuariosLogados.end(); 
    it--; //Para finalizar o for
    }
  }

  return par;
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
        auto user = is_user_logged(id);
        if(user.first) {//Se estiver logado
          return "Usuário " + u.getEmail() + " já logado";
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
  auto user = is_user_logged(id);
  if(user.first) {//Se estiver logado
    usuariosLogados.erase(user.second);
    return "Desconectando usuário " + usuarios[id].getEmail();
  }

  return "Não está conectado";
}

std::pair<bool, std::vector<Servidor>::iterator> Sistema::this_server_exists(string nome){
  std::pair<bool, std::vector<Servidor>::iterator> par;
  par.first = false;

  for(auto it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == nome) { //Servidor existe
      par.first = true; //Servidor existe
      par.second = it; //Nessa posição
      it = servidores.end(); 
      it--; //Para finalizar o for
    }
  }

  return par;
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
    auto user = is_user_logged(id);
    if(user.first == false){//Não tá logado
      return "Usuário não logado";
    }
    
    //Já existe servidor com esse nome?
    auto server = this_server_exists(nome);
    if(server.first) {//Existe servidor
      return "Servidor com esse nome já existe";
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
    auto user = is_user_logged(id);
    if(user.first == false) {//Não tá logado
      return "Usuário não logado";
    }

    //Tem algum servidor com esse nome?
    auto server = this_server_exists(nome);
    if(server.first == false){//Servidor não existe
      return "Servidor com esse nome não existente";
    }
    
    //Você é o dono desse servidor?
    if(server.second->getId() == id){
      server.second->setDescricao(descricao);
      return "Descrição do servidor " + nome + " modificada!";
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
    auto user = is_user_logged(id);
    if(user.first == false) {//Não tá logado
      return "Usuário não logado";
    }

    //Tem algum servidor com esse nome?
    auto server = this_server_exists(nome);
    if(server.first == false){//Servidor não existe
      return "Servidor " + nome + " não encontrado";
    }

    //Você é o dono desse servidor?
    if(server.second->getId() == id){//É dono do servidor
      server.second->setCodigo(codigo);
      //Código está vazio?
      if(codigo == "") {//Código vazio
        return "Código de convite do servidor " + nome + " removido!";
      } else {//Código não vazio
        return "Código de convite do servidor " + nome + " modificado!";
      }
    }

  } else {
    return "Usuário não logado";
  }

  return "Você não pode alterar o código de um servidor que não foi criado por você";
}

string Sistema::list_servers(int id) {

  //Esse usuário está logado?
  auto user = is_user_logged(id);
  if(user.first) {//Está logado
    if(servidores.size() == 0) {
      return "Não existem servidores criados no momento";
    }
    string listaServers;

    for(auto it2 = servidores.begin(); it2 != servidores.end(); it2++) {
      listaServers.append(it2->getNome());
      listaServers.append("\n");
    }
    return listaServers;
  }

  return "Usuário não logado";
}

string Sistema::remove_server(int id, const string nome) {
  //Existe alguém logado?
  int x = usuariosLogados.size();

  if(x > 0) {
    //Usuário está logado?
    auto user = is_user_logged(id);
    if(user.first == false) {//Não tá logado
      return "Usuário não logado";
    }

    //Tem algum servidor com esse nome?
    auto server = this_server_exists(nome);
    if(server.first == false){//Servidor não existe
      return "Servidor " + nome + " não encontrado";
    }
    
    //Você é o dono desse servidor?
    if(server.second->getId() == id) {//É dono do servidor
      servidores.erase(server.second);
      //Desassociando users nesse servidor
      for(auto it = usuariosLogados.begin(); it != usuariosLogados.end(); it++) {
        if(it->second.first == nome) {
          it->second.first = "";
          it->second.second = "";
        }
      }
      return "Servidor " + nome + " removido";
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
  auto user = is_user_logged(id);
  if(user.first == false) {//Não tá logado
    return "Usuário não logado";
  }

  //Tem algum servidor com esse nome?
  auto server = this_server_exists(nome);
  if(server.first == false){//Servidor não existe
    return "Servidor " + nome + " não encontrado";
  }
        
  //Já está dentro do servidor?

  if(server.second->findUser(user.second->first) == false) {//Não está dentro
    //É dono do servidor?
    if(server.second->getId() == user.second->first) {//É dono
      pair<string,string> status;
      status.first = nome; //Associa a visualização do usuário aquele server
      status.second = ""; //Coloca o usuário para não ver nenhum canal
      user.second->second = status; //Atualiza as informações
      server.second->addUser(user.second->first); //Adiciona o id do usuário a lista de participantes
        return "Entrou no servidor com sucesso";
      } else {//Não é dono
        //Código de convite necessário?
        if(server.second->getCodigo() != "") {//É necessário
          //Há código de convite válido?
          if(codigo == ""){
            return "Servidor requer código de convite";
          } else if(codigo == server.second->getCodigo()) {
            pair<string,string> status;
            status.first = nome; //Associa a visualização do usuário aquele server
            status.second = ""; //Coloca o usuário para não ver nenhum canal
            user.second->second = status; //Atualiza as informações
            server.second->addUser(user.second->first); //Adiciona o id do usuário a lista de participantes
            return "Entrou no servidor com sucesso";
          }
        } else {//Não é necessário
          pair<string,string> status;
          status.first = nome; //Associa a visualização do usuário aquele server
          status.second = ""; //Coloca o usuário para não ver nenhum canal
          user.second->second = status; //Atualiza as informações
          server.second->addUser(user.second->first); //Adiciona o id do usuário a lista de participantes
          return "Entrou no servidor com sucesso";
        }
      }
    } else{//Está dentro
      //Está visualizando aquele servidor?
      pair<string,string> status;
      if(user.second->second.first != nome){//Não
        status.first = nome; //Associa a visualização do usuário aquele server
        status.second = ""; //Coloca o usuário para não ver nenhum canal
        user.second->second = status; //Atualiza as informações
      }

      return "";
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
    auto user = is_user_logged(id);
    if(user.first == false) {//Não tá logado
      return "Usuário não logado";
    }

    //Usuário pertence a algum servidor?
    bool pertence = false;
    for(auto itAux = servidores.begin(); itAux != servidores.end(); itAux++){
      if(itAux->findUser(user.second->first) == true){
        pertence = true;
      }
    }

    if(pertence == false) {//Não pertence
      return "Você não está em qualquer servidor";
    }

    //Tem algum servidor com esse nome?
    auto server = this_server_exists(nome);
    if(server.first == false){//Servidor não existe
      return "Servidor " + nome + " não encontrado";
    }

    //O usuário está logado nesse servidor?
    if(server.second->findUser(user.second->first) == false) {//Está logado
      return "Você não está logado no servidor " + nome;
    }

    //Está visualizando esse servidor?
    if(user.second->second.first == nome){
      user.second->second.first = "";
      user.second->second.second = "";
    }
    server.second->removeUser(user.second->first);
    return "Saindo do servidor " + nome;
              
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
    auto user = is_user_logged(id);
    if(user.first == false) {//Não tá logado
      return "Usuário não logado";
    }

    //Existe tal servidor?
    string nome = user.second->second.first;
    auto server = this_server_exists(nome);
    if(server.first){//Servidor existe
      return server.second->printUsers(usuarios);
    }

  } else {
    return "Usuário não logado";
  }

  return "Usuário não está visualizando nenhum servidor";
}

string Sistema::list_channels(int id) {
  //Existe alguém logado?
  int x = usuariosLogados.size();

  if(x > 0) {
    //Usuário está logado?
    auto user = is_user_logged(id);
    if(user.first == false) {//Não tá logado
      return "Usuário não logado";
    }

    //Existe tal servidor?
    string nome = user.second->second.first;
    auto server = this_server_exists(nome);
    if(server.first){//Servidor existe
      return server.second->printChannels();
    }

  } else {
    return "Usuário não logado";
  }

  return "Usuário não está visualizando nenhum servidor";
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
