#include "document.h"

void DocumentModel::addElement(DocumentElement *element) {
  elements.push_back(element);
}

std::vector<DocumentElement*> DocumentModel::getElements() {
  return elements; 
}