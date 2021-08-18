#ifndef CANALTEXTO_H
#define CANALTEXTO_H
#include <iostream>
#include <vector>
#include <utility>
#include <iterator>

#include "mensagem.h"

/*
ok
*/
class CanalTexto{
	private:
		std::string nome; //<! O nome do canal
		std::vector<Mensagem> mensagens; //<! Um vector com mensagens que foram enviadas neste canal
	public:

		//*! Construtor de CanalTexto que cria um canal de texto vazio
		CanalTexto();

		/*! Coloca o nome do canal de texto
				@param nome_ nome do canal de texto a ser criado
		*/
		void setNome(std::string nome_);

		/*! Recupera o nome do canal de texto
				@return Uma string que representa o nome do canal de texto
		*/
		std::string getNome();

		/*! Adiciona uma mensagem ao vetor de mensagens do canal de texto
				@param id O id do usuário que enviou a mensagem
				@param conteudo O conteúdo da mensagem a ser adicionáda
		*/
		void addMsg(int id, std::string conteudo);

		/*! Retorna um pair de iterators apontando para a primeira e pós última posição do vetor de mensagens do canal de texto
				@return Um pair de iterators apontando para a primeira e pós última posição do vetor de mensagens
		*/
		std::pair<std::vector<Mensagem>::iterator, std::vector<Mensagem>::iterator> getMsgIts(); //não é uma prática comum retornar iterators!

};

#endif
