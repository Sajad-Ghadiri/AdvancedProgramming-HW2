#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include "crypto.h"

class Server;

class Client
{
public:
	Client(std::string _id, const Server &server);
	std::string get_id() const;
	std::string get_publickey() const {return public_key;}
	double get_wallet() const;
	std::string sign(std::string txt) const;
	bool transfer_money(std::string receiver, double value) const;

	size_t generate_nonce();


private:
	Server const *const server;
	const std::string id;
	std::string public_key;
	std::string private_key;

};

#endif // CLIENT_H