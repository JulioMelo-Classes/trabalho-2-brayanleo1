#ifndef CANALTEXTO_H
#define CANALTEXTO_H
#include <iostream>
#include <vector>

#include "mensagem.h"

class CanalTexto{
	private:
		std::string nome; //<! O nome do canal
		std::vector<Mensagem> mensagens; //<! Um vector com mensagens que foram enviadas neste canal
	/*
		TODO implementação de métodos
	*/
};

#endif
