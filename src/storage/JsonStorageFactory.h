//
// Created by Marco Bassaletti on 25-03-21.
//

#ifndef OWNPASS_JSONSTORAGEFACTORY_H
#define OWNPASS_JSONSTORAGEFACTORY_H

#include "StorageFactory.h"

namespace OwnPass::Storage {
	class JsonStorageFactory : public StorageFactory {
	public:
		JsonStorageFactory() = default;
		~JsonStorageFactory() override = default;

		std::unique_ptr<Storage> make() override;
	};
}

#endif //OWNPASS_JSONSTORAGEFACTORY_H
