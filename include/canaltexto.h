#ifndef CANALTEXTO_H
#define CANALTEXTO_H
#include <iostream>
#include <vector>

#include "mensagem.h"

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
};

#endif
