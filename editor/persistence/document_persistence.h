#pragma once
#include "../element/document_element.h"
#include <sqlite3.h>
#include <string>


class DocumentPersistence {
public:
  virtual ~DocumentPersistence() = default;
  virtual void save(DocumentElement &data) = 0;
};

class DocumentPersistenceIntoFile : public DocumentPersistence {
public:
  void save(DocumentElement &data) override;
};

class DocumentPersistenceIntoDatabase : public DocumentPersistence {
private:
  sqlite3 *db;

public:
  DocumentPersistenceIntoDatabase();
  ~DocumentPersistenceIntoDatabase();

  void save(DocumentElement &data) override;
};
