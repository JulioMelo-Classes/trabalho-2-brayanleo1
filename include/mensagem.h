#ifndef MENSAGEM_H
#define MENSAGEM_H
#include <iostream>

class Mensagem{
	private:
		std::string dataHora; //<! Um texto representando um timestamp com a data e hora em que a mensagem foi enviada no formato <DD/MM/AAAA - HH:MM>
		int enviadaPor; //<! Id do usuário que enviou a mensagem
		std::string conteudo; //<! Conteúdo da mensagem
	/*
		TODO implementação de métodos
	*/
};

#endif