#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <iostream>
#include <vector>

#include "canaltexto.h"

class Servidor{
	private:
		int usuarioDonoId;
		std::string nome;
		std::string descricao;
		std::string codigoConvite;
		std::vector<CanalTexto> canaisTexto;
		std::vector<int> participantesIDs;
	/*
		TODO implementação de métodos
	*/
};

#endif
