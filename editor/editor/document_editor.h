#pragma once

#include "../model/document.h"
#include "../persistence/document_persistence.h"

#include <memory>
#include <string>

class DocumentEditor {
private:
  std::unique_ptr<DocumentModel> doc;

  std::unique_ptr<DocumentPersistence> databaseStore;
  std::unique_ptr<DocumentPersistence> fileStore;

public:
  DocumentEditor();

  void addText(const std::string &text);
  void addImage(const std::string &imagePath);

  void saveToDatabase();
  void saveToFile();
};
