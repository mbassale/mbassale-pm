//
// Created by Marco Bassaletti on 18-03-21.
//

#include <string>
#include "../../commands/HelpCommand.h"
#include "../../commands/CreatePasswordCommand.h"
#include "../InvalidCommandSyntaxException.h"
#include "Parser.h"
#include "CreatePasswordCommandParser.h"

namespace NSPass::CLI::Parsers {
	using namespace std;
	using NSPass::Commands::CommandPtr;
	using NSPass::Commands::HelpCommand;
	using NSPass::Commands::CreatePasswordCommand;
	using NSPass::CLI::InvalidCommandSyntaxException;
	namespace po = boost::program_options;

	CommandPtr NSPass::CLI::Parsers::CreatePasswordCommandParser::operator()()
	{
		po::options_description create_desc{ "Create command options" };
		create_desc.add_options()
				("help,h", "This help")
				("category,c", po::value<string>()->default_value("Default"), "Password Category")
				("application,a", po::value<string>(), "Application name")
				("site,s", po::value<string>(), "Site name")
				("url", po::value<string>()->default_value(""), "Site url")
				("description", po::value<string>()->default_value(""), "Description")
				("username,u", po::value<string>(), "Username")
				("password,p", po::value<string>(), "Password");

		try {
			// Collect all the unrecognized options from the first pass. This will include the
			// (positional) command name, so we need to erase that.
			vector<string> opts = po::collect_unrecognized(parsed.options, po::include_positional);
			if (!opts.empty())
				opts.erase(opts.begin());
			// Parse again...
			po::store(po::command_line_parser(opts).options(create_desc).run(), vm);
			po::notify(vm);
		}
		catch (po::error& err) {
			throw InvalidCommandSyntaxException(format_error(err.what(), create_desc));
		}

		if (vm.empty() || vm.count("help")) {
			return CommandPtr{ new HelpCommand{ app, create_desc }};
		}

		if (vm.count("username") == 0 || vm.count("password") == 0) {
			throw InvalidCommandSyntaxException(format_error("Missing required username and password.", create_desc));
		}
		if (vm.count("application") == 0 && vm.count("site") == 0) {
			throw InvalidCommandSyntaxException(format_error("Missing application or site.", create_desc));
		}

		CreatePasswordCommand::CreateData create_data{};
		create_data.category = vm["category"].as<string>();
		create_data.application = vm.count("application") ? vm["application"].as<string>() : "";
		create_data.site = vm.count("site") ? vm["site"].as<string>() : "";
		create_data.username = vm["username"].as<string>();
		create_data.password = vm["password"].as<string>();
		create_data.url = vm["url"].as<string>();
		create_data.description = vm["description"].as<string>();

		return CommandPtr{
				new CreatePasswordCommand{ app, create_data }};
	}

}
