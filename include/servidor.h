#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <string>
#include <vector>

class Servidor{
	private:
		int usuarioDonoId;
		string nome;
		string descricao;
		string codigoConvite;
		vector<CanalTexto> canaisTexto;
		vector<int> participantesIDs;
	/*
		TODO implementação de métodos
	*/
};

#endif
