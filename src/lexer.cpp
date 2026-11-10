#include <lexer.hpp>

using namespace Designar;

Lexer make_lexer(const std::string& input) 
{
    Lexer lexer;

    lexer.add_token("SI", "si");
    return lexer;
}