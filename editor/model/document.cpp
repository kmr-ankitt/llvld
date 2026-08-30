#include "document.h"

void DocumentModel::addElement(DocumentElement *element) {
  elements.push_back(element);
}

std::vector<DocumentElement> DocumentModel::getElements() {
  std::vector<DocumentElement> elementCopies;
  for (DocumentElement *element : elements) {
    elementCopies.push_back(*element);
  }
  return elementCopies; 
}