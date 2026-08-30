#pragma once
#include "../element/document_element.h"
#include "vector"

class DocumentModel {
private:
  std::vector<DocumentElement *> elements;

public:
  DocumentModel();
  ~DocumentModel();

  void addElement(DocumentElement *element);
  std::vector<DocumentElement> getElements();
};
