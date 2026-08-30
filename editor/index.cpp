#include "editor/document_editor.h"

int main() {

  DocumentEditor editor;

  editor.addText("Hello from llvld!");
  editor.addImage("./assets/hank.jpg");

  editor.saveToFile();
  editor.saveToDatabase();

  return 0;
}
