//
// Created by Marco Bassaletti on 12-03-21.
//

#include "Vault.h"

namespace NSPass {

	Vault& Vault::set_master_password(std::string_view new_master_password)
	{
		master_password = new_master_password;
		return *this;
	}

	Vault& Vault::set_storage_location(std::string_view new_storage_location)
	{
		storage_location = new_storage_location;
		return *this;
	}

	BaseStorage& Vault::get_storage()
	{
		if (storage) return *storage;
		if (master_password.empty())
			throw ApplicationException("Trying to open storage without master password");
		if (storage_location.empty())
			throw ApplicationException("Trying to open storage without storage location");
		storage = storage_factory.make(master_password, storage_location);
		return *storage;
	}

	void Vault::open()
	{
		if (!storage) get_storage();
	}

	void Vault::save()
	{
		if (storage) storage->flush();
		else throw ApplicationException("Trying to save without storage");
	}

	void Vault::close()
	{
		if (storage) storage.reset();
		else throw ApplicationException("Trying to close without storage");
	}
}
