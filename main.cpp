#include <iostream>

#include "antlr4-runtime.h"
#include "DifferentialLexer.h"
#include "DifferentialParser.h"
#include "DifferentialBaseListener.h"

using namespace antlr4;

class TreeShapeListener : public DifferentialBaseListener {
public:
  void enterKey(ParserRuleContext *ctx) {
    
  }
};


int main(int argc, const char* argv[]) {
  std::ifstream stream;
  stream.open(argv[1]);
  ANTLRInputStream input(stream);
  DifferentialLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  DifferentialParser parser(&tokens);

  tree::ParseTree *tree = parser.prog();
  TreeShapeListener listener;
  tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

  return 0;
}