#include <npk_lexer.hpp>

using namespace Designar;

Lexer make_lexer() 
{
    std::cout<<"Run make_lexer!"<<std::endl;
    Lexer lexer;

    std::string num = "(0|1|2|3|4|5|6|7|8|9)";
    std::string mayus = "(A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z)";
    std::string minus = "(a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z)";

    //Tipos
    lexer.add_token("ENTERO", "entero");
    lexer.add_token("REAL", "real");
    lexer.add_token("BOOL", "booleano");
    lexer.add_token("CADENA", "cadena");
    lexer.add_token("CARACTER", "caracter");

    //Control de flujo
    lexer.add_token("SI", "si");
    lexer.add_token("HACER", "hacer");
    lexer.add_token("FIN_SI", "fin si");
    lexer.add_token("ELSE", "sino");
    lexer.add_token("ELSE_IF", "sino si");
    lexer.add_token("MIENTRAS", "mientras");
    lexer.add_token("FIN_MIENTRAS", "fin mientras");

    //Funciones
    lexer.add_token("IMPRIMIR", "imprimir");
    lexer.add_token("LEER", "leer");

    //Operadores lógicos
    lexer.add_token("LOGICO_Y", "y");
    lexer.add_token("LOGICO_O", "o");

    //Identificadores y Literales
    lexer.add_token("ID", "(" + minus + "|" + mayus + ")" + "(" + minus + "|" + mayus + "|" + num + ")*");
    //lexer.add_token("CAD", "\"[^\"]*\""); 
    //lexer.add_token("CAR", "'[^']*'");
    //lexer.add_token("NUM_ENTERO",  "-?[0-9]+");
    //lexer.add_token("NUM_REAL", "-?[0-9]+,[0-9]+"); 

    //Operadores aritméticos
    lexer.add_token("SUMA", "\\+");
    lexer.add_token("RESTA", "-");
    lexer.add_token("MUL", "\\*");
    lexer.add_token("DIV", "/");
    lexer.add_token("ASIGNAR", ":=");
    
    // Símbolos de agrupación
    lexer.add_token("PAREN_I", "\\(");
    lexer.add_token("PAREN_D", "\\)");
    
    // Espacios en Blanco
    //lexer.add_token("EB", "\\s+"); 
    return lexer;
}