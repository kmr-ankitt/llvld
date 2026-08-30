#include "document_editor.h"

DocumentEditor::DocumentEditor()
    : doc(std::make_unique<DocumentModel>()),
      databaseStore(std::make_unique<DocumentPersistenceIntoDatabase>()),
      fileStore(std::make_unique<DocumentPersistenceIntoFile>()) {}

void DocumentEditor::addText(const std::string &text) {
  doc->addElement(new TextElement(text));
}

void DocumentEditor::addImage(const std::string &imagePath) {
  doc->addElement(new ImageElement(imagePath));
}

void DocumentEditor::saveToDatabase() { databaseStore->save(*doc); }

void DocumentEditor::saveToFile() { fileStore->save(*doc); }
