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
	public:
		Servidor();

		void setId(int id_);
		int getId();

		void setNome(std::string nome_);
		std::string getNome();

		void setDescricao(std::string descricao_);
		std::string getDescricao();

		void setCodigo(std::string codigo_);
		std::string getCodigo();
};

#endif
