#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <iostream>
#include <vector>

#include "canaltexto.h"
#include "usuario.h"

class Servidor{
	private:
		int usuarioDonoId;
		std::string nome;
		std::string descricao;
		std::string codigoConvite;
		std::vector<CanalTexto> canaisTexto;
		std::vector<int> participantesIDs;
	public:

		//*! Construtor de servidor que cria um servidor vazio
		Servidor();

		/*! Coloca o id do usuário dono do servidor
				@param id_ Id do usuário dono do servidor a ser criado
		*/
		void setId(int id_);

		/*! Recupera o id do usuário dono do servidor
				@return Um int que representa o id do usuário dono do servidor
		*/
		int getId();

		/*! Coloca o nome do servidor
				@param nome_ nome do servidor a ser criado
		*/
		void setNome(std::string nome_);

		/*! Recupera o nome do servidor
				@return Uma string que representa o nome do servidor
		*/
		std::string getNome();

		/*! Coloca a descrição do servidor
				@param descricao_ descrição do servidor
		*/
		void setDescricao(std::string descricao_);

		/*! Recupera a descrição do servidor
				@return Uma string que representa a descrição do servidor
		*/
		std::string getDescricao();

		/*! Coloca a código do servidor
				@param codigo_ código do servidor
		*/
		void setCodigo(std::string codigo_);

		/*! Recupera o código do servidor
				@return Uma string que representa o código do servidor
		*/
		std::string getCodigo();

		/*! Adiciona usuário ao servidor
				@param id_ id do usuário a ser adicionado
		*/
		void addUser(int id_);

		/*! Busca usuário no servidor
				@param id_ id do usuário a ser procurado
				@return booleano que manda true caso o usuário está no servidor e false caso contrário
		*/
		bool findUser(int id_);

		/*! Remove usuário no servidor
				@param id_ id do usuário a ser removido
		*/
		void removeUser(int id_);

		/*! Imprime todos os usuários do servidor
			@param usuarios_ Vetor com todos os usuários existentes
			@return uma string contendo todos os usuários logados
		*/
		std::string printUsers(std::vector<Usuario> usuarios_);
};

#endif
