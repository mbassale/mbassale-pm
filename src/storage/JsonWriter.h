//
// Created by Marco Bassaletti on 07-03-21.
//

#ifndef OWNPASS_JSONWRITER_H
#define OWNPASS_JSONWRITER_H

#include <boost/json.hpp>

namespace NSPass::Storage {
	class JsonWriter {
	public:
		explicit JsonWriter(boost::json::value& root);
		std::string save();
	private:
		boost::json::value& root;
		const char* filename;
	};
}

#endif //OWNPASS_JSONWRITER_H
