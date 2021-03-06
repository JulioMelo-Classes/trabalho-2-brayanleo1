#ifndef MENSAGEM_H
#define MENSAGEM_H
#include <iostream>

class Mensagem{
	private:
		std::string dataHora; //<! Um texto representando um timestamp com a data e hora em que a mensagem foi enviada no formato <DD/MM/AAAA - HH:MM>
		int enviadaPor; //<! Id do usuário que enviou a mensagem
		std::string conteudo; //<! Conteúdo da mensagem
	public:

	//*! Construtor de Mensagem que cria um objeto do tipo Mensagem vazio
	Mensagem();

	/*! Coloca a data e hora da mensagem
			@param dataHora_ String representando a data e hora da mensagem
	*/
	void setDH(std::string dataHora_);

	/*! Coloca o id do usuário que enviou a mensagem
			@param id Int representando o id de quem enviou a mensagem
	*/
	void setEnv(int id);

	/*! Recupera o id do usuário que enviou a mensagem
			@return Int representando o id de quem enviou a mensagem
	*/
	int getEnv();

	/*! Coloca o conteúdo da mensagem
			@param conteudo_ String que possui o conteúdo da mensagem
	*/
	void setContent(std::string conteudo_);

	/*! Imprime data, hora e conteúdo da mensagem em um formato pré-definido
			@return Uma string que possui data, hora e conteúdo da mensagem
	*/
	std::string printMsg();
};

#endif