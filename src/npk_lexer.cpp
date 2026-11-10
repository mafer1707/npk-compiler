#include <npk_lexer.hpp>

using namespace Designar;

Lexer make_lexer() 
{
    std::cout<<"Run make_lexer!"<<std::endl;
    Lexer lexer;
    lexer.add_token("SI", "si");
    return lexer;
}