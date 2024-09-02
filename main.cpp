#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <class name> <address>" << std::endl;
    return 1;
  } else {
    std::stringstream raw;
    std::string className = argv[1];
    for (int i = 0; i < static_cast<int>(className.length()); i++) {
      char c = static_cast<unsigned char>(className[i]);
      if (i == 0)
        c = std::toupper(c);
      else
        c = std::tolower(c);
      raw << c;
    }
    className = raw.str();
    std::string address = argv[2];
    std::stringstream headerName;
    headerName << address << "/" << className << ".hpp";
    std::stringstream sourceName;
    sourceName << address << "/" << className << ".cpp";
    std::ofstream header(headerName.str().c_str());
    std::ofstream source(sourceName.str().c_str());
    std::stringstream upper;
    for (int i = 0; i < static_cast<int>(className.length()); i++) {
      char c = static_cast<unsigned char>(className[i]);
      c = std::toupper(c);
      upper << c;
    }
    std::string upperClassName = upper.str();
    header << "#ifndef " << upperClassName << "_HPP" << std::endl;
    header << "#define " << upperClassName << "_HPP" << std::endl;
    header << std::endl;
    header << "#include <iostream>" << std::endl;
    header << "#include <string>" << std::endl;
    header << "#include <sstream>" << std::endl;
    header << "#include <ostream>" << std::endl;
    header << "#include <fstream>" << std::endl;
    header << std::endl;
    header << "class " << className << " {" << std::endl;
    header << "public:" << std::endl;
    header << "  " << className << "();" << std::endl;
    header << "  ~" << className << "();" << std::endl;
    header << "  " << className << "(const " << className << " &src);"
           << std::endl;
    header << "  " << className << " &operator=(const " << className
           << " &src);" << std::endl;
    header << std::endl;
    header << "private:" << std::endl;
    header << "};" << std::endl;
    header << std::endl;
	header << "std::ostream &operator<<(std::ostream &out, const " << className << " &src);" << std::endl;
    header << std::endl;
	header << "#endif" << std::endl;
    header.close();
    source << "#include \"" << className << ".hpp\"" << std::endl;
    source << std::endl;
    source << className << "::" << className << "() {}" << std::endl;
    source << className << "::~" << className << "() {}" << std::endl;
    source << className << "::" << className << "(const " << className
           << " &src) {}" << std::endl;
    source << className << " &" << className << "::operator=(const "
           << className << " &src) {}" << std::endl;
	source << "std::ostream &operator<<(std::ostream &out, const " << className << " &src) {}" << std::endl;
    source.close();
    return 0;
  }
  return 1;
}


