//
// Created by Marco Bassaletti on 30-03-21.
//

#ifndef OWNPASS_LISTCOMMAND_H
#define OWNPASS_LISTCOMMAND_H

#include "../OwnPass.h"
#include "Command.h"

namespace OwnPass::Commands {
	class ListCommand : public Command {
	public:
		enum class Format {
			STDOUT = 1,
			CSV
		};
		explicit ListCommand(OwnPass::Application& app, Format format)
				:Command{ app }, format{ format } { };
	protected:
		Format format;
	};
}

#endif //OWNPASS_LISTCOMMAND_H
