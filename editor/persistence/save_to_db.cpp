#include "document_persistence.h"
#include <stdexcept>
#include <string>

DocumentPersistenceIntoDatabase::DocumentPersistenceIntoDatabase()
    : db(nullptr) {

  if (sqlite3_open("documents.db", &db) != SQLITE_OK) {
    throw std::runtime_error("Failed to open database");
  }

  const char *sql = R"(
        CREATE TABLE IF NOT EXISTS document_elements (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            type TEXT NOT NULL,
            data TEXT NOT NULL
        );
    )";

  if (sqlite3_exec(db, sql, nullptr, nullptr, nullptr) != SQLITE_OK) {
    sqlite3_close(db);
    db = nullptr;
    throw std::runtime_error("Failed to create table");
  }
}

DocumentPersistenceIntoDatabase::~DocumentPersistenceIntoDatabase() {
  if (db) {
    sqlite3_close(db);
  }
}

void DocumentPersistenceIntoDatabase::save(const DocumentModel &document) {

  const char *sql = R"(
        INSERT INTO document_elements (type, data)
        VALUES (?, ?);
    )";

  for (DocumentElement *element : document.getElements()) {

    std::string type;
    std::string value;

    if (auto *text = dynamic_cast<TextElement *>(element)) {
      type = "text";
      value = text->getText();

    } else if (auto *image = dynamic_cast<ImageElement *>(element)) {
      type = "image";
      value = image->getImagePath();

    } else {
      throw std::runtime_error("Unknown DocumentElement type");
    }

    sqlite3_stmt *stmt = nullptr;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
      throw std::runtime_error("Failed to prepare SQL statement");
    }

    sqlite3_bind_text(stmt, 1, type.c_str(), -1, SQLITE_TRANSIENT);

    sqlite3_bind_text(stmt, 2, value.c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
      sqlite3_finalize(stmt);
      throw std::runtime_error("Failed to save document element");
    }

    sqlite3_finalize(stmt);
  }
}
