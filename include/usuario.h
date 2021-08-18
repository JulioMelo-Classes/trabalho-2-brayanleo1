#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>

/*
ok
*/
class Usuario{
	private:
		int id; //<! Um identificador único para o usuário
		std::string nome; //<! O nome cadastrado pelo usuário
		std::string email; //<! O email cadastrado pelo usuário
		std::string senha; //<! A senha cadastrada pelo usuário
	public:

		//*! Construtor de usuário que cria um usuário vazio
		Usuario();

		/*! Coloca o id do usuário
				@param id_ Id do usuário a ser criado
		*/
		void setId(int id_);

		/*! Recupera o id do usuário
				@return Um int que representa o id do usuário
		*/
		int getId();

		/*! Coloca o nome do usuário
				@param nome_ nome do usuário a ser criado
		*/
		void setNome(std::string nome_);

		/*! Recupera o nome do usuário
				@return Uma string que representa o nome do usuário
		*/
		std::string getNome();

		/*! Coloca o email do usuário
				@param email_ endereço de email do usuário a ser criado
		*/
		void setEmail(std::string email_);

		/*! Recupera o email do usuário
				@return Uma string que representa o email do usuário
		*/
		std::string getEmail();

		/*! Coloca a senha do usuário
				@param senha_ senha do usuário a ser criado
		*/
		void setSenha(std::string senha_);

		/*! Recupera a senha do usuário
				@return Uma string que representa a senha do usuário
		*/
		std::string getSenha();
};

#endif