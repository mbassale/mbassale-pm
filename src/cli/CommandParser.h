//
// Created by Marco Bassaletti on 18-03-21.
//

#ifndef OWNPASS_COMMANDPARSER_H
#define OWNPASS_COMMANDPARSER_H

#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <boost/program_options.hpp>
#include "../commands/Command.h"

namespace OwnPass::CLI {

	typedef std::function<Commands::CommandPtr()> CommandCreatorCallback;

	struct CommandTable {
		std::string name;
		CommandCreatorCallback command_creator;
		CommandTable(std::string_view name, CommandCreatorCallback command_creator)
				:name{ name }, command_creator{ std::move(command_creator) } { }
	};

	class CommandParser {
	public:
		CommandParser(OwnPass::Application& app, int argc, char** argv);

		[[nodiscard]] const std::vector<Commands::CommandPtr>& get_commands() const { return commands; }

	private:
		static constexpr auto ProgramCaption = R"(OwnPass v0.1 - © 2021, Marco Bassaletti <bassaletti@gmail.com>.
Simple commands-line password management program.
Allowed Options)";
		OwnPass::Application& app;
		int argc;
		char** argv;
		boost::program_options::options_description opt_descriptions{ ProgramCaption };
		boost::program_options::positional_options_description positional_opt_descriptions;
		boost::program_options::variables_map vm;
		std::vector<Commands::CommandPtr> commands;

		void create_options();
		void parse_options();
		void create_commands();
	};
}

#endif //OWNPASS_COMMANDPARSER_H
