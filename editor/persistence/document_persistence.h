#pragma once
#include <sqlite3.h>
#include <string>

class DocumentPersistence {
public:
  DocumentPersistence();
  ~DocumentPersistence();
  virtual void save(const std::string &data);
};

class DocumentPersistenceIntoFile : public DocumentPersistence {
public:
  DocumentPersistenceIntoFile();
  ~DocumentPersistenceIntoFile();
  void save(const std::string &data) override;
};

class DocumentPersistenceIntoDatabase : public DocumentPersistence {
private:
  sqlite3 *db;

public:
  DocumentPersistenceIntoDatabase();
  ~DocumentPersistenceIntoDatabase();
  void save(const std::string &data) override;
};
