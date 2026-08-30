#pragma once
#include "../element/document_element.h"
#include "vector"

class DocumentModel {
private:
    std::vector<DocumentElement*> elements;

public:
    DocumentModel() = default;
    ~DocumentModel();

    void addElement(DocumentElement* element);
    const std::vector<DocumentElement*> &getElements() const;
};
