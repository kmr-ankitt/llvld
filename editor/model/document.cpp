#include "document.h"

DocumentModel::~DocumentModel() {
    for (DocumentElement* element : elements) {
        delete element;
    }
}

void DocumentModel::addElement(DocumentElement* element) {
    elements.push_back(element);
}

const std::vector<DocumentElement*>& DocumentModel::getElements() const {
    return elements;
}