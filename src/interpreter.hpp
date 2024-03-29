#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "syntax-tree.hpp"
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

class Interpreter {
public:
    using Token = std::string;
    using Line = std::vector<Token>;

    struct FunctionData {
        SyntaxTreeNode* body;
        std::vector<Token> parameters;
        int index;
    };

    using FunctionDataMap = std::map<Token, FunctionData>;
private:
    std::string input_string;
    Variables variables;
    std::vector<Line> lines;
    int total_lines;

    int total_number_of_functions = 0;


    FunctionDataMap function_map;

    enum StatementNodeType {
        ASSIGNMENT,
        RETURN,
        IF_ELSE,
        LONE_FUNCTION_CALL,
        FUNCTION_DEFINITION,
        PRINT,
        WHILE
    };

    enum AssignmentValueType {
        OPERAND,
        BINARY_OPERATION,
        FUNCTION_CALL
    };

    friend std::ostream& operator<<(std::ostream& o, Line& line);

    struct FunctionSignatureDetails {
        std::vector<Token> inputs;
        Token name;
    };

    SyntaxTreeNode* parse_while_node(int& start_line);
    int get_closing_parenthesis_index(Line& line);
    SyntaxTreeNode* parse_assignment_value_node(int start_line, int start_index, int end_index);
    SyntaxTreeNode* parse_return_node(int& start_line);
    SyntaxTreeNode* parse_lone_function_call_node(int& start_line);
    FunctionSignatureDetails get_function_signature_details(Line& line, bool is_definition);
    bool token_is_function_name(Token& token);
    SyntaxTreeNode* parse_function_call_node(int& line_number);
    AssignmentValueType get_assignment_value_type(Line& line, int start_index, int end_index);
    void preprocess_input_string(std::string& input_string);
    void parse_input_into_tokens();
    bool token_is_variable_name(const Token& token);
    int get_literal_value_from_token(const Token& token);
    BinaryOperation binary_operation_token_to_enum(const Token& token);
    bool line_is_lone_function_call(Line& line);
    StatementNodeType get_next_statement_node_type(int& start_line);
    SyntaxTreeNode* parse_operand_token(const Token& token);
    SyntaxTreeNode* parse_binary_operation_node(const Token& left, const Token& op, const Token& right);
    SyntaxTreeNode* parse_assignment_node(int& start_line);
    int get_closing_brace_line(int opening_brace_line);
    SyntaxTreeNode* parse_braces_block(int& start_line);
    SyntaxTreeNode* parse_if_else_node(int& start_line);
    SyntaxTreeNode* parse_print_node(int& start_line);
    SyntaxTreeNode* parse_single_statement_node(int& start_line);
    SyntaxTreeNode* parse_function_definition(int& start_line);
    SyntaxTreeNode* parse_block(int& start_line, int& end_line);
public:
    Interpreter(std::string input_string) : input_string(input_string), variables(Variables()) {}
    SyntaxTreeNode* generate_syntax_tree();
    FunctionDataMap get_function_map() { return function_map; }
};

std::ostream& operator<<(std::ostream& o, Interpreter::Line& line);

#endif