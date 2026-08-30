#include "document_editor.h"

DocumentEditor::DocumentEditor()
    : doc(std::make_unique<DocumentModel>()),
      store(std::make_unique<DocumentPersistenceIntoDatabase>()) {}

void DocumentEditor::addText(const std::string &text) {
  doc->addElement(new TextElement(text));
}

void DocumentEditor::addImage(const std::string &imagePath) {
  doc->addElement(new ImageElement(imagePath));
}

void DocumentEditor::saveDocument() { store->save(*doc); }
