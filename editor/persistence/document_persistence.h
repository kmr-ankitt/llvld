#pragma once
#include "../model/document.h"
#include <sqlite3.h>
#include <string>


class DocumentPersistence {
public:
  virtual ~DocumentPersistence() = default;
  virtual void save(const DocumentModel &doc) = 0;
};

class DocumentPersistenceIntoFile : public DocumentPersistence {
public:
  void save(const DocumentModel &doc) override;
};

class DocumentPersistenceIntoDatabase : public DocumentPersistence {
private:
  sqlite3 *db;

public:
  DocumentPersistenceIntoDatabase();
  ~DocumentPersistenceIntoDatabase();

  void save(const DocumentModel &doc) override;
};
